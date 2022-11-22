#include "../cbpch.h"
#include "application.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace crumbl2d
{
    application::application()
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

    application::~application()
    {
        window.CleanUp();
        SDL_Quit();
        TTF_Quit();
    }

    void application::run()
    {
        while (m_running)
        {
            if (input.getEvent(WindowClose))
            {
                m_running = false;
            }
            input.pollEvents();
            window.OnUpdate();
        }
    }
}