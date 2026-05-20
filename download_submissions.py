import sys
import time
import urllib.parse

from download_json import download_and_save_json


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


days_ago = get_days_ago_from_args()
from_second = int(time.time()) - days_ago * 24 * 60 * 60

base_url = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
query = urllib.parse.urlencode({
    "user": "tatt61880",
    "from_second": from_second,
})

download_and_save_json(
    f"{base_url}?{query}",
    "tmp/submissions.json",
)
