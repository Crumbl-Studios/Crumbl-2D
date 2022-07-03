#!/bin/bash
echo "Crumbl Engine Builder (Mac/Unix/Linux)"
echo "Select an option:"
echo "1.) Build engine"
echo "2.) Build engine and run Python test script"
echo "3.) Build C++ test script and run"
echo "4.) Quit this compiler"
read -p "Please type the option number and press Enter " option
case $option in
    [1]* )
        {
            cd ./Engine/
        }||{
            echo "Already in directory"
        }
        gcc -o build/sdlWrapper.so sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo "Engine built";;
    [2]* )
        {
            cd ./Engine/
        }||{
            echo "Already in directory"
        }
        gcc -o build/sdlWrapper.so sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo "Engine built, running test script"
        /bin/python3 engineTester.py;;
    [3]* )
        {
            cd ./Engine/
        }||{
            echo "Already in directory"
        }
        gcc -o build/sdlTest cppTester.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo "Engine built, running test script"
        ./build/sdlTest;;
    [4]* )
        {
            echo Compile aborted
        }
esac