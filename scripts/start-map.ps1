[CmdletBinding()]
param([switch]$NoBrowser)
$ErrorActionPreference = 'Stop'
$labRoot = Split-Path -Parent $PSScriptRoot
$projectRoot = Join-Path $labRoot 'llama.cpp'
$mapRoot = Join-Path $labRoot 'map-tools'
$viewerPath = Join-Path $mapRoot 'viewer\bin\viewer.mjs'
$statePath = Join-Path $mapRoot 'dashboard-state.json'
$stdoutPath = Join-Path $mapRoot 'dashboard.stdout.log'
$stderrPath = Join-Path $mapRoot 'dashboard.stderr.log'
$expectedCommit = 'e6ab7c1a41054a888ada952eab4c886444c2f5ad'

function Test-DashboardState($state) {
    try {
        if (-not $state -or -not $state.url -or -not $state.processId) { return $false }
        $uri = [Uri]$state.url
        if ($uri.Scheme -ne 'http' -or $uri.Host -ne '127.0.0.1' -or $uri.Query -notmatch '^\?token=[a-f0-9]+$') { return $false }
        $serverProcess = Get-CimInstance Win32_Process -Filter ('ProcessId = ' + [int]$state.processId) -ErrorAction Stop
        if (-not $serverProcess.CommandLine -or -not $serverProcess.CommandLine.Contains($viewerPath) -or -not $serverProcess.CommandLine.Contains($projectRoot)) { return $false }
        $probeUrl = 'http://127.0.0.1:' + $uri.Port + '/knowledge-graph.json' + $uri.Query
        $graph = Invoke-RestMethod -Uri $probeUrl -TimeoutSec 2
        return ($graph.project.gitCommitHash -eq $expectedCommit -and $graph.nodes.Count -gt 0)
    } catch { return $false }
}

if (-not (Test-Path -LiteralPath (Join-Path $projectRoot '.ua\knowledge-graph.json'))) { throw 'The code map data is missing from llama.cpp\.ua.' }
if (-not (Test-Path -LiteralPath $viewerPath)) { throw 'The local Understand-Anything viewer is missing from map-tools\viewer.' }
$mutex = New-Object System.Threading.Mutex($false, 'Local\LlamaVulkanLabUnderstandAnything')
$locked = $false
try {
    $locked = $mutex.WaitOne(30000)
    if (-not $locked) { throw 'Another map launcher is still starting. Please try again shortly.' }
    $state = $null
    if (Test-Path -LiteralPath $statePath) {
        try { $state = Get-Content -LiteralPath $statePath -Raw | ConvertFrom-Json } catch { $state = $null }
    }
    if (-not (Test-DashboardState $state)) {
        $nodePath = Join-Path $mapRoot 'runtime\node.exe'
        if (-not (Test-Path -LiteralPath $nodePath)) { $nodePath = (Get-Command node.exe -ErrorAction Stop).Source }
        $process = Start-Process -FilePath $nodePath -ArgumentList @(('"'+$viewerPath+'"'), ('"'+$projectRoot+'"'), '--port', '0', '--no-open') -WorkingDirectory $mapRoot -WindowStyle Hidden -RedirectStandardOutput $stdoutPath -RedirectStandardError $stderrPath -PassThru
        $dashboardUrl = $null
        for ($attempt = 0; $attempt -lt 100; $attempt++) {
            Start-Sleep -Milliseconds 200
            $process.Refresh()
            if ($process.HasExited) {
                $failureText = if (Test-Path -LiteralPath $stderrPath) { Get-Content -LiteralPath $stderrPath -Raw } else { '' }
                throw ('Understand-Anything exited during startup. ' + $failureText)
            }
            if (Test-Path -LiteralPath $stdoutPath) {
                $logText = Get-Content -LiteralPath $stdoutPath -Raw
                if ($logText -match 'http://127\.0\.0\.1:\d+/\?token=[a-f0-9]+') { $dashboardUrl = $Matches[0]; break }
            }
        }
        if (-not $dashboardUrl) { throw 'The viewer did not report its URL. See map-tools\dashboard.stderr.log.' }
        $state = [pscustomobject]@{url=$dashboardUrl;processId=$process.Id;projectRoot=$projectRoot;viewerVersion='2.9.8';startedAt=[DateTime]::UtcNow.ToString('o')}
        if (-not (Test-DashboardState $state)) { throw 'The viewer started but did not return the expected code map.' }
        $state | ConvertTo-Json | Set-Content -LiteralPath $statePath -Encoding UTF8
    }
    Write-Output ('Understand-Anything: ' + $state.url)
    Write-Output ('Source folder: ' + $projectRoot)
    Write-Output 'Scope: 12 selected source files, 42 nodes, 67 relationships. This is not a full-repository analysis.'
    if (-not $NoBrowser) { Start-Process $state.url }
} finally {
    if ($locked) { $mutex.ReleaseMutex() }
    $mutex.Dispose()
}
