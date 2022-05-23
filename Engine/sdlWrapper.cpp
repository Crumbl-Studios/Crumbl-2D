#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_timer.h>

int main(const char* title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL Error: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow(title,
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    while (1)
        ;
    // Insert engine code here
}