#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
extern "C"{
    // Text generator (Commented out because compiler was not linking TTF module)
    SDL_Surface *generateText(const char *text,TTF_Font *font,int r = 255,int g = 255,
                            int b = 255){
        SDL_Color color = {r,g,b};
        SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
        return surfaceObject;
    }
}