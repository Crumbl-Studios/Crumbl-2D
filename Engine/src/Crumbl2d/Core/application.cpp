#include "../cbpch.h"
#include "application.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace Crumbl2D
{
    Application::Application()
    {
        if (SDL_Init(SDL_INIT_VIDEO) > 0)
        {
            CB_CORE_WARN(SDL_GetError());
        }
        CB_CORE_INFO("Initialized SDL!");

        if (!(IMG_Init(IMG_INIT_PNG)))
        {
            CB_CORE_WARN(SDL_GetError());
        }
        CB_CORE_INFO("Initialized SDL_IMAGE!");

        TTF_Init();
        CB_CORE_INFO("Initialized SDL_TTF!");
    }

    Application::~Application()
    {
        Window.CleanUp();
        SDL_Quit();
        TTF_Quit();
    }

    void Application::Run()
    {
        while (m_running)
        {
            if (EventHandler.GetEvent(WindowClose))
            {
                m_running = false;
            }
            EventHandler.PollEvents();
            Window.OnUpdate();
        }
    }
}