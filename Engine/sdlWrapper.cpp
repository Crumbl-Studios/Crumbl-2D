// SDL imports
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
// Wrapper module imports
#include "eventHandler.h"
#include "uiHandler.h"
// Variables
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *winSurface;
Uint32 flags = 0;

int main(int argc, char** args,const char *title,int xres, int yres,bool noFlags = true,bool fullscreen = false,bool fullscreenDesk = false,int gDriver = 0, // Init engine
        bool invisible = false, bool noDecoration = false, bool canResize = false,bool minimized = false,
        bool maximized = false, bool foreignWindow = false, bool highDPI = true,bool skipTaskbar = false,
        bool utilWin = false, bool tooltipWin = false, bool popup = false){
    // Attempt init
    if (SDL_Init(SDL_INIT_VIDEO)) // Redundancy for initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    // IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF|IMG_INIT_WEBP);
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return -1;
    }
    // Setup SDL object.flags
    if (fullscreen)
    { // Fullscreen object.flags
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }
    if (fullscreenDesk){
        flags = flags | SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (gDriver == 1)
    { //Choose gpu driver 0 = default, 1 = openGL 2 = Vulkan
        flags = flags | SDL_WINDOW_OPENGL;
    }
    if (gDriver == 2)
    {
        flags = flags | SDL_WINDOW_VULKAN;
    }
    if (invisible)
    {
        flags = flags | SDL_WINDOW_HIDDEN;
    }
    if (noDecoration)
    {
        flags = flags | SDL_WINDOW_BORDERLESS;
    }
    if (canResize)
    {
        flags = flags | SDL_WINDOW_RESIZABLE;
    }
    if (minimized)
    {
        flags = flags | SDL_WINDOW_MINIMIZED;
    }
    if (maximized)
    {
        flags = flags | SDL_WINDOW_MAXIMIZED;
    }
    if (foreignWindow)
    {
        flags = flags | SDL_WINDOW_FOREIGN;
    }
    if (highDPI)
    {
        flags = flags | SDL_WINDOW_ALLOW_HIGHDPI;
    }
    if (skipTaskbar)
    {
        flags = flags | SDL_WINDOW_SKIP_TASKBAR;
    }
    if (utilWin)
    {
        flags = flags | SDL_WINDOW_UTILITY;
    }
    if (tooltipWin)
    {
        flags = flags | SDL_WINDOW_TOOLTIP;
    }
    if (popup)
    {
        flags = flags | SDL_WINDOW_POPUP_MENU;
    }
    if (noFlags)
    {
        flags = 0;
    }
    // Generate window
    window = SDL_CreateWindow(title,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    xres, yres,flags);
    // Check for new window
    if(!window){
        printf("Critical: SDL failed to init");
        return -1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_RenderClear(renderer);

    // Create surface
    winSurface = SDL_GetWindowSurface(window);
    // Check surface
    if(!winSurface){
        printf("Critical: No surface generated (Could it be uncommented in source code?)");
        return -1;
    }
    printf("Window generated, Filling background");
    // Fill window with default
    SDL_FillRect(winSurface,NULL,SDL_MapRGBA(winSurface->format, 0, 0, 0, 255) );
    SDL_RenderPresent(renderer);
    return 0;
}

extern "C"{
    SDL_Window *getWindow(){
        return window;
    }

    SDL_Surface *getSurface(){
        return winSurface;
    }

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

    void blitObject(SDL_Surface *object,SDL_Rect *rect,SDL_Surface* surface,int x, int y,
                    bool scaled = false,int w =  NULL, int h = NULL){
        SDL_Rect endrect;
        endrect.x = x;
        endrect.y = y;
        endrect.w = w;
        endrect.h = h;
        if(!scaled){
            SDL_BlitSurface(object,rect,surface,&endrect);
        }
        else{
            SDL_BlitScaled(object,rect,surface,&endrect);
        }
        SDL_UpdateWindowSurface(window);
    }

    SDL_Rect makeRect(int x,int y,int w,int h){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        return rect;
    }

    void changeTitle(SDL_Window *window, char *title){
        SDL_SetWindowTitle(window,title);
    }

    void updateframestarttasks(){
        SDL_RenderClear(renderer);
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
        SDL_RenderPresent(renderer);
        SDL_Delay(16.67); //Temporary framelimit
        SDL_RenderClear(renderer);
    }

    void delay(float time){
        SDL_Delay(time);
    }

    void fillRect(SDL_Surface *surface,int r,int g, int b,int a,SDL_Rect *rect = NULL){
        SDL_FillRect(surface,rect,SDL_MapRGBA( surface->format, r, g, b , a));
    }

    void changeBGColor(int r,int g, int b,int a){
        SDL_SetRenderDrawColor(renderer,r, g, b, a);
        // SDL_UpdateWindowSurface(window); // Former update routine
        //SDL_RenderPresent(renderer);
    }

    // SDL_Timer wrap
    SDL_TimerID addTimer(Uint32 interval,SDL_TimerCallback callback,void *param){
        return SDL_AddTimer(interval,callback,param);
    }
    
    // uiHandler wrap
    // Text

    TTF_Font *loadFont(const char *fontFile,int size){
        return TTF_OpenFont(fontFile, size);
    }

    void passText(const char *text,int x,int y,TTF_Font *font,int r = 255,int g = 255,
                    int b = 255,int a = 255){
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        SDL_Surface *textSurface = generateText(text,font,r,g,b,a);
        SDL_BlitSurface(textSurface, NULL, winSurface, &dest);
        //SDL_UpdateWindowSurface(window);
    }

    // Images

    SDL_Surface *generateImage(const char *fileLocation){
        return loadImage(fileLocation);
    }

}