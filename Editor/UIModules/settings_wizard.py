import tkinter
from tkinter import ttk
from PIL import ImageTk
import sv_ttk
import fileHandler
import os

settingObjects = ["Personalization","Terminal","Browser","IDE","Asset Viewer","Scene Editor"]
settingChanged = [False,False,False,False,False,False]
settingColumns = ["category","changed"]

darkMode = True
theme = "sun_valley"

class settingsWin():
    global settingObjects
    global settingColumns
    global settingChanged
    def __init__(startAtSection = None):
        self = tkinter.Tk()
        self.winfo_toplevel().title("Crumbl Editor Settings")
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
        self.selectionMenu = ttk.Treeview(self,columns=settingColumns)
        #Load setting categories from list
        self.selectionMenu.heading("category",text = "Category")
        self.selectionMenu.pack(side = 'left',fill = "y",expand=0)
        self.settingArea = ttk.Frame(self)
        self.settingArea.pack(fill = "both",expand=0)
        # Bottom bar
        self.bottomBar = ttk.Frame(self)
        self.bottomBar.pack(side = "bottom",fill = "x",expand=1)
        self.okBtn = ttk.Button(self.bottomBar,text = "✓ OK",style="Accent.TButton")
        self.okBtn.pack(side = "right")
        self.applyBtn = ttk.Button(self.bottomBar,text = "Apply")
        self.applyBtn.pack(side = "right")
        self.closeBtn = ttk.Button(self.bottomBar,text = "⮾ Close")
        self.closeBtn.pack(side = "right")
        self.geometry("640x640+0+0")
        self.resizable(False,False)
        # Personalization settings
        self.personalizedSetting = ttk.Frame(self.settingArea)
        self.personalizedSetting.pack(fill='both') # Pack this so it shows up on start
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