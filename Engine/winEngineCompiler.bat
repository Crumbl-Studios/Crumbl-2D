@ECHO OFF
:choice
echo Crumbl Engine Builder (windows)
echo Select an option:
echo 1.) Build engine
echo 2.) Build engine and run Python test script
echo 3.) Build C++ test script and run
set /p c=Please type the option number and press Enter 

if /i "%c%" EQU "1" goto :buildCPP
if /i "%c%" EQU "2" goto :runPython
if /i "%c%" EQU "3" goto :runCPP
goto :choice

:buildCPP
%@try%
    set Path=C:\MinGW\bin;%PATH%
    echo GCC added to PATH
    cd ./Engine
%@EndTry%
:@Catch
    echo Already in directory, Compiling
:@EndCatch
gcc -o %CD%/build/sdlWrapper.dll %CD%/sdlWrapper.cpp -I%CD%/SDL2 -shared -W -g -fPIC -Wall -Wpedantic
echo Engine built
exit
:runPython
%@try%
    set Path=C:\MinGW\bin;%PATH%
    echo GCC added to PATH
    cd ./Engine
%@EndTry%
:@Catch
    echo Already in directory, Compiling
:@EndCatch
gcc -o %CD%/build/sdlWrapper.dll %CD%/sdlWrapper.cpp -I%CD%/SDL2 -shared -W -g -fPIC -Wall -Wpedantic
echo Engine built
python3 %CD%/engineTester.py
exit
:runCPP
%@try%
    set Path=C:\MinGW\bin;%PATH%
    echo GCC added to PATH
    cd ./Engine
%@EndTry%
:@Catch
    echo Already in directory, Compiling
:@EndCatch
gcc -o %CD%/build/sdlTest.exe %CD%/cppTester.cpp -I%CD%/SDL2 -shared -W -g -fPIC -Wall -Wpedantic
echo Engine built
exit