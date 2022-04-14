import tkinter
from tkinter import scrolledtext, ttk
import page_renderer as page_renderer

helpdir = "home.crhd"
previousdir = "home.crhd"

class NotebookPage():
    def start_page(nbPage):
        # Toolbar and text sytem
        toolFrame = tkinter.Frame(nbPage,highlightbackground = "gray", highlightthickness = 1)
        toolFrame.pack(side = "top",fill = "x")
        maintext = scrolledtext.ScrolledText(nbPage,state = "disabled")
        maintext.pack(fill = "both",expand = 1)

                
        # Progress text
        currentop = tkinter.StringVar(nbPage)
        currentpage = tkinter.StringVar(nbPage)

        # Control buttons
        back = tkinter.Button(toolFrame,text = "⬅️",fg = "dodgerblue",command = 
        lambda maintext,refresh,back,loader,nbPage,currentpage,currentop:
        page_renderer.back(helpdir,maintext,refresh,back,loader,nbPage,currentpage,currentop))
        back.pack(side = "left")
        home = tkinter.Button(toolFrame,text = "⌂️",fg = "dodgerblue", command= 
        lambda maintext,refresh,back,loader,nbPage,currentpage,currentop:
        page_renderer.home(maintext,refresh,back,loader,nbPage,currentpage,currentop))
        home.pack(side = "left")
        refresh = tkinter.Button(toolFrame,text = "↺",fg = "green",command =
        lambda maintext,refresh,back,loader,nbPage,currentpage,currentop:
        page_renderer.loadpage(previousdir,maintext,refresh,back,loader,nbPage,currentpage,currentop))
        refresh.pack(side = "right")


        # Progress bar
        loader = ttk.Progressbar(toolFrame)

        currentoplabel = tkinter.Label(nbPage, textvariable = currentop)
        currentoplabel.pack(side = "top",fill="x")

        page_renderer.loadpage("home.crhd",maintext,refresh,back,loader,nbPage,currentpage,currentop)

        maintext.tag_add("normal",1.0)
        maintext.tag_config("normal",font = ("TkDefaultFont",12))
        maintext.tag_add("title",1.0)
        maintext.tag_config("title",font = ("TkDefaultFont",48,"bold"))
        maintext.tag_add("subtitle",1.0)
        maintext.tag_config("subtitle",font = ("TkDefaultFont",24,"bold"))
        maintext.tag_add("italic",1.0)
        maintext.tag_config("italic",font = ("TkDefaultFont",12,"italic"))
        maintext.tag_add("bold",1.0)
        maintext.tag_config("bold",font = ("TkDefaultFont",12,"bold"))
        maintext.tag_add("code",1.0)
        maintext.tag_config("code",font = ("Courier New",12),background = "gainsboro")
        maintext.config(cursor="xterm")