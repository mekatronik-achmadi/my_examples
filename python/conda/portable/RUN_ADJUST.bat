@echo off

%CD%\python.exe %CD%\path_adjust.py qt.conf %CD%
%CD%\python.exe %CD%\path_adjust.py etc\profile.d\conda.sh %CD%
%CD%\python.exe %CD%\path_adjust.py etc\profile.d\conda.csh %CD%
%CD%\python.exe %CD%\path_adjust.py etc\fish\conf.d\conda.fish %CD%