@echo off

echo Building the project...

if not exist "build" (
    echo Creating build folder...
    mkdir build
) else (
    echo Build folder already exists.
)

cd build

echo Running CMake to configure the project...
cmake ..
if %ERRORLEVEL% NEQ 0 (
    echo Error: CMake configuration failed.
    pause
    exit /b 1
)

echo Building the project...
cmake --build . --config Release
if %ERRORLEVEL% NEQ 0 (
    echo Error: Build process failed.
    pause
    exit /b 1
)

if not exist "calultr.exe" (
    echo Error: calultr.exe file does not exist.
) else (
    echo Starting calultr.exe...
    start "" "calultr.exe"
)

pause
