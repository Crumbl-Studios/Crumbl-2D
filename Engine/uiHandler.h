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
    #define _access    access
#endif

extern "C"{
    // Text generator (Commented out because compiler was not linking TTF module)
    SDL_Surface *generateText(const char *text,TTF_Font *font,Uint8 r = 255,Uint8 g = 255,
                            Uint8 b = 255,Uint8 a = 255){
        SDL_Color color = {r,g,b,a};
        SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
        return surfaceObject;
    }
    // BMP image support
    bool imageLocationExists( const std::string &imageLocation ){
        return _access( imageLocation.c_str(), 0 ) == 0;
    }
    SDL_Surface *loadImage(const char *imageLocation){
        SDL_Surface *imageSurface;
        bool imageLocationFound = imageLocationExists(imageLocation);
        if(imageLocationFound){
            SDL_Surface *imageSurface = SDL_LoadBMP(imageLocation);
        }
        else{
            SDL_Surface *imageSurface = SDL_LoadBMP("/stockAssets/missingasset.png");
            std::cout<<"Warning: Image "<<imageLocation<<" has not been found\n";
        }
        return imageSurface;
    }
}