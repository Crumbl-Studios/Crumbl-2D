cmake_minimum_required(VERSION 3.21)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(CB_PLATFORM_WINDOWS)

include_directories(../Engine/src/)
include_directories(../Engine/src/Crumbl2d/)

include_directories(../Engine/vendor/SDL2/include/SDL2)
include_directories(../Engine/vendor/box2D/include)
include_directories(../Engine/vendor/spdlog/include/spdlog/)
include_directories(../Engine/vendor/spdlog/include/spdlog/sinks/)
include_directories(../Engine/vendor/entt/)

link_directories(../Engine/build/debug)

add_executable(Sandbox
        src/sandbox.cpp)
target_link_libraries(Sandbox Crumbl2d)