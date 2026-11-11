@echo off
"%~dp0graphify-tools\venv\Scripts\python.exe" "%~dp0graphify-tools\build_map.py" > "%~dp0graphify-tools\extraction.log" 2>&1
if errorlevel 1 (
  type "%~dp0graphify-tools\extraction.log"
  pause
  exit /b 1
)
type "%~dp0graphify-tools\extraction.log"
start "" "%~dp0graphify-out\graph.html"
pause
