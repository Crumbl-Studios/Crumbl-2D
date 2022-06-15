import ctypes
from ctypes import cdll
import os

class Engine():
    global sdlHandler
    def __init__(self,title,xres,yres,fullscreen = False,fullscreenDesk = False,gDriver = 0,
        invisible = False,noDecoration = False,canResize = False,minimized = False,
        maximized = False,foreignWindow = False,highDPI = True,skipTaskbar = False,
        utilWin = False,tooltipWin = False,popup = False):
        print("Starting engine")
        enginePath = os.path.join(os.getcwd(),"build/sdlWrapper.so")
        self.sdlHandler = ctypes.CDLL(enginePath) # COMPILE ENGINE BEFORE RUNNING
        newTitle = bytes(title,encoding='utf8')
        self = self.sdlHandler.main(0,"",newTitle,xres,yres,fullscreen,fullscreenDesk,gDriver,invisible,noDecoration,
                        canResize,minimized,maximized,foreignWindow,highDPI,skipTaskbar,utilWin,
                        tooltipWin,popup)
        print("Crumbl Engine started")
    
    def UpdateCrumblTasks(self,mouse = True,debug = True):
        self.sdlHandler.updateCrumblTasks(mouse,debug)

    def getPosition(self):
        self.sdlHandler.getPos()
    
    def setPosition(self,x,y):
        self.sdlHandler.setPos(x,y)

    def destroyWindow(self):
        self.sdlHandler.sdlShutdown()
    
    def changeTitle(self,title):
        self.sdlHandler.changeTitle(self,bytes(title,encoding='utf8'))

    def blit(self,object,rect,endrect):
        self.sdlHandler.blit(self,object,rect,endrect)

    def fillRect(self,r,g,b,rect = None):
        self.sdlHandler.fillRect(rect,r,g,b)
    
    def changeBG(self,r,g,b):
        self.sdlHandler.changeBGColor(r,g,b)
    
    def loadFont(self,fontFile,size = 12):
        return self.sdlHandler.loadFont(bytes(fontFile,encoding="utf8"),size)

    def uiRenderText(self,text,x,y,font,size = 12,r = 255,g = 255,b = 255):
        textBytes = bytes(text,encoding="utf8")
        self.sdlHandler.generateText(textBytes,int(x),int(y),font,size,r,g,b)
        