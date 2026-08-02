@echo off

echo Building...
gcc *.c -o game.exe

if %errorlevel% neq 0 (
    echo.
    echo Build failed!
    pause
    exit /b
)

echo Build successful!

start "" /max cmd /c game.exe