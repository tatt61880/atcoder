@echo off
set /p DAYS=‰½“ú‘O‚©‚çæ“¾‚µ‚Ü‚·‚©H –¢“ü—Í‚È‚ç10“ú‘O: 

if "%DAYS%"=="" (
  python save_submissions.py
) else (
  python save_submissions.py %DAYS%
)

if not "%1" == "skip" (
  python save_contests.py
  python save_problems.py
  python save_contest_problem.py
)

atcoder.exe

pause
