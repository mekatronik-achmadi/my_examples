@echo off

%windir%\System32\WindowsPowerShell\v1.0\powershell.exe -ExecutionPolicy ByPass -NoExit -Command "& '%CD%\shell\condabin\conda-hook.ps1' ; conda activate '%CD%' "