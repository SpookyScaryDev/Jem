@echo off

echo Building Jem Engine project files.
echo.

@echo on
call premake5\premake5.exe vs2019
@echo off

pause