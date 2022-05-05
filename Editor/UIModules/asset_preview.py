import tkinter
from tkinter import ttk

class NotebookPage():
    def start_page(nbPage,startHelp = False):
        noassetlabel = ttk.Label(nbPage,text="No asset")
        noassetlabel.pack()