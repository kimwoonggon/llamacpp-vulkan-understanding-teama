param([ValidateSet('Debug','RelWithDebInfo','Release')][string]$Configuration='Debug')
$ErrorActionPreference='Stop'
$lab=Split-Path $PSScriptRoot -Parent
if (-not $env:VULKAN_SDK) { $env:VULKAN_SDK='D:\VulkanSDK\1.4.363.0' }
if (-not (Test-Path "$env:VULKAN_SDK\Bin\glslc.exe")) { throw 'Vulkan SDK not found.' }
$env:PATH="$env:VULKAN_SDK\Bin;$env:PATH"
New-Item -ItemType Directory -Force "$lab\logs" | Out-Null
$ErrorActionPreference='Continue'
& cmake -S $lab -B "$lab\build" -G 'Visual Studio 17 2022' -A x64 "-DCMAKE_PREFIX_PATH=$env:VULKAN_SDK" 2>&1 | ForEach-Object { "$_" } | Tee-Object "$lab\logs\configure.log"
if ($LASTEXITCODE -ne 0) { throw 'CMake configure failed. See logs/configure.log.' }
& cmake --build "$lab\build" --config $Configuration --target llama-simple --parallel 6 2>&1 | ForEach-Object { "$_" } | Tee-Object "$lab\logs\build-$Configuration.log"
if ($LASTEXITCODE -ne 0) { throw 'Build failed. See logs.' }
$ErrorActionPreference='Stop'
Write-Host "Ready: $lab\build\bin\$Configuration\llama-simple.exe"
