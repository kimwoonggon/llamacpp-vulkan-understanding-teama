param([ValidateSet('Vulkan','CPU')][string]$Backend='Vulkan',[ValidateSet('Debug','RelWithDebInfo','Release')][string]$Configuration='Debug',[string]$Prompt='The capital of South Korea is',[int]$Tokens=48)
$ErrorActionPreference='Stop'
$lab=Split-Path $PSScriptRoot -Parent
$exe="$lab\build\bin\$Configuration\llama-simple.exe"
$model="$lab\models\qwen2.5-1.5b-instruct-fp16.gguf"
if (-not (Test-Path $exe)) { throw "Build first: $lab\01-build.cmd" }
if (-not (Test-Path $model)) { throw "Model missing: $model" }
$env:GGML_VK_VISIBLE_DEVICES='0'
$ngl=if ($Backend -eq 'Vulkan') {99} else {0}
$stamp=Get-Date -Format 'yyyyMMdd-HHmmss'
$log="$lab\logs\run-$Backend-$Configuration-$stamp.log"
Write-Host "Backend=$Backend, offload layers=$ngl, log=$log"
$ErrorActionPreference='Continue'
& $exe -m $model -ngl $ngl -n $Tokens $Prompt 2>&1 | ForEach-Object { "$_" } | Tee-Object $log
if ($LASTEXITCODE -ne 0) { throw "Inference failed ($LASTEXITCODE). See $log" }
$ErrorActionPreference='Stop'
