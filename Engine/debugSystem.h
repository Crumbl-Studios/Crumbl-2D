// Crumbl Engine Debug menu
// SDL imports
#ifdef _WIN32 || _WIN64
    #include "SDL2/SDL.h"
    #include "SDL2/SDL_image.h"
    #include "SDL2/SDL_ttf.h"
    #include <io.h> 
    #define access    _access_s
#else
    #include <unistd.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #define _access    access
#endif
// Module imports
#include "uiHandler.h"

TTF_Font *debugFont = loadUIFont("build/stockAssets/SourceSansPro-Regular.ttf",12);

// Show the debug menu
void showDebug(SDL_Renderer *renderer){
    SDL_Surface *vText = generateText("Crumbl Engine v1.0a",debugFont);
    blitMenuObject(vText,NULL,0,0,500,12);
}

// Same as blitObject, but exists to avoid recursion with sdlWrapper
void blitMenuObject(SDL_Surface *object,SDL_Rect *rect,int x, int y,
                int w =  64, int h = 64){
    SDL_Rect endrect;
    endrect.x = x;
    endrect.y = y;
    endrect.w = w;
    endrect.h = h;
    SDL_Texture *objectTexture = SDL_CreateTextureFromSurface(renderer,object);
    std::cout<<SDL_GetError()<<"\n";
    SDL_RenderClear(renderer);
    int error = SDL_RenderCopy(renderer,objectTexture,rect,&endrect);
    if (error == -1){
        const char *error = SDL_GetError();
        std::cout<<"Warning: SDL blit error "<<error<<"\n";
    }
    SDL_RenderPresent(renderer);
}