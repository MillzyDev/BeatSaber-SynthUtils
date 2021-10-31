$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

# Builds a .qmod file for loading with QuestPatcher
$NDKPath = Get-Content $PSScriptRoot/ndkpath.txt

$Version = "0.1.0"

$buildScript = "$NDKPath/build/ndk-build"
if (-not ($PSVersionTable.PSEdition -eq "Core")) {
    $buildScript += ".cmd"
}

$ArchiveName = "SynthUtils-$Version.qmod"
$TempArchiveName = "SynthUtils-$Version.qmod.zip"

& $buildScript NDK_PROJECT_PATH=$PSScriptRoot APP_BUILD_SCRIPT=$PSScriptRoot/Android.mk NDK_APPLICATION_MK=$PSScriptRoot/Application.mk

$stopwatch.Stop()
$timeElapsed = [math]::Round($stopwatch.Elapsed.TotalSeconds,3)
Write-Output "SO build completed in $timeElapsed seconds"
$stopwatch.Start()

Compress-Archive -Path "./libs/arm64-v8a/libSynthUtils.so", "./libs/arm64-v8a/libbeatsaber-hook_2_3_2.so", "./mod.json" -DestinationPath $TempArchiveName -Force
Move-Item $TempArchiveName $ArchiveName -Force

$stopwatch.Stop()
$timeElapsed = [math]::Round($stopwatch.Elapsed.TotalSeconds,3)
Write-Output "QMOD build completed in $timeElapsed seconds"
