import json
import sys
import time
import urllib.parse
from pathlib import Path
from typing import Any, Dict, List, Optional

from download_json import download_json, save_json

USER = "tatt61880"
OUTPUT_PATH = "tmp/submissions.json"
LATEST_AC_OUTPUT_PATH = "tmp/latest_ac_submissions.json"
WAIT_SECONDS = 1.5


def get_days_ago_from_args() -> int:
    if len(sys.argv) == 1:
        return 10

    if len(sys.argv) != 2:
        print("使い方: python download_submissions.py [days_ago]")
        sys.exit(1)

    try:
        days_ago = int(sys.argv[1])
    except ValueError:
        print("days_ago には整数を指定してください。")
        sys.exit(1)

    if days_ago < 0:
        print("days_ago には0以上の整数を指定してください。")
        sys.exit(1)

    return days_ago


def load_existing_submissions(output_path: str) -> List[Dict[str, Any]]:
    path = Path(output_path)

    if not path.exists():
        return []

    with path.open("r", encoding="utf-8") as file:
        data = json.load(file)

    if not isinstance(data, list):
        raise ValueError(f"{output_path} の形式が想定外です。list ではありません。")

    return data


def get_latest_epoch_second(submissions: List[Dict[str, Any]]) -> Optional[int]:
    epoch_seconds = [
        submission["epoch_second"]
        for submission in submissions
        if isinstance(submission.get("epoch_second"), int)
    ]

    if len(epoch_seconds) == 0:
        return None

    return max(epoch_seconds)


def make_url(from_second: int) -> str:
    base_url = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
    query = urllib.parse.urlencode({
        "user": USER,
        "from_second": from_second,
    })
    return f"{base_url}?{query}"


def download_new_submissions(from_second: int) -> List[Dict[str, Any]]:
    new_submissions: List[Dict[str, Any]] = []

    while True:
        data = download_json(make_url(from_second))

        if not isinstance(data, list):
            raise ValueError("APIの返却値が想定外です。list ではありません。")

        if len(data) == 0:
            break

        new_submissions.extend(data)

        latest_epoch_second = get_latest_epoch_second(data)
        if latest_epoch_second is None:
            raise ValueError("epoch_second を持つ提出がありません。")

        from_second = latest_epoch_second + 1
        time.sleep(WAIT_SECONDS)

    return new_submissions


def merge_submissions(
    existing_submissions: List[Dict[str, Any]],
    new_submissions: List[Dict[str, Any]],
) -> List[Dict[str, Any]]:
    submissions_by_id: Dict[int, Dict[str, Any]] = {}

    for submission in existing_submissions:
        submission_id = submission.get("id")
        if isinstance(submission_id, int):
            submissions_by_id[submission_id] = submission

    for submission in new_submissions:
        submission_id = submission.get("id")
        if isinstance(submission_id, int):
            submissions_by_id[submission_id] = submission

    return sorted(
        submissions_by_id.values(),
        key=lambda submission: (
            submission.get("epoch_second", 0),
            submission.get("id", 0),
        ),
    )


def make_latest_ac_submissions(
    submissions: List[Dict[str, Any]],
) -> List[Dict[str, Any]]:
    latest_by_cp_id: Dict[str, Dict[str, Any]] = {}

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

        cp_id = f"{contest_id}/{problem_id}"
        previous = latest_by_cp_id.get(cp_id)

        if previous is None:
            latest_by_cp_id[cp_id] = submission
            continue

        previous_epoch_second = previous.get("epoch_second", 0)
        previous_id = previous.get("id", 0)

        if (epoch_second, submission_id) > (previous_epoch_second, previous_id):
            latest_by_cp_id[cp_id] = submission

    return sorted(
        latest_by_cp_id.values(),
        key=lambda submission: (
            submission.get("contest_id", ""),
            submission.get("problem_id", ""),
            submission.get("epoch_second", 0),
            submission.get("id", 0),
        ),
    )


def save_latest_ac_submissions(submissions: List[Dict[str, Any]]) -> None:
    latest_ac_submissions = make_latest_ac_submissions(submissions)
    save_json(latest_ac_submissions, LATEST_AC_OUTPUT_PATH)
    print(f"最新AC: {len(latest_ac_submissions)}件")


def main() -> None:
    existing_submissions = load_existing_submissions(OUTPUT_PATH)
    latest_epoch_second = get_latest_epoch_second(existing_submissions)

    if latest_epoch_second is None:
        days_ago = get_days_ago_from_args()
        print(f"新規取得: {days_ago}日前から")
        from_second = int(time.time()) - days_ago * 24 * 60 * 60
    else:
        from_second = latest_epoch_second + 1

    new_submissions = download_new_submissions(from_second)

    if len(new_submissions) == 0:
        if not Path(LATEST_AC_OUTPUT_PATH).exists():
            save_latest_ac_submissions(existing_submissions)

        print("新しい提出はありません。")
        return

    merged_submissions = merge_submissions(existing_submissions, new_submissions)
    save_json(merged_submissions, OUTPUT_PATH)
    save_latest_ac_submissions(merged_submissions)

    print(f"新規取得: {len(new_submissions)}件")
    print(f"保存後合計: {len(merged_submissions)}件")


if __name__ == "__main__":
    main()
