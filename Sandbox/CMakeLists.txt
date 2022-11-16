cmake_minimum_required(VERSION 3.21)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(CB_PLATFORM_WINDOWS)

include_directories(../Engine/src)
include_directories(../Engine/src/Crumbl2d)

link_directories(../Engine/cmake-build-debug/)

add_executable(Sandbox
        src/sandbox.cpp)
target_link_libraries(Sandbox Crumbl2d)
