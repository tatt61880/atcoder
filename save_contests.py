import gzip
import json
import sys
import time
import urllib.error
import urllib.parse
import urllib.request


def save_contests(output_path: str = "contests.json") -> None:
    url = "https://kenkoooo.com/atcoder/resources/contests.json"
    print(url)

    headers = {
        "User-Agent": (
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
            "AppleWebKit/537.36 (KHTML, like Gecko) "
            "Chrome/120.0.0.0 Safari/537.36"
        ),
        "Accept": "application/json",
        "Accept-Encoding": "gzip",
    }

    request = urllib.request.Request(url, headers=headers)

    try:
        with urllib.request.urlopen(request) as response:
            body = response.read()

            if response.headers.get("Content-Encoding") == "gzip":
                body = gzip.decompress(body)

            data = json.loads(body.decode("utf-8"))

    except urllib.error.HTTPError as e:
        print(f"HTTP Error: {e.code} {e.reason}")
        print(e.read().decode("utf-8", errors="replace"))
        raise

    with open(output_path, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


save_contests()
