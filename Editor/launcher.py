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
        self.splashScreen.wm_attributes('-type', 'splash')
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
        self.splashScreen.wm_attributes('-type', 'normal')
        self.splashScreen.geometry("1000x600")
        self.imageText.destroy()
        self.loadBar.destroy()
        self.splashScreen.title("Crumbl Engine Launcher")
        self.menuBar = tkinter.Frame(relief="raised",borderwidth=2)
        self.menuBar.pack(side="top", fill= "x")
        self.hamburgerButton = ttk.Button(self.menuBar,text = "X",command=self.toggleHamburger)
        self.hamburgerButton.pack(side = "left")
        self.backButton = ttk.Button(self.menuBar,text="<Back")
        self.logoImageFile = Image.open(fileHandler.crumbl_logo).resize((24,24))
        self.splashScreen.iconphoto(True,ImageTk.PhotoImage(self.logoImageFile))
        self.searchResult = tkinter.StringVar(self.menuBar,"Search projects...")
        self.searchBar = ttk.Entry(self.menuBar,textvariable=self.searchResult)
        self.searchBar.pack(side = "right")
        self.searchBar.bind("<Button-1>",self.clearSearch)

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
    def clearSearch(self,event = None):
        self.searchResult.set("")

    def toggleHamburger(self):
        if self.hamburgerEnable:
            self.hamburgerEnable = False
            self.hamburgerButton.config(text="≡")
            self.hamburgerMenu.pack_forget()
        else:
            self.hamburgerEnable = True
            self.hamburgerButton.config(text="X")
            self.hamburgerMenu.pack(side="left",fill="y")

    def backToMainMenu(self,menu):
        if menu == "newGame":
            self.welcomeFrame.pack()
            self.createFrame.pack_forget()
        self.backButton.pack_forget()
        self.hamburgerButton.pack(side="left")

    def createProject(self):
        self.createFrame.pack(fill="both",expand=1)
        self.welcomeFrame.pack_forget()
        # Rename window, place back button
        self.splashScreen.winfo_toplevel().title = "New project - Crumbl Engine Launcher"
        self.backButton.pack(side="left")
        self.backButton.config(command=lambda self = self,a = "newGame":self.backToMainMenu(a))
        # Remove hamburger button (will be returned if returned to welcome page)
        self.hamburgerEnable = True
        self.toggleHamburger()
        self.hamburgerButton.pack_forget()
        self.searchResult.set("Search templates...")
        #Generate new widgets
        self.cProgressBar = ttk.Progressbar(self.createFrame)
        self.cProgressBar.pack(side = "top",fill="x")
        self.continueButton = ttk.Button(self.createFrame,text = "Install a template")
        self.continueButton.pack(anchor="ne")
        self.cText = ttk.Label(self.createFrame,text = "Create New Project",font = ("TkDefaultFont",24,"bold"))
        self.cText.pack(side = "top")
        self.choiceText = ttk.Label(self.createFrame,text = "Choose a template")
        self.choiceText.pack(side = "top")
        self.templateFrame = ttk.Frame(relief="raised",borderwidth=2)
        self.templateFrame.pack(side = "left",fill= "both")
        self.choiceFrame = ttk.Frame(self.createFrame)
        self.choiceFrame.pack(side = "right",fill="y")
        self.continueButton = ttk.Button(self.choiceFrame,text = "Next>",style="Accent.TButton")
        self.continueButton.pack()


splashScreen = splash()
splashScreen.splashScreen.update()
settings_wizard.NotebookPage.applySettings(splashScreen.splashScreen,splashScreen.loadStatus,splashScreen.loadBar)
splashScreen.convertFromSplash()