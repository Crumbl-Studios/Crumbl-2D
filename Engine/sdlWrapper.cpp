// SDL imports
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// Wrapper module imports
#include "eventHandler.h"
#include "uiHandler.h"
int main(int argc, char** args,const char *title,int xres, int yres,bool fullscreen = false,bool fullscreenDesk = false,int gDriver = 0, // Init engine
        bool invisible = false, bool noDecoration = false, bool canResize = false,bool minimized = false,
        bool maximized = false, bool foreignWindow = false, bool highDPI = true,bool skipTaskbar = false,
        bool utilWin = false, bool tooltipWin = false, bool popup = false){
    SDL_Window *window;
    SDL_Surface *winSurface;
    Uint32 flags = 0;
    // Attempt init
    if (SDL_Init(SDL_INIT_VIDEO)) // Redundancy for initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return -1;
    }
    // Setup SDL object.flags
    if (fullscreen == true)
    { // Fullscreen object.flags
        flags += SDL_WINDOW_FULLSCREEN;
    }
    if (fullscreenDesk == true){
        flags += SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (gDriver == 1)
    { //Choose gpu driver 0 = default, 1 = openGL 2 = Vulkan
        flags += SDL_WINDOW_OPENGL;
    }
    if (gDriver == 2)
    {
        flags += SDL_WINDOW_VULKAN;
    }
    if (invisible == true)
    {
        flags += SDL_WINDOW_HIDDEN;
    }
    if (noDecoration == true)
    {
        flags += SDL_WINDOW_BORDERLESS;
    }
    if (canResize == true)
    {
        flags += SDL_WINDOW_RESIZABLE;
    }
    if (minimized == true)
    {
        flags += SDL_WINDOW_MINIMIZED;
    }
    if (maximized == true)
    {
        flags += SDL_WINDOW_MAXIMIZED;
    }
    if (foreignWindow == true)
    {
        flags += SDL_WINDOW_FOREIGN;
    }
    if (highDPI == true)
    {
        flags += SDL_WINDOW_ALLOW_HIGHDPI;
    }
    if (skipTaskbar == true)
    {
        flags += SDL_WINDOW_SKIP_TASKBAR;
    }
    if (utilWin == true)
    {
        flags += SDL_WINDOW_UTILITY;
    }
    if (tooltipWin == true)
    {
        flags += SDL_WINDOW_TOOLTIP;
    }
    if (popup = true)
    {
        flags += SDL_WINDOW_POPUP_MENU;
    }
    // Generate window
    window = SDL_CreateWindow(title,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    xres, yres,0); //,object.flags used to be here, disabled for testing
    // Check for new window
    if(!window){
        printf("Critical: SDL failed to init");
        return -1;
    }

    // Create surface
    winSurface = SDL_GetWindowSurface(window);
    // Check surface
    if(!winSurface){
        printf("Critical: No surface generated (Could it be uncommented in source code?)");
        return -1;
    }
    printf("Window generated, filling surface");
    // Fill window with default
    SDL_FillRect(winSurface,NULL,SDL_MapRGB(winSurface->format, 0, 0, 0 ) );
    SDL_UpdateWindowSurface(window);
}

extern "C"{
    void getPos(SDL_Window *window){
        return SDL_GetWindowPosition(window,0,0);
    }

    void setPos(SDL_Window *window,int x,int y){
        SDL_SetWindowPosition(window,x,y);
    }

    void sdlShutdown(SDL_Window *window){
        printf("Closing Crumbl engine, tearing down SDL");
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void blitObject(SDL_Surface *object,SDL_Rect *rect,SDL_Surface* surface,SDL_Rect *endrect){
        SDL_BlitSurface(object,rect,surface,endrect);
    }
    void changeTitle(SDL_Window *window, char *title){
        SDL_SetWindowTitle(window,title);
    }
    void updateCrumblTasks(SDL_Window *window,SDL_Surface surface,bool cursor = true,bool debugWin = true){
        int pollReturn =  pollInputs();
        if(pollReturn == -1){
            printf("Shutdown called");
            sdlShutdown(window);
        }
        if(cursor){
            SDL_Cursor *cur;
            // Generate cursor image
            SDL_Surface *cursorImage = IMG_Load("/stockAssets/defaultCursor");
            cur = SDL_CreateColorCursor(cursorImage,0,0);
            SDL_SetCursor(cur);
        }   
        SDL_UpdateWindowSurface(window);
    }

    void fillRect(SDL_Surface *surface,int r,int g, int b,SDL_Rect *rect = NULL){
        SDL_FillRect(surface,rect,SDL_MapRGB( surface->format, r, g, b ));
    }

    void passText(const char *text,int x,int y,int w,int size = 12,int r = 255,int g = 255,
                    int b = 255,const char *fontFile = "stockAssets/SourceSansPro-Regular.ttf"){
        generateText(text,x,y,w,size,r,g,b,fontFile);
    }
}