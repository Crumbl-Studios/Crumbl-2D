# CrumblEngine
[![License](https://img.shields.io/:license-gplv2-green.svg)](https://tldrlegal.com/license/gnu-general-public-license-v2)

CrumblEngine is a 2d (and 3d in the future) game engine written in c++, with python scripting and the hopes of it being easy to pick up. It will not be written from scratch, but glued together with pre-existing libraries and in-house extensions of them. It is similar to pygame, as it is based on SDL2. It is largely incomplete.

## Features
- (FUTURE) Python based editor that will make it easier to produce games
- Speed of C++ with stock SDL
- (FUTURE) Robust in-game debugger tools
- (FUTURE) Advanced sound engine
- Python scripting system
- (FUTURE) In-editor documentation that has enough knowledge of Python to ease game making

## Contributions
We are actively looking for developers to help. This software is open source and all work is volunteer work. Any help is appreciated, but is entirely voluntary

## Installation
### NOTE FOR ALL VERSIONS: THESE INSTALL INSTRUCTIONS DO NOT WORK; WE ARE CURRENTLY REVAMPING OUR ENTIRE CODEBASE
Currently the software is incomplete, so this guide only is to get the "demo" program running, and is assuming you have already cloned this repo.

### Linux/Unix

#### Prerequisites: 
- GCC/G++ (most distros include it)
- libsdl2-2.0-0 (most distros include it)
- libsdl2-dev 
- libsdl2-image-dev
- libsdl2-ttf-dev
#### Future prerequisites:
- libsdl2-mixer-dev
- libsdl2-net-dev

#### To compile and run demo:
- Install the above packages (Debian based distros: use `sudo apt install <package>`)
- Run ``./Engine/linuxEngineCompiler.sh``
- When it gives the list of options, type `2` if you want to run the Python version or `3` for the C++ version

### Mac

#### Prerequisites:
- GCC/G++ (you should have it if you have xcode)
- libsdl2-2.0-0 (you might have it if you have worked with Unreal or Pygame)
- libsdl2-dev 
- libsdl2-image-dev
- libsdl2-ttf-dev

#### To compile and run demo:
- Get Xcode and run, close when the devkit has installed
- Unzip all of the downloaded SDL development files
- Create a folder titled SDL2 in /Engine/
- Copy all SDL2 dev files from `SDL2-2.X.YYY/include` into `SDL2` folder
- Run ``./Engine/linuxEngineCompiler.sh``
- When it gives the list of options, type `2` if you want to run the Python version or `3` for the C++ version

### Windows

#### Prerequisites:
- [MinGW with GCC/G++ binaries installed](https://sourceforge.net/projects/mingw/)
- [SDL2 development source code](https://www.libsdl.org/download-2.0.php)
- [SDL2 Image header](https://www.libsdl.org/projects/SDL_image/)
- [SDL2 TTF header](https://github.com/libsdl-org/SDL_ttf/releases)

#### Future:
- SDL2 Network headers

#### To compile and run demo
- Unzip all of the downloaded SDL development files
- Create a folder titled SDL2 in /Engine/
- Copy all SDL2 dev files from `SDL2-2.X.YYY/include` into `SDL2` folder
- Run ``./Engine/winEngineCompiler.bat``
- When it gives the list of options, type `2` if you want to run the Python version or `3` for the C++ version