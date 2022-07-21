#ifdef _WIN32
    #include "SDL2/SDL.h"
#else
    #include <SDL2/SDL.h>
#endif
#include <iostream>

int mouse_x;
int mouse_y;

bool keys[322];


int pollInputs(SDL_Event events,bool verbose = false){
    for(int i = 0; i < 322; i++) { // reset keys
        keys[i] = false;
    }
    while(SDL_PollEvent(&events)){
        switch(events.type){
            case SDL_QUIT:
                if(verbose){
                    std::cout<<"\033[31mEventHandler: Shutdown called\033[0m\n";
                }
                return -1;
                break;
            case SDL_USEREVENT:
                if(verbose){
                    std::cout<<"\033[36mEventHandler: User event (likely timer)\033[0m\n";
                }
                return 1;
                break;
            case SDL_KEYDOWN:
                if(verbose){
                    std::cout<<"\033[36mEventHandler: Key pressed\033[0m\n";
                }
                keys[events.key.keysym.sym] = true;
                return 2;
                break;
            case SDL_KEYUP:
                if(verbose){
                    std::cout<<"\033[36mEventHandler: Key released\033[0m\n";
                }
                keys[events.key.keysym.sym] = false;
                return 3;
                break;
            case SDL_MOUSEMOTION:
                if(verbose){
                    std::cout<<"\033[36mEventHandler: Mouse moved\033[0m\n";
                }
                mouse_x = events.motion.x;
                mouse_y = events.motion.y;
                return 4;
                break;
        }
        if(verbose){
            std::cout<<"\033[36mEventHandler: No events\033[0m\n";
        }
        return 0; 
    }
    return 0;
}

int returnMouseX(){
    return mouse_x;
}

int returnMouseY(){
    return mouse_y;
}