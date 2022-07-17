// Crumbl Engine Debug menu
// SDL imports
#ifdef _WIN64
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
    #include <iostream>
    #define _access    access
#endif
// Module imports
#include "debugUIHandler.h"

TTF_Font* debugFont = loadDebugFont("build/stockAssets/SourceSansPro-Regular.ttf",12);

// Show the debug menu
void showDebug(SDL_Renderer *renderer){
    SDL_Surface *vText = generateDebugText("Crumbl Engine v1.0a",debugFont);
    blitMenuObject(renderer,vText,NULL,0,0,500,12);
}