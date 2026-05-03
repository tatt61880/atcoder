@echo off
set /p DAYS=‰½“ú‘O‚©‚çæ“¾‚µ‚Ü‚·‚©H –¢“ü—Í‚È‚ç10“ú‘O: 

if "%DAYS%"=="" (
  python save_submissions.py
) else (
  python save_submissions.py %DAYS%
)

pause
