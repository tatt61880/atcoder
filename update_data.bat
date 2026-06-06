@echo off
setlocal

pushd %~dp0

set /p DAYS=何日前から取得しますか？ 未入力なら10日前: 

if "%DAYS%"=="" (
  python download_submissions.py
) else (
  python download_submissions.py %DAYS%
)

if not "%1" == "skip" (
  python download_contests.py
  python download_problems.py
  python download_contest_problem.py
)

atcoder.exe

pause

popd
exit /b
