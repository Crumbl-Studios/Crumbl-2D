# Crumbl 2D
[![License](https://img.shields.io/:license-gplv2-green.svg)](https://tldrlegal.com/license/gnu-general-public-license-v2)

Crumbl 2D is a game engine written in c++. With planned python scripting for the hopes of it being easy to pick up. It will not be written from scratch, but glued together with pre-existing libraries, including ENTT, box2d, SDL and in-house extensions of them. It is similar to pygame, as it is based on SDL2. It is largely incomplete.

## Features
- (FUTURE) Python based editor
- (FUTURE) Python scripting system
- (FUTURE) Robust in-game debugger tools
- (FUTURE) Advanced sound engine
- (FUTURE) In-editor documentation with knowledge of Python

## Contributions
We are actively looking for developers to help. This software is open source and all work is volunteer work. Any help is appreciated, but is entirely voluntary.

## Installation: Editor
### All platforms
#### Prerequisites
- Source code
- Python interpreter

#### To run
- Go to editor directory and run `launcher.py`

## Installation: RGB Demo
### NOTE FOR ALL VERSIONS: THESE INSTALL INSTRUCTIONS DO NOT WORK; WE ARE CURRENTLY REVAMPING OUR ENTIRE CODEBASE
Currently the software is incomplete, so this guide only is to get the "demo" program running, and is assuming you have already cloned this repo.

### Linux/Unix

#### Prerequisites
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
- [Cmake](https://cmake.org/install/?adlt=strict&toWww=1&redig=8767CF0C0A844B15BCEB347DA9D474AE)


#### To compile and run (INCOMPLETE)
- Install MinGW
- Install Cmake
- Add both to PATH
- Open a CMD window in the Crumbl2D/Engine folder
