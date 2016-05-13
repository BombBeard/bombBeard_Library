@ECHO off
#
D:
cd %1
@ECHO on
gcc %2.c -o executables\%2.exe
@ECHO.
@ECHO off
executables\%2.exe
ECHO.
PAUSE @ECHO on