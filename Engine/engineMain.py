from ctypes import cdll
import os

class Engine():
    global sdlHandler
    def __init__(title,xres,yres,fullscreen = False,fullscreenDesk = False,gDriver = 0,
        invisible = False,noDecoration = False,canResize = False,minimized = False,
        maximized = False,foreignWindow = False,highDPI = True,skipTaskbar = False,
        utilWin = False,tooltipWin = False,popup = False):
        print("Starting engine")
        sdlHandler = cdll.LoadLibrary("./build/sdlWrapper.so") # COMPILE ENGINE BEFORE RUNNING
        sdl = sdlHandler.main(title,xres,yres,fullscreen,fullscreenDesk,gDriver,invisible,noDecoration,
                        canResize,minimized,maximized,foreignWindow,highDPI,skipTaskbar,utilWin,
                        tooltipWin,popup)
        print("Crumbl Engine started")
        return sdl