set MATLAB=G:\applicationn\MATLAB 2014\nasb

cd .

if "%1"=="" (G:\APPLIC~1\MATLAB~1\nasb\bin\win64\gmake -f simconsensusbasic.mk all) else (G:\APPLIC~1\MATLAB~1\nasb\bin\win64\gmake -f simconsensusbasic.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
