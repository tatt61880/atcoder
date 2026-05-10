@echo off

for /R %%i in (*.c) do (
	echo %%i
	cl.exe /nologo %%i
	if ERRORLEVEL 1 (
		echo ERROR: %%i failed.
		pause
	)
)

for /R %%i in (*.cpp) do (
	echo %%i
	cl.exe /EHsc /nologo %%i
	if ERRORLEVEL 1 (
		echo ERROR: %%i failed.
		pause
	)
)

pause
