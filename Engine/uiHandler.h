#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>

// Text generator
SDL_Surface *generateText(const char *text,int x,int y,int w,int size = 12,int r = 255,int g = 255,
                          int b = 255,const char *fontFile = "stockAssets/SourceSansPro-Regular.ttf"){
    TTF_Font *usrFont= TTF_OpenFont(fontFile, size);
    SDL_Surface *surfaceObject = TTF_RenderText_Solid(usrFont,text,{r,g,b});
}