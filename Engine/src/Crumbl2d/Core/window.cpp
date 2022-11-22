#include "../cbpch.h"
#include "window.h"

namespace crumbl2d
{
    Window::Window(const char *p_title, int p_width, int p_height)
    {
        window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            CB_CORE_WARN(SDL_GetError());
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        CB_CORE_INFO("Created Window!");
    }

    void Window::OnUpdate()
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    void Window::CleanUp()
    {
        SDL_DestroyWindow(window);
    }

}