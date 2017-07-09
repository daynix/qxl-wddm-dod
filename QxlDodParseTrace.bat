@echo off
set tmpname=%temp%\%RANDOM%%RANDOM%%RANDOM%.tmp
if "%~1" equ "" goto :usage
if "%~2" equ "" goto :usage
"C:\Program Files (x86)\Windows Kits\10\tools\x86\traceview.exe" -process "%~1" -o %tmpname% -pdb "%~2" -nosummary
start notepad %tmpname%
goto :eof
:usage
echo %~n0 ^<ETL trace file^> ^<PDB file^>
goto :eof
