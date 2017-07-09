:: Place this script to any writable directory
:: on the machine and run it as administrator
:: recorded binary file qxldod.etl will be created in the same directory
:: 
:: parameter "4" in 'logman update' sets logging level to INFO
:: change it to "5" for VERBOSE
:: 

@echo off

net session >nul 2>&1
if %errorlevel% equ 0 goto :admin_ok
echo This script shall run with administrator rights
pause
goto :eof


:admin_ok
pushd "%~dp0"
logman stop qxldod -ets >nul 2>&1
logman delete qxldod -ets >nul 2>&1
logman create trace qxldod -o qxldod.etl -ow -ets 
logman update qxldod -p {756ABE50-54E3-4A05-B5BB-F0112C75B18A} 0x7fffffff 4 -ets
echo Recording started.
echo Reproduce the problem, then press ENTER
pause > nul
logman stop qxldod -ets
dir qxldod.etl
echo Please collect qxldod.etl file now
pause
popd
