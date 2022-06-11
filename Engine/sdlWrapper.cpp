// SDL imports
#include <SDL2/SDL.h>
// Wrapper module imports
#include "eventHandler.h"
#include "uiHandler.h"

class engine{
    public:
        SDL_Window *window;
        SDL_Surface *winSurface;
        SDL_Event *events;
        Uint32 flags = 0;
};
int main(const char *title,int xres, int yres,bool fullscreen = false,bool fullscreenDesk = false,int gDriver = 0, // Init engine
        bool invisible = false, bool noDecoration = false, bool canResize = false,bool minimized = false,
        bool maximized = false, bool foreignWindow = false, bool highDPI = true,bool skipTaskbar = false,
        bool utilWin = false, bool tooltipWin = false, bool popup = false){
    // Create class
    engine object;
    // Setup SDL object.flags
    if (fullscreen == true)
    { // Fullscreen object.flags
        object.flags += SDL_WINDOW_FULLSCREEN;
    }
    if (fullscreenDesk == true){
        object.flags += SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (gDriver == 1)
    { //Choose gpu driver 0 = default, 1 = openGL 2 = Vulkan
        object.flags += SDL_WINDOW_OPENGL;
    }
    if (gDriver == 2)
    {
        object.flags += SDL_WINDOW_VULKAN;
    }
    if (invisible == true)
    {
        object.flags += SDL_WINDOW_HIDDEN;
    }
    if (noDecoration == true)
    {
        object.flags += SDL_WINDOW_BORDERLESS;
    }
    if (canResize == true)
    {
        object.flags += SDL_WINDOW_RESIZABLE;
    }
    if (minimized == true)
    {
        object.flags += SDL_WINDOW_MINIMIZED;
    }
    if (maximized == true)
    {
        object.flags += SDL_WINDOW_MAXIMIZED;
    }
    if (foreignWindow == true)
    {
        object.flags += SDL_WINDOW_FOREIGN;
    }
    if (highDPI == true)
    {
        object.flags += SDL_WINDOW_ALLOW_HIGHDPI;
    }
    if (skipTaskbar == true)
    {
        object.flags += SDL_WINDOW_SKIP_TASKBAR;
    }
    if (utilWin == true)
    {
        object.flags += SDL_WINDOW_UTILITY;
    }
    if (tooltipWin == true)
    {
        object.flags += SDL_WINDOW_TOOLTIP;
    }
    if (popup = true)
    {
        object.flags += SDL_WINDOW_POPUP_MENU;
    }
    // Attempt init
    if (SDL_Init(SDL_INIT_VIDEO)) // Redundancy for initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return -1;
    }
    // Generate window
    object.window = SDL_CreateWindow(title,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    xres, yres,0); //,object.flags used to be here, disabled for testing
    SDL_SetWindowTitle(object.window,title);
    // Check for new window
    if(!object.window){
        printf("Critical: SDL failed to init");
        return -1;
    }

    // Create surface
    object.winSurface = SDL_GetWindowSurface(object.window); //Commented out for error

    // Check surface
    if(!object.winSurface){
        printf("Critical: No surface generated (Could it be uncommented in source code?)");
        return -1;
    }
}

extern "C"{
    void getPos(SDL_Window *window){
        return SDL_GetWindowPosition(window,0,0);
    }

    void setPos(SDL_Window *window,int x,int y){
        SDL_SetWindowPosition(window,x,y);
    }

    void sdlShutdown(SDL_Window *window){
        SDL_DestroyWindow(window);
    }

    void blitObject(SDL_Surface *object,SDL_Rect *rect,SDL_Surface* surface,SDL_Rect *endrect){
        SDL_BlitSurface(object,rect,surface,endrect);
    }
    void changeTitle(SDL_Window *window, char *title){
        SDL_SetWindowTitle(window,title);
    }
    void updateCrumblTasks(SDL_Window *winSurface,SDL_Event *event,bool cursor = true,bool debugWin = true){
        int pollReturn =  pollInputs(event);
        if(pollReturn == -1){
            sdlShutdown(winSurface);
        }
        if(cursor){
            SDL_Cursor* cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        }
        SDL_UpdateWindowSurface(winSurface);
    }
}