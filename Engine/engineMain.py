import ctypes
from ctypes import cdll
import os
import platform
import time

class Engine():
    global sdlHandler
    global STDOUT
    def __init__(self,title,xres,yres,noFlags = True,fullscreen = False,fullscreenDesk = False,gDriver = 0,
        invisible = False,noDecoration = False,canResize = False,minimized = False,
        maximized = False,foreignWindow = False,highDPI = True,skipTaskbar = False,
        utilWin = False,tooltipWin = False,popup = False):
        global STDOUT
        print("Starting engine")
        if os.name == "posix":
            enginePath = os.path.join(os.getcwd(),"build/sdlWrapper.so")
        else:
            enginePath = os.path.join(os.getcwd(),"build/sdlWrapper.dll")
        self.sdlHandler = ctypes.CDLL(enginePath) # COMPILE ENGINE BEFORE RUNNING
        newTitle = bytes(title,encoding='utf8')
        self.sdlHandler.start_engine(newTitle,xres,yres,noFlags,fullscreen,fullscreenDesk,gDriver,invisible,noDecoration,
                        canResize,minimized,maximized,foreignWindow,highDPI,skipTaskbar,utilWin,
                        tooltipWin,popup)
        print("Crumbl Engine started, getting surface and window")
        self.window = self.sdlHandler.getWindow()
        self.renderer = self.sdlHandler.getRenderer()
        print("Surface obtained\nCrumbl Engine has successfully initialized!")
    
    def UpdateFrameStartTasks(self):
        self.sdlHandler.updateframestarttasks()

    def UpdateCrumblTasks(self,mouse = True,debug = True,framelimit = 0): # Update SDL window, and set framelimits. Mouse: enable cursor; debug: allow debugger menu , framelimit: Set framelimit (Omit or set to None if no framelimit is needed)
        self.sdlHandler.updateCrumblTasks(mouse,debug,framelimit)

    def getPosition(self):
        self.sdlHandler.getPos()
    
    def setPosition(self,x,y):
        self.sdlHandler.setPos(x,y)

    def destroyWindow(self):
        self.sdlHandler.sdlShutdown()
    
    def changeTitle(self,title):
        self.sdlHandler.changeTitle(self,bytes(title,encoding='utf8'))
    
    def createRect(self,x,y,w,h):
        return self.sdlHandler.makeRect(x,y,w,h)

    def blit(self,object,rect,x,y,w = None, h = None): # Blits surface to window, rect can be None
        self.sdlHandler.blitObject(object,rect,x,y,w,h)

    def fillRect(self,r,g,b,a = 255,rect = None):
        self.sdlHandler.fillRect(rect,r,g,b,a)
    
    def changeBG(self,r,g,b,a = 255):
        self.sdlHandler.changeBGColor(r,g,b,a)

    #Text

    def loadFont(self,fontFile,size = 12):
        return self.sdlHandler.loadFont(bytes(fontFile,encoding="utf8"),size)

    def uiRenderText(self,text,x,y,font,size = 12,r = 255,g = 255,b = 255,a = 255):
        textBytes = bytes(text,encoding="utf8")
        self.sdlHandler.generateText(textBytes,int(x),int(y),font,size,r,g,b,a)
    
    #Images

    def loadImage(self,file): # Generates image, uses relative path
        fileBytes = bytes(file,encoding="utf8")
        return self.sdlHandler.generateImage(fileBytes)

        