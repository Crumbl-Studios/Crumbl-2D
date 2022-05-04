import tkinter
from tkinter import scrolledtext, ttk
import page_renderer as page_renderer

helpdir = "home.crhd"
previousdir = "home.crhd"

class NotebookPage():
    def start_page(nbPage,startHelp = False):
        global addressbar
        # Toolbar and text sytem
        toolFrame = tkinter.Frame(nbPage,highlightbackground = "gray", highlightthickness = 1)
        toolFrame.pack(side = "top",fill = "x")
        maintext = scrolledtext.ScrolledText(nbPage,state = "disabled")
        maintext.pack(fill = "both",expand = 1)

        # Progress text
        currentop = tkinter.StringVar(nbPage)
        currentpage = tkinter.StringVar(nbPage)
        currenthelpdir = tkinter.StringVar(nbPage)

        # Control buttons
        back = ttk.Button(toolFrame,text = "⬅️",command = NotebookPage.back)
        back.pack(side = "left")
        home = ttk.Button(toolFrame,text = "⌂️", command= page_renderer.home)
        home.pack(side = "left")
        addressbar = ttk.Entry(toolFrame,textvariable=currenthelpdir)
        addressbar.pack(side = "left",fill="x",expand=1)
        addressbar.bind("<Return>",NotebookPage.load_page)
        gobutton = ttk.Button(toolFrame,text = "▶️",command = NotebookPage.load_page)
        gobutton.pack(side = "left")
        refresh = ttk.Button(toolFrame,text = "↺",command = lambda a = helpdir:page_renderer.loadpage(a))
        refresh.pack(side = "right")

        # Progress bar
        loader = ttk.Progressbar(toolFrame)

        page_renderer.set_tkVars(maintext,refresh,back,loader,nbPage,currentop,currentpage,currenthelpdir)
        if startHelp:
            page_renderer.loadpage("help/toc.crhd")
        else:
            page_renderer.loadpage("home.crhd")

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

    def load_page(event = None,page = None):
        global addressbar
        if not page == None:
            page_renderer.loadpage(page)
        else:
            p = addressbar.get()
            page_renderer.loadpage(p)
    
    def back():
        page_renderer.loadpage(previousdir)