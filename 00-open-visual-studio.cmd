@echo off
if not exist "%~dp0build\llama-vulkan-lab.sln" call "%~dp001-build.cmd"
if not exist "%~dp0build\llama-vulkan-lab.sln" exit /b 1
if exist "D:\microsoft\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" (
    start "" "D:\microsoft\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" "%~dp0build\llama-vulkan-lab.sln"
) else (
    start "" "%~dp0build\llama-vulkan-lab.sln"
)
