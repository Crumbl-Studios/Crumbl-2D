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
    SDL_Surface *generateText(const char *text,TTF_Font *font,Uint8 r = 255,Uint8 g = 255,
                            Uint8 b = 255,Uint8 a = 255){
        SDL_Color color = {r,g,b,a};
        SDL_Surface *surfaceObject = TTF_RenderText_Solid(font,text,color);
        return surfaceObject;
    }
    // BMP image support
    bool imageLocationExists( const std::string &imageLocation ){
        return access( imageLocation.c_str(), 0 ) == 0;
    }
    SDL_Surface *loadImage(const char *imageLocation){
        SDL_Surface *imageSurface;
        bool imageLocationExists = imageLocationExists;
        if(imageLocationExists){
            SDL_Surface *imageSurface = SDL_LoadBMP(imageLocation);
        }
        else{
            printf("Warning: Image ");
            printf(imageLocation);
            printf(" has not been found\n");
            SDL_Surface *imageSurface = SDL_LoadBMP("stockAssets/missingasset.png");
        }
        return imageSurface;
    }
}