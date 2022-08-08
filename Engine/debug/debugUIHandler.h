// Crumbl Engine Debug UI handler
// Somewhat unmodified version of uiHandler, built to avoid recursion with sdlWrapper
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

bool ttf_Initialized = false;

// Same as blitObject, but exists to avoid recursion with sdlWrapper
void blitMenuObject(SDL_Renderer *renderer,SDL_Surface *object,SDL_Rect *rect,int x, int y,
                int w =  64, int h = 64){
    if(object == nullptr){
        std::cout<<"\033[34mWarning: A surface has been detected as NULL, you will have errors (on debug)\033[0m"<<std::endl;
    }
    SDL_Rect endrect;
    endrect.x = x;
    endrect.y = y;
    endrect.w = w;
    endrect.h = h;
    SDL_Texture *objectTexture = SDL_CreateTextureFromSurface(renderer,object);
    std::cout<<"\033[34m"<<SDL_GetError()<<"\033[0m\n";
    SDL_RenderClear(renderer);
    int error = SDL_RenderCopy(renderer,objectTexture,rect,&endrect);
    if (error == -1){
        const char *error = SDL_GetError();
        std::cout<<"\033[35mError: SDL blit error "<<error<<" (on debug)\033[0m\n";
    }
    SDL_RenderPresent(renderer);
}
SDL_Surface *generateDebugText(const char *text,TTF_Font *font,Uint8 r = 255,Uint8 g = 255,
                        Uint8 b = 255,Uint8 a = 255){
    if(!ttf_Initialized){
        std::cout<<"\033[32mInfo: SDL_ttf hasn't initialized yet. Initializing...\033[0m\n";
        TTF_Init();
        ttf_Initialized = true;
    }
    SDL_Color color = {r,g,b,a};
    SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
    if(!surfaceObject){
        std::cout<<"\033[34mWarning: A debug text output a null surface. Check the following terminal out for more info\033[0m\n";
        const char *error = SDL_GetError();
        std::cout<<"\033[32mInfo: SDL text generation error: "<<error<<" (on debug)\033[0m\n";
    }
    return surfaceObject;
}
//Font loader
TTF_Font *loadDebugFont(const char *fontFile,int size){
    if(!ttf_Initialized){
        std::cout<<"\033[32mInfo: SDL_ttf hasn't initialized yet. Initializing...\033[0m\n";
        TTF_Init();
        ttf_Initialized = true;
    }
    std::cout<<"\033[32mDebugger fonts loading\033[0m\n";
    return TTF_OpenFont(fontFile, size);
}
