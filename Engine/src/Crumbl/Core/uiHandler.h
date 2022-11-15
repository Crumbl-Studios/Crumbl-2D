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

bool ttf_Initialized = false;

extern "C"{
    // Text generator (Commented out because compiler was not linking TTF module)
    SDL_Surface *generateText(const char *text,TTF_Font *font,Uint8 r = 255,Uint8 g = 255,
                            Uint8 b = 255,Uint8 a = 255){
        if(!ttf_Initialized){
            std::cout<<"\033[32mInfo: SDL_ttf hasn't initialized yet. Initializing...\033[0m\n";
            TTF_Init();
            ttf_Initialized = true;
        }
        SDL_Color color = {r,g,b,a};
        SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
        if(!surfaceObject){
            std::cout<<"\033[33mWarning: Your text output as null. Check the following terminal out for more info\033[0m\n";
            const char *error = SDL_GetError();
            std::cout<<"\033[32mInfo: SDL text generation error: "<<error<<"\033[0m\n";
        }
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
            std::cout<<"\033[33m\nWarning: Image "<<imageLocation<<" has not been found\033[0m\n";
        }
        return imageSurface;
    }
}