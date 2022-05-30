import tkinter
from tkinter import ttk
import sv_ttk
import fileHandler
import os

darkMode = True
theme = "sun_valley"

class settingsWin():
    def __init__(startAtSection = None):
        self = tkinter.Tk()
        self.geometry("640x640+0+0")
        self.winfo_toplevel().title("Crumbl Editor Settings")
        self.resizable(False,False)
        if theme == "sun_valley":
            if darkMode:
                sv_ttk.set_theme("dark")
                sv_ttk.use_dark_theme()
            else:
                sv_ttk.set_theme("light")
                sv_ttk.use_light_theme()
        elif theme == "forest":
            if darkMode:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-dark.tcl'))
                ttk.Style().theme_use('forest-dark')
            else:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-light.tcl'))
                ttk.Style().theme_use('forest-light')
        else:
            if darkMode:
                ttk.Style().theme_use('alt')
        self.selectionMenu = ttk.Treeview(self)
        self.selectionMenu.pack(side = 'left',fill = "y")
        self.settingArea = ttk.Frame(self)
        self.settingArea.pack(side = 'right',fill = "y")
        # Personalization settings
        self.personalizedSetting = ttk.Frame(self.settingArea)
        self.personalizedSetting.pack(fill='both', expand = 1) # Pack this so it shows up on start
        self.personalizationLabel = tkinter.Label(self.personalizedSetting,text="Personalization")
        self.personalizationLabel.pack(side = "top")
        # Terminal settings
        self.termSetting = ttk.Frame(self.settingArea)
        self.termLabel = tkinter.Label(self.personalizedSetting,text="Terminal")
        # Browser settings
        self.browserSetting = ttk.Frame(self.settingArea)
        self.browserLabel = tkinter.Label(self.personalizedSetting,text="Browser")
        # IDE settings
        self.ideSetting = ttk.Frame(self.settingArea)
        self.ideLabel = tkinter.Label(self.personalizedSetting,text="IDE")
        # AssetViewer settings
        self.aviewSetting = ttk.Frame(self.settingArea)
        self.aviewLabel = tkinter.Label(self.personalizedSetting,text="Asset Viewer")
        # sceneEditor settings
        self.termSetting = ttk.Frame(self.settingArea)
        self.termLabel = tkinter.Label(self.personalizedSetting,text="Scene Editor")
        self.mainloop()