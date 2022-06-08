#include <SDL2/SDL.h>

SDL_Window* window;

int main(const char* title,int xres, int yres,bool fullscreen = false,bool fullscreenDesk = false,int gDriver = 0, // Init engine
        bool invisible = false, bool noDecoration = false, bool canResize = false,bool minimized = false,
        bool maximized = false, bool foreignWindow = false, bool highDPI = true,bool skipTaskbar = false,
        bool utilWin = false, bool tooltipWin = false, bool popup = false){
    // Attempt init
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        printf("SDL Error: %s\n", SDL_GetError());
    }
    // Setup SDL flags
    Uint32 flags = 0;
    if (fullscreen == true)
    { // Fullscreen flags
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
    SDL_Window* window = SDL_CreateWindow(title,
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       xres, yres,flags);
    
}

void updateCrumblTasks(bool cursor = true,bool debugWin = true){
    if(cursor){
        SDL_Cursor* cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    }
    SDL_UpdateWindowSurface(window);
}

void sdlShutdown(){
    SDL_DestroyWindow(window);
}