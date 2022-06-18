#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#ifdef _WIN32 
    #include <io.h> 
    #define access    _access_s
#else
    #include <unistd.h>
#endif

extern "C"{
    // Text generator (Commented out because compiler was not linking TTF module)
    SDL_Surface *generateText(const char *text,TTF_Font *font,int r = 255,int g = 255,
                            int b = 255,int a = 255){
        SDL_Color color = {r,g,b,a};
        SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
        return surfaceObject;
    }
    // BMP image support
    bool imageLocationExists( const std::string &imageLocation ){
        return access( imageLocation.c_str(), 0 ) == 0;
    }
    SDL_Surface *loadImage(const char *imageLocation){
        bool imageLocationExists = imageLocationExists;
        if(imageLocationExists){
            return SDL_LoadBMP(imageLocation);
        }
        else{
            return SDL_LoadBMP("stockAssets/missingasset.png");
        }
    }
}