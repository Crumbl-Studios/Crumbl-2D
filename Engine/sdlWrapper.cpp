#include <SDL2/SDL.h>

SDL_Window* window;

class engine{
    public:
        SDL_Window* window;
        Uint32 flags = 0;
};
int main(const char* title,int xres, int yres,bool fullscreen = false,bool fullscreenDesk = false,int gDriver = 0, // Init engine
        bool invisible = false, bool noDecoration = false, bool canResize = false,bool minimized = false,
        bool maximized = false, bool foreignWindow = false, bool highDPI = true,bool skipTaskbar = false,
        bool utilWin = false, bool tooltipWin = false, bool popup = false){
    // Create class
    engine object;
    // Attempt init
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        printf("SDL Error: %s\n", SDL_GetError());
    }
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
    // Generate window
    object.window = SDL_CreateWindow(title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    xres, yres,object.flags);
}

extern "C"{
    void getPos(){
        return SDL_GetWindowPosition(window,0,0);
    }

    void setPos(int x,int y){
        SDL_SetWindowPosition(window,x,y);
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
}