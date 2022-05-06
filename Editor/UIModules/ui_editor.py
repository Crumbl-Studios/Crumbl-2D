import tkinter
from tkinter import scrolledtext, ttk

class NotebookPage():
    def start_page(nbPage):
        scenes = ["No scene","foo"]
        layers = ["No layers","bar"]
        sceneSelection = tkinter.StringVar(nbPage)
        layerSelection = tkinter.StringVar(nbPage)
        layerBar = ttk.Frame(nbPage)
        layerBar.pack(side="top",fill="x")
        sceneText = ttk.Label(layerBar,text = "Scene:")
        sceneText.pack(side = "left")
        sceneSelect = ttk.OptionMenu(layerBar,sceneSelection,"No scene",*scenes)
        sceneSelect.pack(side="left")
        labelText = ttk.Label(layerBar,text = "Layer:")
        labelText.pack(side = "left")
        layerSelect = ttk.OptionMenu(layerBar,layerSelection,"No layer",*layers)
        layerSelect.pack(side="left")
        edit = tkinter.Canvas(nbPage)
        edit.pack(fill = 'both',expand=1)