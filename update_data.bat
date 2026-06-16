@echo off
setlocal EnableExtensions EnableDelayedExpansion
pushd "%~dp0"

if exist "tmp\submissions.json" (
    python download_submissions.py || goto :error
) else (
    set "DAYS="
    set /p "DAYS=初回取得は何日前から取得しますか？ 未入力なら10日前: "

    if "!DAYS!"=="" (
        python download_submissions.py || goto :error
    ) else (
        python download_submissions.py "!DAYS!" || goto :error
    )
)

if /i not "%~1"=="skip" (
    python update_resources_if_needed.py || goto :error
)

atcoder.exe || goto :error

pause
popd
exit /b 0

:error
echo エラーが発生しました。
pause
popd
exit /b 1
