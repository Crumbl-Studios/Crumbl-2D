#include <iostream>
#include <SDL2/SDL.h>

int onEvent(SDL_Event &event){
   switch(event.type){
        case SDL_QUIT:
            return -1;
   }
   return 0; 
}

int pollInputs(){
    SDL_Event events; // Generate events in function
    SDL_PumpEvents();
    while(SDL_PollEvent(&events)){
        int quit_event = onEvent(events); // Check for quit state and make window close
        if(quit_event == -1){
            return -1;
        }
    }
}