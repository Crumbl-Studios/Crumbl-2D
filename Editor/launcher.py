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
        self.menuBar = tkinter.Frame(relief="raised",borderwidth=2)
        self.menuBar.pack(side="top", fill= "x")
        self.hamburgerButton = ttk.Button(self.menuBar,text = "X ⬅Menu",command=self.toggleHamburger)
        self.hamburgerButton.pack(side = "left")
        self.backButton = ttk.Button(self.menuBar,text="<Back")
        self.logoImageFile = Image.open(fileHandler.crumbl_logo).resize((24,24))
        self.logoImage = ImageTk.PhotoImage(self.logoImageFile)
        self.windowTitle = ttk.Label(self.menuBar,text = "Crumbl Engine Launcher",image=self.logoImage,compound="left")
        self.windowTitle.pack(side="left",anchor="center",fill=None)
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
        self.hamburgerMenu = tkinter.Frame(relief="groove",borderwidth=2)
        self.hamburgerMenu.pack(side="left",fill="y")
        self.newProjectText = ttk.Label(self.hamburgerMenu,text="NEW")
        self.newProjectText.pack(side="top",fill = "x")
        self.newProjectImage = ImageTk.PhotoImage(Image.open(fileHandler.new_project_asset))
        self.newGameButton = ttk.Button(self.hamburgerMenu,text="New Project",image = self.newProjectImage,compound="left",command=self.createProject)
        self.newGameButton.pack(side = "top",fill = "x")
        self.openProjectText = ttk.Label(self.hamburgerMenu,text="OPEN")
        self.openProjectText.pack(side="top",fill = "x")
        self.openProjectImage = ImageTk.PhotoImage(Image.open(fileHandler.open_project_asset))
        self.openGameButton = ttk.Button(self.hamburgerMenu,text="Open Project",image = self.openProjectImage,compound="left")
        self.openGameButton.pack(side = "top",fill = "x")
        self.gitCloneImage = ImageTk.PhotoImage(Image.open(fileHandler.git_clone_asset))
        self.openGitButton = ttk.Button(self.hamburgerMenu,text="Clone from Git",image = self.gitCloneImage,compound="left")
        self.openGitButton.pack(side = "top",fill = "x")
        self.settingsText = ttk.Label(self.hamburgerMenu,text="SETTINGS")
        self.settingsText.pack(side="top",fill = "x")
        self.settingsImage = ImageTk.PhotoImage(Image.open(fileHandler.settings_asset))
        self.settingsButton = ttk.Button(self.hamburgerMenu,text="Settings",image = self.settingsImage,compound="left")
        self.settingsButton.pack(side = "top",fill = "x")

        # Pre-determined widget frames
        self.welcomeFrame = tkinter.Frame()
        self.createFrame = tkinter.Frame()
        self.settingsFrame = tkinter.Frame()

        self.welcomeFrame.pack(fill="both",expand=1)
        self.wText = ttk.Label(self.welcomeFrame,text = "Welcome to the Crumbl Engine!",font = ("TkDefaultFont",24,"bold"))
        self.wText.pack(side = "top",fill = "x")

        # Final steps
        self.splashScreen.mainloop()
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
        self.createFrame.pack(fill="both",expand=1)
        self.welcomeFrame.pack_forget()
        # Temporarily remove window title, rename it, pack back button to be in correct order, repack title 
        self.windowTitle.pack_forget()
        self.backButton.pack(side="left")
        self.windowTitle.config(text = "Create New - Crumbl Engine Launcher")
        self.windowTitle.pack(side="left")
        # Remove hamburger button (will be returned if returned to welcome page)
        self.hamburgerEnable = True
        self.toggleHamburger()
        self.hamburgerButton.pack_forget()
        #Generate new widgets
        self.cProgressBar = ttk.Progressbar(self.createFrame)
        self.cProgressBar.pack(side = "top",fill="x")
        self.cText = ttk.Label(self.createFrame,text = "Create New Project",font = ("TkDefaultFont",24,"bold"))
        self.cText.pack(side = "top",fill = "x")

splashScreen = splash()
splashScreen.splashScreen.update()
settings_wizard.NotebookPage.applySettings(splashScreen.splashScreen,splashScreen.loadStatus,splashScreen.loadBar)
splashScreen.convertFromSplash()