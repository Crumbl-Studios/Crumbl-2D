#include <SDL/SDL.h>

// Array of events
const char *eventArray[100];
int eventI;

void pollInputs(SDL_Event *event){
    while(SDL_PollEvent(event)){
        if(event->type = SDL_QUIT){
            eventI += 1;
            eventArray[eventI] = "quit";
        }
        if(event->type = SDL_KEYDOWN){
            eventI += 1;
            eventArray[eventI] = "Key_Down";
        }
        if(event->type = SDL_KEYUP){
            eventI += 1;
            eventArray[eventI] = "Key_Up";
        }
    }
    eventI = 0;
}