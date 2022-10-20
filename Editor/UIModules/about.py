import tkinter
import fileHandler
from tkinter import scrolledtext, ttk

class NotebookPage():
    def start_page(nbPage,startHelp = False):
        about = nbPage
        engine_icon = tkinter.PhotoImage(master = about,file = fileHandler.engine_logo)
        studio_icon = tkinter.PhotoImage(master = about,file = fileHandler.studio_logo)
        logo = tkinter.Label(about,image = engine_icon,text="Version: 0.1B",compound="top")
        logo.pack(side = "top",expand = 0)
        text = tkinter.Label(about,text="Engine Version: 0.1B")
        text.pack(side = "top",expand = 0)
        names = scrolledtext.ScrolledText(about)
        names.pack(side = "top",expand = 0)
        names.tag_add("title",tkinter.INSERT,tkinter.END)
        names.tag_config("title",font = ("TkDefaultFont",48,"bold"))
        names.tag_add("title",tkinter.INSERT,tkinter.END)
        names.tag_config("normal",font = ("TkDefaultFont",12))
        names.insert(tkinter.END,"Made by these contributors:\n","title")
        names.insert(tkinter.END,"FROM CRUMBL STUDIOS:\nRJ Carter\nEshan Tahir\n","normal")
        names.insert(tkinter.END,"Did you contribute to this project? Add your name here!","normal")
        clsBtn = ttk.Button(about,text = "⮾ Close")
        clsBtn.pack(side = "top",anchor="se",expand = 1)