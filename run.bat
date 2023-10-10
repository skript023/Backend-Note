@echo off
setlocal

rem Save the current directory
set "current_dir=%cd%"

rem Navigate to the build/Release directory
cd /d "%~dp0build\Release"

rem Run the Note executable
Note

rem Return to the original directory
cd /d "%current_dir%"

endlocal
