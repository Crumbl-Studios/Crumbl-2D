echo Crumbl Engine Builder (windows)
%@try%
    set Path=C:\MinGW\bin;%PATH%
    echo GCC added to PATH
    cd ./Engine
%@EndTry%
:@Catch
    echo Already in directory, Compiling
:@EndCatch
gcc -o %CD%/build/sdlWrapper.dll %CD%/sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
echo Engine built

:choice
set /p c=Would you like to run the test python program? [Yn]?

if /i "%c%" EQU "Y" goto :runPython
if /i "%c%" EQU "N" goto :doNotRunPython
if /i "%c%" EQU "" goto :runPython
goto :choice

:runPython
python3 %CD%/engineTester.py
:doNotRunPython