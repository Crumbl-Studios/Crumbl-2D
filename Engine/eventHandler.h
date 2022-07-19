#ifdef _WIN32
    #include "SDL2/SDL.h"
#else
    #include <SDL2/SDL.h>
#endif
#include <iostream>

int mouse_x;
int mouse_y;

bool keys[322];


int pollInputs(SDL_Event events){
    for(int i = 0; i < 322; i++) { // reset keys
        keys[i] = false;
    }
    while(SDL_PollEvent(&events)){
        switch(events.type){
            case SDL_QUIT:
                std::cout<<"EventHandler: Shutdown called\n";
                return -1;
                break;
            case SDL_USEREVENT:
                std::cout<<"EventHandler: User event (likely timer)\n";
                return 1;
                break;
            case SDL_KEYDOWN:
                std::cout<<"EventHandler: Key pressed\n";
                keys[events.key.keysym.sym] = true;
                return 2;
                break;
            case SDL_KEYUP:
                std::cout<<"EventHandler: Key released\n";
                keys[events.key.keysym.sym] = false;
                return 3;
                break;
            case SDL_MOUSEMOTION:
                std::cout<<"EventHandler: Mouse moved\n";
                mouse_x = events.motion.x;
                mouse_y = events.motion.y;
                return 4;
                break;
        }
        std::cout<<"EventHandler: No events\n";
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