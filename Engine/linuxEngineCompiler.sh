#!/bin/bash
echo "Crumbl engine builder (linux)"
{
    cd ./Engine/
}||{
    echo "Already in directory, compiling"
}
gcc -o build/sdlWrapper.so sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
echo "Engine built"
read -p "Would you like to run the test python program? [Yn]" yn
case $yn in
    [Yy]* )/bin/python3 engineTester.py;;
    [Nn]* )exit;; 
    * )/bin/python3 engineTester.py;;
esac