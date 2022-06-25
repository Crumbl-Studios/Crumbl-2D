#ifdef _WIN32
    #include "SDL2/SDL.h"
#else
    #include <SDL2/SDL.h>
#endif
#include <iostream>

int pollInputs(){
    SDL_Event events; // Generate events in function
    SDL_PumpEvents();
    while(SDL_PollEvent(&events)){
        switch(events.type){
            case SDL_QUIT:
                return -1;
            case SDL_USEREVENT:
                return 1;
        }
        return 0; 
    }
    return 0;
}