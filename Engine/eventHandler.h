#include <SDL2/SDL.h>

// Array of events
const char *eventArray[100];
int eventI;

int pollInputs(SDL_Event *event){
    // while(SDL_PollEvent(event)){
        // if(event->type = SDL_QUIT){ //If quit is called return -1 to tell sdlWrapper to destroy SDL
            // eventI += 1; // Commented out due to segmentation faults, but some parts remain to allow functionality
            // eventArray[eventI] = "quit";
            // return -1;
        // }
        // if(event->type = SDL_KEYDOWN){
        //    eventI += 1;
        //    eventArray[eventI] = "Key_Down";
        // }
        // if(event->type = SDL_KEYUP){
        //    eventI += 1;
        //    eventArray[eventI] = "Key_Up";
        // }
    // }
    // eventI = 0;
    return 0;
}