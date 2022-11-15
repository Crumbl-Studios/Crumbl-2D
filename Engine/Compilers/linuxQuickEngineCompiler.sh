#!/bin/bash
echo "Quick Engine Build script (Linux/unix)\nDesigned for CodeQL tests"
{
    cd ./Engine/
}||{
    echo "Already in directory"
}
g++ -o build/sdlTest cppTester.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -g -fPIC
echo "Engine built, running test script"
./build/sdlTest