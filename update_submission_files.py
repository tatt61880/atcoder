import csv
import gzip
import html
import json
import re
import sys
import time
import urllib.error
import urllib.request
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

ATCODER_BASE = "https://atcoder.jp/contests/"

TMP_DIR = Path("tmp")
HTML_DIR = Path("html")
SUBMISSIONS_DIR = Path("submissions")

SUBMISSIONS_JSON = TMP_DIR / "latest_ac_submissions.json"
CONTESTS_JSON = TMP_DIR / "contests.json"
PROBLEMS_JSON = TMP_DIR / "problems.json"
CONTEST_PROBLEM_JSON = TMP_DIR / "contest-problem.json"

EXTENSIONS_CSV = Path("extensions.csv")
KUIN_SUBMISSIONS_JSON = SUBMISSIONS_DIR / "kuinSubmissions.json"

WAIT_SECONDS = 3.0

HEADERS = {
    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/120.0.0.0 Safari/537.36"
    ),
    "Accept-Encoding": "gzip",
}

SOURCE_CODE_PATTERN = re.compile(
    r'<pre\b(?=[^>]*\bid=["\']submission-code["\'])[^>]*>([\s\S]*?)</pre>',
    re.IGNORECASE,
)


def load_json(path: Path) -> Any:
    with path.open("r", encoding="utf-8") as file:
        return json.load(file)


def save_json(data: Any, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=2)
        file.write("\n")


def load_json_list(path: Path) -> List[Dict[str, Any]]:
    data = load_json(path)

    if not isinstance(data, list):
        raise ValueError(f"{path} の形式が想定外です。list ではありません。")

    result: List[Dict[str, Any]] = []

    for item in data:
        if not isinstance(item, dict):
            raise ValueError(f"{path} の要素が想定外です。dict ではありません。")

        result.append(item)

    return result


def load_extension_pairs() -> List[Tuple[str, str]]:
    if not EXTENSIONS_CSV.exists():
        raise FileNotFoundError(f"{EXTENSIONS_CSV} がありません。")

    pairs: List[Tuple[str, str]] = []

    with EXTENSIONS_CSV.open("r", encoding="utf-8", newline="") as file:
        reader = csv.reader(file)

        for row in reader:
            if len(row) < 2:
                continue

            language = row[0].strip()
            extension = row[1].strip()

            if language != "" and extension != "":
                pairs.append((language, extension))

    return pairs


def find_extension(language: str, extension_pairs: List[Tuple[str, str]]) -> str:
    for language_part, extension in reversed(extension_pairs):
        if language_part in language:
            return extension

    return "unknown"


def make_latest_ac_submissions(
    submissions: List[Dict[str, Any]],
) -> List[Dict[str, Any]]:
    latest_by_cp: Dict[Tuple[str, str], Dict[str, Any]] = {}

    for submission in submissions:
        if submission.get("result") != "AC":
            continue

        contest_id = submission.get("contest_id")
        problem_id = submission.get("problem_id")
        epoch_second = submission.get("epoch_second")
        submission_id = submission.get("id")

        if (
            not isinstance(contest_id, str)
            or not isinstance(problem_id, str)
            or not isinstance(epoch_second, int)
            or not isinstance(submission_id, int)
        ):
            continue

        key = (contest_id, problem_id)
        previous = latest_by_cp.get(key)

        if previous is None:
            latest_by_cp[key] = submission
            continue

        previous_epoch_second = previous.get("epoch_second", 0)
        previous_id = previous.get("id", 0)

        if (epoch_second, submission_id) > (previous_epoch_second, previous_id):
            latest_by_cp[key] = submission

    return sorted(
        latest_by_cp.values(),
        key=lambda submission: (
            submission.get("contest_id", ""),
            submission.get("problem_id", ""),
            submission.get("epoch_second", 0),
            submission.get("id", 0),
        ),
    )


def make_submission_url(contest_id: str, submission_id: int) -> str:
    return f"{ATCODER_BASE}{contest_id}/submissions/{submission_id}"


def make_html_path(contest_id: str, submission_id: int) -> Path:
    return HTML_DIR / f"{contest_id}#{submission_id}.html"


def make_source_path(contest_id: str, problem_id: str, extension: str) -> Path:
    return SUBMISSIONS_DIR / contest_id / f"{problem_id}.{extension}"


def make_url_path(contest_id: str, problem_id: str) -> Path:
    return SUBMISSIONS_DIR / contest_id / f"{problem_id}.url"


def read_text_if_exists(path: Path) -> Optional[str]:
    if not path.exists():
        return None

    with path.open("r", encoding="utf-8", errors="replace") as file:
        return file.read()


def write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as file:
        file.write(text)


def is_url_file_current(path: Path, url: str) -> bool:
    text = read_text_if_exists(path)

    if text is None:
        return False

    return f"URL={url}" in text


def needs_update(source_path: Path, url_path: Path, url: str) -> bool:
    return not source_path.exists() or not is_url_file_current(url_path, url)


def fetch_html(url: str) -> str:
    print(f"Fetching data: {url}")

    request = urllib.request.Request(url, headers=HEADERS)

    try:
        with urllib.request.urlopen(request) as response:
            body = response.read()

            if response.headers.get("Content-Encoding") == "gzip":
                body = gzip.decompress(body)

            return body.decode("utf-8", errors="replace").replace("\r", "")

    except urllib.error.HTTPError as error:
        print(f"HTTP Error: {error.code} {error.reason}")
        print(error.read().decode("utf-8", errors="replace"))
        raise


def load_or_fetch_html(contest_id: str, submission_id: int, url: str) -> str:
    html_path = make_html_path(contest_id, submission_id)

    if html_path.exists():
        cached_html = read_text_if_exists(html_path)

        if cached_html is not None:
            return cached_html

    page_html = fetch_html(url)
    write_text(html_path, page_html)
    time.sleep(WAIT_SECONDS)

    return page_html


def extract_source_code(page_html: str) -> Optional[str]:
    match = SOURCE_CODE_PATTERN.search(page_html)

    if match is None:
        return None

    return html.unescape(match.group(1))


def write_submission_url_file(path: Path, url: str) -> None:
    write_text(path, f"[InternetShortcut]\nURL={url}\n")


def make_contest_title_map(contests: List[Dict[str, Any]]) -> Dict[str, str]:
    contest_title_map: Dict[str, str] = {}

    for contest in contests:
        contest_id = contest.get("id")
        title = contest.get("title")

        if isinstance(contest_id, str) and isinstance(title, str):
            contest_title_map[contest_id] = title

    return contest_title_map


def make_problem_name_map(problems: List[Dict[str, Any]]) -> Dict[str, str]:
    problem_name_map: Dict[str, str] = {}

    for problem in problems:
        problem_id = problem.get("id")
        name = problem.get("name")

        if isinstance(problem_id, str) and isinstance(name, str):
            problem_name_map[problem_id] = name

    return problem_name_map


def make_cp_problem_index_map(
    contest_problems: List[Dict[str, Any]],
) -> Dict[Tuple[str, str], str]:
    cp_problem_index_map: Dict[Tuple[str, str], str] = {}

    for item in contest_problems:
        contest_id = item.get("contest_id")
        problem_id = item.get("problem_id")
        problem_index = item.get("problem_index")

        if (
            isinstance(contest_id, str)
            and isinstance(problem_id, str)
            and isinstance(problem_index, str)
        ):
            cp_problem_index_map[(contest_id, problem_id)] = problem_index

    return cp_problem_index_map


def collect_kuin_cp_ids() -> List[Tuple[str, str]]:
    cp_ids: List[Tuple[str, str]] = []

    if not SUBMISSIONS_DIR.exists():
        return cp_ids

    for path in SUBMISSIONS_DIR.rglob("*.kn"):
        if not path.is_file():
            continue

        contest_id = path.parent.name
        problem_id = path.stem

        if contest_id == "" or problem_id == "":
            continue

        cp_ids.append((contest_id, problem_id))

    return sorted(set(cp_ids))


def update_kuin_submissions_json(
    contest_title_map: Dict[str, str],
    problem_name_map: Dict[str, str],
    cp_problem_index_map: Dict[Tuple[str, str], str],
) -> None:
    records: List[Dict[str, str]] = []
    unique_problem_ids = set()

    for contest_id, problem_id in collect_kuin_cp_ids():
        problem_index = cp_problem_index_map.get((contest_id, problem_id))
        problem_name = problem_name_map.get(problem_id)
        contest_title = contest_title_map.get(contest_id)

        if problem_index is None:
            print(f"Error: {contest_id}/{problem_id} の problem_index が見つかりません。")
            continue

        if problem_name is None:
            print(f"Error: {contest_id}/{problem_id} の問題名が見つかりません。")
            continue

        if contest_title is None:
            print(f"Error: {contest_id} のコンテスト名が見つかりません。")
            continue

        records.append(
            {
                "problem_id": problem_id,
                "contest_id": contest_id,
                "contest_title": contest_title,
                "problem_index": problem_index,
                "name": problem_name,
            }
        )
        unique_problem_ids.add(problem_id)

    save_json(records, KUIN_SUBMISSIONS_JSON)

    print(f"{KUIN_SUBMISSIONS_JSON}: {len(records)}問（問題IDの重複分を除くと{len(unique_problem_ids)}問）")


def update_submission_files(
    submissions: List[Dict[str, Any]],
    extension_pairs: List[Tuple[str, str]],
) -> None:
    latest_ac_submissions = make_latest_ac_submissions(submissions)

    targets: List[Tuple[Dict[str, Any], str, str, Path, Path]] = []

    for submission in latest_ac_submissions:
        contest_id = submission.get("contest_id")
        problem_id = submission.get("problem_id")
        submission_id = submission.get("id")
        language = submission.get("language")

        if (
            not isinstance(contest_id, str)
            or not isinstance(problem_id, str)
            or not isinstance(submission_id, int)
            or not isinstance(language, str)
        ):
            continue

        extension = find_extension(language, extension_pairs)
        url = make_submission_url(contest_id, submission_id)
        source_path = make_source_path(contest_id, problem_id, extension)
        url_path = make_url_path(contest_id, problem_id)

        if needs_update(source_path, url_path, url):
            targets.append((submission, url, extension, source_path, url_path))

    if len(targets) == 0:
        print("更新対象の提出ファイルはありません。")
        return

    print(f"{len(targets)}件の提出ファイルを取得・更新します。")

    failed_count = 0

    for index, (submission, url, extension, source_path, url_path) in enumerate(targets, 1):
        contest_id = submission["contest_id"]
        problem_id = submission["problem_id"]
        submission_id = submission["id"]

        print(f"[{index}/{len(targets)}] {contest_id}/{problem_id} {submission_id}")

        try:
            page_html = load_or_fetch_html(contest_id, submission_id, url)
            source_code = extract_source_code(page_html)

            if source_code is None:
                print(f"Error: Failed to find source code. [{contest_id}#{submission_id}]")
                failed_count += 1
                continue

            write_text(source_path, source_code)
            write_submission_url_file(url_path, url)

        except Exception as error:
            print(f"Error: {contest_id}/{problem_id} {submission_id}: {error}")
            failed_count += 1

    if failed_count > 0:
        raise RuntimeError(f"{failed_count}件の提出ファイル更新に失敗しました。")


def main() -> None:
    if not SUBMISSIONS_JSON.exists():
        print(f"{SUBMISSIONS_JSON} がありません。先に download_submissions.py を実行してください。")
        sys.exit(1)

    for path in [CONTESTS_JSON, PROBLEMS_JSON, CONTEST_PROBLEM_JSON, EXTENSIONS_CSV]:
        if not path.exists():
            print(f"{path} がありません。先に update_resources_if_needed.py 等を実行してください。")
            sys.exit(1)

    submissions = load_json_list(SUBMISSIONS_JSON)
    contests = load_json_list(CONTESTS_JSON)
    problems = load_json_list(PROBLEMS_JSON)
    contest_problems = load_json_list(CONTEST_PROBLEM_JSON)
    extension_pairs = load_extension_pairs()

    update_submission_files(submissions, extension_pairs)

    contest_title_map = make_contest_title_map(contests)
    problem_name_map = make_problem_name_map(problems)
    cp_problem_index_map = make_cp_problem_index_map(contest_problems)

    update_kuin_submissions_json(
        contest_title_map,
        problem_name_map,
        cp_problem_index_map,
    )


if __name__ == "__main__":
    main()
