import tkinter
from tkinter import ttk

class NotebookPage():
    def start_page(nbPage,startHelp = False):
        cProgressBar = ttk.Progressbar(nbPage)
        cProgressBar.pack(side = "top",fill="x")
        cText = ttk.Label(nbPage,text = "Create New Project",font = ("TkDefaultFont",24,"bold"))
        cText.pack(side = "top",fill = "x")
