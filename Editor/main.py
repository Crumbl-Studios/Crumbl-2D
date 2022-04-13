import tkinter
from tkinter import Menu, ttk

# UI Module imports
import UIModules.start_page as start_page

class app():
    def __init__(self):
        # Globalise vars created here
        global main_frame
        global left_pane
        global right_pane
        global bottom_pane
        global module_tabs

        main = tkinter.Tk(None,None," Crumbl Engine Editor")
        main.geometry("1366x720")

        # File/Edit/Help Menu

        menubar = tkinter.Menu(main)

        filemenu = tkinter.Menu(menubar, tearoff=0)
        filemenu.add_command(label="New project")
        filemenu.add_command(label="Open project")
        filemenu.add_command(label="Save")
        filemenu.add_separator()
        filemenu.add_command(label="Configure Git")
        filemenu.add_command(label="Clone repo")
        filemenu.add_command(label="Push to repo")
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=main.quit)
        menubar.add_cascade(label="File", menu=filemenu)

        editmenu = tkinter.Menu(menubar, tearoff=0)
        editmenu.add_command(label="Undo")
        editmenu.add_command(label="Redo")
        editmenu.add_separator()
        editmenu.add_command(label="Cut")
        editmenu.add_command(label="Copy")
        editmenu.add_command(label="Paste")
        editmenu.add_separator()
        editmenu.add_command(label = "Indent region")
        editmenu.add_command(label = "Dedent region")
        menubar.add_cascade(label="Edit", menu=editmenu)

        editmenu = tkinter.Menu(menubar, tearoff=0)
        editmenu.add_command(label="Start page")
        editmenu.add_command(label="IDE")
        editmenu.add_command(label="UI editor")
        editmenu.add_command(label="Help")
        editmenu.add_separator()
        editmenu.add_command(label = "Asset viewer")
        editmenu.add_command(label = "Python console")
        editmenu.add_command(label = "Objects")
        menubar.add_cascade(label="View", menu=editmenu)

        helpmenu = tkinter.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="Documentation")
        helpmenu.add_command(label="About...")
        menubar.add_cascade(label="Help", menu=helpmenu)

        main.config(menu = menubar)

        # Menu ribbon
        ribbon_frame = tkinter.Frame(main)
        ribbon_frame.pack(side = "top", fill = "x", expand = 1)

        ribbon_tabs = ttk.Notebook(ribbon_frame)
        ribbon_tabs.pack(side = "top", fill = "x", expand = 1)

        #Ribbon menu
        
        start_ribbon = tkinter.Frame(ribbon_tabs)
        start_ribbon.pack(side = "top",fill = "x")
        ui_ribbon = tkinter.Frame(ribbon_tabs)
        ui_ribbon.pack(side = "top",fill = "x")

        #Ribbon tab definitions

        ribbon_tabs.add(start_ribbon,text = "Start")
        ribbon_tabs.add(ui_ribbon,text = "UI")

        main_frame = tkinter.Frame(main)
        main_frame.pack(side = "top", fill = "x", expand = 1)

        left_pane = tkinter.Frame(main_frame)
        left_pane.pack(side = "left", fill = "y", expand = 1)
        
        right_pane = tkinter.Frame(main_frame)
        right_pane.pack(side = "right", fill = "y", expand = 1)

        bottom_pane = tkinter.Frame(main_frame)
        bottom_pane.pack(side = "bottom", fill = "x", expand = 1)

        module_tabs = ttk.Notebook(main_frame)
        module_tabs.pack(fill = "both", expand = 1)

        main.mainloop()


engine = app()
