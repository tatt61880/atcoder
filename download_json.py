import gzip
import json
import time
import urllib.error
import urllib.request
from pathlib import Path
from typing import Any


HEADERS = {
    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/120.0.0.0 Safari/537.36"
    ),
    "Accept": "application/json",
    "Accept-Encoding": "gzip",
}


def download_json(url: str) -> Any:
    print(url)

    request = urllib.request.Request(url, headers=HEADERS)

    try:
        with urllib.request.urlopen(request) as response:
            body = response.read()

            if response.headers.get("Content-Encoding") == "gzip":
                body = gzip.decompress(body)

            return json.loads(body.decode("utf-8"))
    except urllib.error.HTTPError as error:
        print(f"HTTP Error: {error.code} {error.reason}")
        print(error.read().decode("utf-8", errors="replace"))
        raise


def save_json(data: Any, output_path: str) -> None:
    path = Path(output_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    with path.open("w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=2)


def download_and_save_json(url: str, output_path: str, wait_seconds: float = 1.0) -> None:
    data = download_json(url)
    save_json(data, output_path)

    if wait_seconds > 0:
        time.sleep(wait_seconds)
