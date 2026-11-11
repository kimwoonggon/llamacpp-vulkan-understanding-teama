@echo off
setlocal
pushd "%~dp0"
cmake -S gguf-inspector -B gguf-inspector/build -G "Visual Studio 17 2022" -A x64
if errorlevel 1 goto :failed
start "" "gguf-inspector\build\gguf-inspector.sln"
popd
exit /b 0
:failed
pause
popd
exit /b 1
