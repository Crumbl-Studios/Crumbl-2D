##    Crumbl Engine Loader
##    Copyright (C) 2022 Crumbl Studios

##    This program is free software; you can redistribute it and/or modify
##    it under the terms of the GNU General Public License as published by
##    the Free Software Foundation; version 2 of the License

##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.

##    You should have received a copy of the GNU General Public License along
##    with this program; if not, write to the Free Software Foundation, Inc.,
##    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
import tkinter
from tkinter import ttk
from PIL import ImageTk,Image
import sv_ttk
## Launcher files
import fileHandler
import UIModules.settings_wizard as settings_wizard

class splash():
    def __init__(self):
        self.splashScreen = tkinter.Tk(None,None," Loading - Crumbl Engine Launcher")
        self.splashScreen.overrideredirect(True)
        self.splashScreen.geometry("700x420+2000+500")
        self.splashImage = ImageTk.PhotoImage(Image.open(fileHandler.launcherSplash).resize((700,400)))
        self.imageText = tkinter.Label(image=self.splashImage)
        self.imageText.pack()
        self.loadStatus = tkinter.StringVar(self.imageText)
        self.loadBar = ttk.Progressbar()
        self.loadBar.pack(side="bottom",fill="x")
        self.hamburgerEnable = True
    def convertFromSplash(self):
        # Custom window decorations
        self.splashScreen.geometry("1000x600")
        self.imageText.destroy()
        self.loadBar.destroy()
        self.splashScreen.title("Crumbl Engine Launcher")
        self.resizeGrip = ttk.Sizegrip(self.splashScreen)
        self.resizeGrip.pack(side = "bottom",anchor="se")
        self.menuBar = tkinter.Frame(bd=1)
        self.menuBar.pack(side="top", fill= "x")
        self.hamburgerButton = ttk.Button(self.menuBar,text = "X ⬅Menu",command=self.toggleHamburger)
        self.hamburgerButton.pack(side = "left")
        self.windowTitle = ttk.Label(self.menuBar,text = "Crumbl Engine Launcher")
        self.windowTitle.pack(anchor = "s",expand=0)
        self.closeButton = ttk.Button(self.menuBar,text="X",style="Accent.TButton",command=quit)
        self.closeButton.pack(side="right",anchor="ne")
        self.maximizeButton = ttk.Button(self.menuBar,text="🗖",style="Accent.TButton",state="disabled")
        self.maximizeButton.pack(side="right",anchor="ne")
        self.minimizeButton = ttk.Button(self.menuBar,text="-",style="Accent.TButton",state="disabled")
        self.minimizeButton.pack(side="right",anchor="ne")
        self.windowTitle.bind("<Button-1>",self.clickWindow)
        self.windowTitle.bind("<B1-Motion>",self.moveWindow)
        self.menuBar.bind("<Button-1>",self.clickWindow)
        self.menuBar.bind("<B1-Motion>",self.moveWindow)

        # Hamburger menu options
        self.hamburgerMenu = tkinter.Frame()
        self.hamburgerMenu.pack(side="left",fill="y")
        self.newProjectText = ttk.Label(self.hamburgerMenu,text="NEW")
        self.newProjectText.pack(side="top",fill = "x")
        self.newGameButton = ttk.Button(self.hamburgerMenu,text="New Project")
        self.newGameButton.pack(side = "top",fill = "x")
        self.newProjectText = ttk.Label(self.hamburgerMenu,text="OPEN")
        self.newProjectText.pack(side="top",fill = "x")
        self.newGameButton = ttk.Button(self.hamburgerMenu,text="Open Project")
        self.newGameButton.pack(side = "top",fill = "x")
        self.newGameButton = ttk.Button(self.hamburgerMenu,text="Clone from Git")
        self.newGameButton.pack(side = "top",fill = "x")

        # Final steps
        self.splashScreen.mainloop()
    def geomSet(self,event = None):
        xgeom = self.splashScreen.winfo_screenheight()
        ygeom = self.splashScreen.winfo_screenwidth()
    def moveWindow(self,event):
        global x
        global y
        x = self.splashScreen.winfo_pointerx() - self.splashScreen._offsetx
        y = self.splashScreen.winfo_pointery() - self.splashScreen._offsety
        self.splashScreen.geometry('+{x}+{y}'.format(x=x,y=y))
    def clickWindow(self,event):
        self.splashScreen._offsetx = event.x
        self.splashScreen._offsety = event.y

    def toggleHamburger(self):
        if self.hamburgerEnable:
            self.hamburgerEnable = False
            self.hamburgerButton.config(text="≡")
            self.hamburgerMenu.pack_forget()
        else:
            self.hamburgerEnable = True
            self.hamburgerButton.config(text="X")
            self.hamburgerMenu.pack(side="left",fill="y")
    def createProject(self):
        cProgressBar = ttk.Progressbar(self)
        cProgressBar.pack(side = "top",fill="x")
        cText = ttk.Label(self,text = "Create New Project",font = ("TkDefaultFont",24,"bold"))
        cText.pack(side = "top",fill = "x")

splashScreen = splash()
splashScreen.splashScreen.update()
settings_wizard.NotebookPage.applySettings(splashScreen.splashScreen,splashScreen.loadStatus,splashScreen.loadBar)
splashScreen.convertFromSplash()