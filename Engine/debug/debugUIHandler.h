// Crumbl Engine Debug UI handler
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
    #include <iostream>
    #define _access    access
#endif

// Same as blitObject, but exists to avoid recursion with sdlWrapper
void blitMenuObject(SDL_Renderer *renderer,SDL_Surface *object,SDL_Rect *rect,int x, int y,
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
SDL_Surface *generateDebugText(const char *text,TTF_Font *font,Uint8 r = 255,Uint8 g = 255,
                        Uint8 b = 255,Uint8 a = 255){
    SDL_Color color = {r,g,b,a};
    SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
    return surfaceObject;
}
//Font loader
TTF_Font *loadDebugFont(const char *fontFile,int size){
    return TTF_OpenFont(fontFile, size);
}
