import tkinter
from tkinter import ttk
import os
import UIModules.settings_wizard as settings_wizard
import fileHandler
import sv_ttk

# Code seperated to allow for custom themeing to carry over


class seperatedWin():
    def __init__(self):
        self = tkinter.Tk()
        self.geometry("1366x768")
        if settings_wizard.theme == "sun_valley":
            if settings_wizard.darkMode:
                sv_ttk.set_theme("dark")
            else:
                sv_ttk.set_theme("light")
        elif settings_wizard.theme == "forest":
            if settings_wizard.darkMode:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-dark.tcl'))
                ttk.Style().theme_use('forest-dark')
            else:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-light.tcl'))
                ttk.Style().theme_use('forest-light')
        else:
            if settings_wizard.darkMode:
                ttk.Style().theme_use('alt')
        self.returnbar = ttk.Frame(self)
        self.returnbar.pack(side = "top",fill="x")
        self.collapsebutton = ttk.Button(self.returnbar,text = "↶")
        self.collapsebutton.pack(side='left')
        print(self)
    def additems(self,title):
        self.winfo_toplevel().title(title)