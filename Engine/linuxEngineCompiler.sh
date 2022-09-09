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
            echo -e "\033[32mMoved to software directory\033[0m"
        }||{
            echo -e "\033[32mAlready in directory\033[0m"
        }
        g++ -o build/sdlWrapper.so sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo -e "\033[32mEngine built\a";;
    [2]* )
        {
            cd ./Engine/
            echo -e "\033[32mMoved to software directory\033[0m"
        }||{
            echo -e "\033[32mAlready in directory\033[0m"
        }
        g++ -o build/sdlWrapper.so sdlWrapper.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo -e " \033[32mEngine built, running test script \a\033[0m"
        python3 engineTester.py;;
    [3]* )
        {
            cd ./Engine/
            echo -e "\033[32mMoved to software directory\033[0m"
        }||{
            echo -e "\033[32mAlready in directory\033[0m"
        }
        g++ -o build/sdlTest cppTester.cpp -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -shared -W -g -fPIC -Wall -Wpedantic
        echo -e "\033[32mEngine built, running test script \a\033[0m"
        ./build/sdlTest;;
    [4]* )
        {
            echo -e "\033[31mCompile aborted\033[0m"
        }
esac