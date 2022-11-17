cmake_minimum_required(VERSION 3.21)
project(Crumbl2d)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(CB_PLATFORM_WINDOWS)
add_compile_definitions(CB_BUILD_DLL)

include_directories(src/Crumbl2d/)
include_directories(vendor/box2D/include/box2d)
include_directories(vendor/ENTT)
include_directories(vendor/SDL2/include/SDL2)

link_directories(../Engine/vendor/SDL2/lib)
link_directories(../Engine/vendor/box2D/lib)

add_library(Crumbl2d SHARED
        src/Crumbl2d/Core/application.cpp
        src/Crumbl2d/Core/application.h
        src/Crumbl2d/Core/core.h
        src/Crumbl2d/Core/entryPoint.h

        vendor/ENTT/entt.hpp)

target_link_libraries(Crumbl2d SDL2)
target_link_libraries(Crumbl2d SDL2_image)
target_link_libraries(Crumbl2d SDL2_ttf)
target_link_libraries(Crumbl2d SDL2_mixer)

target_link_libraries(Crumbl2d box2d)