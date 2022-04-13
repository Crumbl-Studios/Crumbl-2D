import tkinter
from tkinter import scrolledtext

class NotebookPage():
    def start_page(nbPage):
        toolFrame = tkinter.Frame(nbPage,highlightbackground = "gray", highlightthickness = 1)
        toolFrame.pack(side = "top",fill = "x")
        maintext = scrolledtext.ScrolledText(nbPage)
        maintext.pack(fill = "both",expand = 1)

        back = tkinter.Button(toolFrame,text = "⬅️",fg = "dodgerblue")
        back.pack(side = "left")
        home = tkinter.Button(toolFrame,text = "⌂️",fg = "dodgerblue")
        home.pack(side = "left")
        refresh = tkinter.Button(toolFrame,text = "↺",fg = "green")
        refresh.pack(side = "right")
