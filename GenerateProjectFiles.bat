@echo off

if not exist "%~dp0Engine\Build\GenerateProjectFiles.bat" (
    goto Error_NoBatchFile
)

cd Engine\Build
call GenerateProjectFiles.bat
echo.
pause
exit

:Error_NoBatchFile
echo Error: The 'GenerateProjectFiles.bat' file in 'Engine/Build' could not be found.
echo.
pause
exit