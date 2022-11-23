#pragma once

#include "application.h"
#include "log.h"
#undef main

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

extern Crumbl2D::Application* Crumbl2D::CreateApplication();

int main(int argc, char** argv)
{
    Crumbl2D::Log::Init();
    CB_CORE_INFO("Initialized Log!");

    auto app = Crumbl2D::CreateApplication();
    app->Run();
    delete app;
}