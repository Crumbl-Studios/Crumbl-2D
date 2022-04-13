import tkinter
import main

class NotebookPage():
    def start_page():
        nbPage = main.module_tabs.notebookAdd("Start Page")
        toolFrame = tkinter.Frame(nbPage,highlightbackground = "gray", highlightthickness = 1)
        toolFrame.pack(side = "top",fill = "x")