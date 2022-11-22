#pragma once
#include <SDL.h>

namespace crumbl2d
{
    class CRUMBL_API Window
    {
    public:
        Window(const char* p_title="Crumbl2D", int p_width=1280, int p_height=720);
        void OnUpdate();
        void CleanUp();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    };

}