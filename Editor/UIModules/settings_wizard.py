import tkinter
from tkinter import ttk
from PIL import ImageTk
import sv_ttk
import fileHandler
import os

settingObjects = ["Personalization","Terminal","Browser","IDE","Asset Viewer","Scene Editor"]
settingChanged = [False,False,False,False,False,False]
settingColumns = ["category","changed"]
settingAmounts = 8

# Object values
# Personalization
readableThemeNames = ["Sun Valley","Forest", "Normal TCL/TK theme"]

darkMode = True
theme = "sun_valley"

# Images and Icons
darkModeIcon : ImageTk.PhotoImage
lightModeIcon : ImageTk.PhotoImage
themeTextVar = ""

class NotebookPage():
    def applySettings(self,currentOP,progressBar,window,isAfterSave = False):
        global themeTextVar
        global darkModeIcon
        global lightModeIcon
        # Read settings from json
        currentOP.set("Checking for data folder")
        progressBar.step(100/settingAmounts)
        self.saveLoc = fileHandler.get_save_loc()
        window.update()
        if not isAfterSave:
            currentOP.set("Getting settings")
            self.settingDataNew = fileHandler.get_setting_data()
            progressBar.step(100/settingAmounts)
            window.update()
        currentOP.set("Getting templates")
        self.templateDataNew = fileHandler.get_template_data()
        progressBar.step(100/settingAmounts)
        window.update()
        # Load theme
        currentOP.set("Loading setting 1/2")
        progressBar.step(100/settingAmounts)
        window.update()
        if theme == "sun_valley":
            themeTextVar = tkinter.StringVar(window,value = "Sun Valley")
            currentOP.set("Loading setting 2/2")
            progressBar.step(100/settingAmounts)
            window.update()
            if darkMode:
                sv_ttk.set_theme("dark")
                sv_ttk.use_dark_theme()
            else:
                sv_ttk.set_theme("light")
                sv_ttk.use_light_theme()
            currentOP.set("Setting theme thumbnails")
            progressBar.step(100/settingAmounts)
            window.update()
            darkModeIcon = tkinter.PhotoImage(master = window, file = fileHandler.sv_dark_asset)
            lightModeIcon = tkinter.PhotoImage(master = window, file = fileHandler.sv_light_asset)
        elif theme == "forest":
            currentOP.set("Loading setting 2/2")
            progressBar.step(100/settingAmounts)
            window.update()
            themeTextVar = tkinter.StringVar(self,value = "Forest")
            if darkMode:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-dark.tcl'))
                ttk.Style().theme_use('forest-dark')
            else:
                self.tk.call('source', os.path.join(fileHandler.IconDir,'forest-light.tcl'))
                ttk.Style().theme_use('forest-light')
            currentOP.set("Setting theme thumbnails")
            progressBar.step(100/settingAmounts)
            window.update()
            darkModeIcon = tkinter.PhotoImage(master = self, file = fileHandler.forest_dark_asset)
            lightModeIcon = tkinter.PhotoImage(master = self, file = fileHandler.forest_light_asset)
        else:
            currentOP.set("Loading setting 2/2")
            progressBar.step(100/settingAmounts)
            window.update()
            themeTextVar = tkinter.StringVar(self,value = "Normal TCL/TK style")
            if darkMode:
                ttk.Style().theme_use('alt')
            currentOP.set("Setting theme thumbnails")
            progressBar.step(100/settingAmounts)
            window.update()
            darkModeIcon = tkinter.PhotoImage(master = self, file = fileHandler.tk_dark_asset)
            lightModeIcon = tkinter.PhotoImage(master = self, file = fileHandler.tk_light_asset)
        currentOP.set("Ready")
        window.update()

    def start_page(nbPage,startHelp = False):
        global settingObjects
        global settingColumns
        global settingChanged
        global themeTextVar
        self = nbPage
        self.selectionMenu = ttk.Treeview(self,columns=settingColumns)
        #Load setting categories from list
        self.selectionMenu.heading("category",text = "Category")
        self.selectionMenu.pack(side = 'left',fill = "y",expand=0)
        # Main area
        self.settingArea = ttk.Frame(self)
        self.settingArea.pack(fill = "both",expand=1)
        # Bottom bar
        self.bottomBar = ttk.Frame(self)
        self.bottomBar.pack(side = "bottom",fill = "x",expand=1)
        self.okBtn = ttk.Button(self.bottomBar,text = "✓ OK",style="Accent.TButton")
        self.okBtn.pack(side = "right")
        self.applyBtn = ttk.Button(self.bottomBar,text = "Apply")
        self.applyBtn.pack(side = "right")
        self.closeBtn = ttk.Button(self.bottomBar,text = "⮾ Close")
        self.closeBtn.pack(side = "right")
        # Personalization settings
        self.personalizedSetting = ttk.Frame(self.settingArea)
        self.personalizedSetting.pack(fill='both') # Pack this so it shows up on start
        self.personalizationLabel = tkinter.Label(self.personalizedSetting,text="Personalization")
        self.personalizationLabel.pack(side = "top")
        self.themeDecider = ttk.Frame(self.personalizedSetting)
        self.themeDecider.pack(side="bottom")
        self.lightButton = ttk.Button(self.themeDecider,text = "Light",image = lightModeIcon,compound="top",command=lambda self = self: NotebookPage.chooseLightMode(self))
        self.lightButton.pack(side="left")
        self.darkButton = ttk.Button(self.themeDecider,text = "Dark",image = darkModeIcon,compound="top",command=lambda self = self: NotebookPage.chooseDarkMode(self))
        self.darkButton.pack(side="right")
        self.modeText = ttk.Label(self.personalizedSetting,text = "Mode:")
        self.modeText.pack(side="bottom")
        self.themeDropdown = ttk.OptionMenu(self.personalizedSetting,themeTextVar,themeTextVar.get(),*readableThemeNames)
        self.themeDropdown.pack(side="bottom")
        self.themeText = ttk.Label(self.personalizedSetting,text = "Theme:")
        self.themeText.pack(side="bottom")
        if darkMode:
            self.darkButton.config(style="Accent.TButton")
        else:
            self.LightButton.config(style="Accent.TButton")
        # Terminal settings
        self.termSetting = ttk.Frame(self.settingArea)
        self.termLabel = tkinter.Label(self.termSetting,text="Terminal")
        self.termLabel.pack(side = "top")
        # Browser settings
        self.browserSetting = ttk.Frame(self.settingArea)
        self.browserLabel = tkinter.Label(self.browserSetting,text="Browser")
        self.browserLabel.pack(side = "top")
        # IDE settings
        self.ideSetting = ttk.Frame(self.settingArea)
        self.ideLabel = tkinter.Label(self.ideSetting,text="IDE")
        self.ideLabel.pack(side = "top")
        # AssetViewer settings
        self.aviewSetting = ttk.Frame(self.settingArea)
        self.aviewLabel = tkinter.Label(self.aviewSetting,text="Asset Viewer")
        self.aviewLabel.pack(side = "top")
        # sceneEditor settings
        self.sceneSetting = ttk.Frame(self.settingArea)
        self.sceneLabel = tkinter.Label(self.sceneSetting,text="Scene Editor")
        self.sceneLabel.pack(side = "top")
    def chooseDarkMode(self):
        darkMode = True
        self.darkButton.config(style="Accent.TButton")
        self.lightButton.config(style="")
    def chooseLightMode(self):
        darkMode = False
        self.darkButton.config(style="")
        self.lightButton.config(style="Accent.TButton")