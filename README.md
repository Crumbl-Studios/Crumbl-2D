# CrumblEngine
[![License](https://img.shields.io/:license-gplv2-green.svg)](https://tldrlegal.com/license/gnu-general-public-license-v2)

CrumblEngine is a 2d (and 3d in the future) game engine written in c++, with python scripting and the hopes of it being easy to pick up. It will not be written from scratch, but glued together with pre-existing libraries and in-house extensions of them. It is similar to pygame, as it is based on SDL2. It is largely incomplete

## Features
- (FUTURE) Python based editor that will make it easier to produce games
- Speed of C++ with stock SDL
- (FUTURE) Robust in-game debugger tools
- (FUTURE) Advanced sound engine
- Python scripting system
- (FUTURE) In-editor documentation that has enough knowledge of Python to ease game making

## Installation

Currently the software is incomplete, so this guide only is to get the "demo" program running

### Mac/Linux/Unix

#### Prerequisites: 
- GCC/G++ (most distros include it)
- libsdl2-2.0-0
- libsdl2-dev 
- libsdl2-image-dev
- libsdl2-ttf-dev
#### Future prerequisites:
- libsdl2-mixer-dev
- libsdl2-net-dev

#### To run demo:
- Run ``./Engine/linuxEngineCompiler.sh``
- When asked to run demo file, type ``y`` and press enter