#ifdef _WIN32
    #include "SDL2/SDL.h"
#else
    #include <SDL2/SDL.h>
#endif
#include <iostream>

bool keys[322];


int pollInputs(){
    for(int i = 0; i < 322; i++) { // reset keys
        keys[i] = false;
    }
    SDL_Event events; // Generate events in function
    SDL_PumpEvents();
    while(SDL_PollEvent(&events)){
        switch(events.type){
            case SDL_QUIT:
                return -1;
                break;
            case SDL_USEREVENT:
                return 1;
                break;
            case SDL_KEYDOWN:
                keys[events.key.keysym.sym] = true;
                return 2;
                break;
            case SDL_KEYUP:
                keys[events.key.keysym.sym] = true;
                return 3;
                break;
        }
        return 0; 
    }
    return 0;
}

