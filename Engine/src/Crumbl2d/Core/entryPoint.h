#pragma once

#include "application.h"
#include "log.h"
#undef main

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

extern crumbl2d::application* crumbl2d::createApplication();

int main(int argc, char** argv)
{
    crumbl2d::log::init();
    CB_CORE_INFO("Initialized Log!");

    auto app = crumbl2d::createApplication();
    app->run();
    delete app;
}