import gzip
import json
import sys
import urllib.error
import urllib.parse
import urllib.request


def save_submissions(user: str, from_second: int, output_path: str = "data.json") -> None:
    base_url = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"

    query = urllib.parse.urlencode({
        "user": user,
        "from_second": from_second,
    })

    url = f"{base_url}?{query}"

    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                      "(KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
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


if len(sys.argv) != 2:
    print("使い方: python save_submissions.py <from_second>")
    sys.exit(1)

x = int(sys.argv[1])
save_submissions("tatt61880", x)
