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
uint8_t fpscolorR = 0;
uint8_t fpscolorG = 255;
uint8_t fpscolorB = 0;

// Show the debug menu
void showDebug(SDL_Renderer *renderer,int framerate,int framelimit,int x,int y){
    SDL_Surface *vText = generateDebugText("Crumbl Engine v1.0a, built on SDL2",debugFont);
    blitMenuObject(renderer,vText,NULL,0,0,500,12);
    // Framerate color key system
    if(framerate <= 10){
        fpscolorR = 255; += std::to_string(framerate);
        fpscolorG = 0;
        fpscolorB = 0;
    }
    if(framerate > 10 && framerate <= 25){
        fpscolorR = 255;
        fpscolorG = 255;
        fpscolorB = 0;
    }
    if(framerate > 25){
        fpscolorR = 255;
        fpscolorG = 0;
        fpscolorB = 0;
    }
    // Text concenteations: labels 
    const char *fpsConjugate = "FPS: ";
    const char *framelimitConjugate = "Framelimit: ";

    const char *mouseXConjugate = "X: ";
    const char *mouseYConjugate = "Y: ";

    fpsConjugate  += std::__int_to_char(framerate);
    framelimitConjugate +=  += std::__int_to_char(framelimit);

    mouseXConjugate += std::__int_to_char(x);
    mouseYConjugate += std::__int_to_char(y);

    SDL_Surface *fText = generateDebugText(fpsConjugate,debugFont,fpscolorR,fpscolorG,fpscolorB);
    blitMenuObject(renderer,fText,NULL,0,0,100,24);
    SDL_Surface *lText = generateDebugText(framelimitConjugate,debugFont);
    blitMenuObject(renderer,fText,NULL,0,0,100,36);
    SDL_Surface *mText = generateDebugText("Mouse:",debugFont);
    blitMenuObject(renderer,vText,NULL,0,0,100,48);
    SDL_Surface *xText = generateDebugText(mouseXConjugate,debugFont);
    blitMenuObject(renderer,vText,NULL,0,0,12,60);
    SDL_Surface *yText = generateDebugText(mouseYConjugate,debugFont);
    blitMenuObject(renderer,vText,NULL,0,0,12,72);
}