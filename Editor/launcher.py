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
        self.splashScreen.geometry("700x420+2000+500")
        self.splashScreen.overrideredirect(False)
        self.splashImage = ImageTk.PhotoImage(Image.open(fileHandler.launcherSplash).resize((700,400)))
        self.imageText = tkinter.Label(image=self.splashImage)
        self.imageText.pack()
        self.loadStatus = tkinter.StringVar(self.imageText)
        self.loadBar = ttk.Progressbar()
        self.loadBar.pack(side="bottom",fill="x")
    def convertFromSplash(self):
        self.splashScreen.overrideredirect(False)
        self.splashScreen.geometry("1000x600")
        self.imageText.destroy()
        self.loadBar.destroy()
        self.splashScreen.title("Crumbl Engine Launcher")
        self.menuBar = tkinter.Frame()
        self.menuBar.pack(side="top")
        self.splashScreen.mainloop()

    def createProject(self):
        cProgressBar = ttk.Progressbar(self)
        cProgressBar.pack(side = "top",fill="x")
        cText = ttk.Label(self,text = "Create New Project",font = ("TkDefaultFont",24,"bold"))
        cText.pack(side = "top",fill = "x")

splashScreen = splash()
splashScreen.splashScreen.update()
settings_wizard.NotebookPage.applySettings(splashScreen.splashScreen,splashScreen.loadStatus,splashScreen.loadBar)
splashScreen.convertFromSplash()