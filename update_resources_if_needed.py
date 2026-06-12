import json
import os
import subprocess
import sys

TMP_DIR = "tmp"

SUBMISSIONS_JSON = os.path.join(TMP_DIR, "submissions.json")
CONTESTS_JSON = os.path.join(TMP_DIR, "contests.json")
PROBLEMS_JSON = os.path.join(TMP_DIR, "problems.json")
CONTEST_PROBLEM_JSON = os.path.join(TMP_DIR, "contest-problem.json")


def load_json(path):
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def run_python(script_name):
    subprocess.run([sys.executable, script_name], check=True)


def needs_update():
    resource_paths = [
        CONTESTS_JSON,
        PROBLEMS_JSON,
        CONTEST_PROBLEM_JSON,
    ]

    if any(not os.path.exists(path) for path in resource_paths):
        return True

    try:
        submissions = load_json(SUBMISSIONS_JSON)
        contests = load_json(CONTESTS_JSON)
        problems = load_json(PROBLEMS_JSON)
        contest_problems = load_json(CONTEST_PROBLEM_JSON)
    except Exception:
        return True

    required_contests = set()
    required_problems = set()
    required_pairs = set()

    for submission in submissions:
        if submission.get("result") != "AC":
            continue

        contest_id = submission.get("contest_id")
        problem_id = submission.get("problem_id")

        if contest_id is None or problem_id is None:
            return True

        required_contests.add(contest_id)
        required_problems.add(problem_id)
        required_pairs.add((contest_id, problem_id))

    existing_contests = {contest["id"] for contest in contests}
    existing_problems = {problem["id"] for problem in problems}
    existing_pairs = {
        (item["contest_id"], item["problem_id"])
        for item in contest_problems
    }

    return (
        not required_contests <= existing_contests
        or not required_problems <= existing_problems
        or not required_pairs <= existing_pairs
    )


if not os.path.exists(SUBMISSIONS_JSON):
    print(f"{SUBMISSIONS_JSON} がありません。先に download_submissions.py を実行してください。")
    sys.exit(1)

if needs_update():
    print("補助JSONを更新します。")
    run_python("download_contests.py")
    run_python("download_problems.py")
    run_python("download_contest_problem.py")
else:
    print("既存の補助JSONで足りています。")
