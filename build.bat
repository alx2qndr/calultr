@echo off

if not exist "build" mkdir build
cd build

cmake .. || exit /b
cmake --build . --config Release || exit /b

if exist "calultr.exe" start "" "calultr.exe"