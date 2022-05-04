import tkinter
from tkinter import Menu, ttk
import fileHandler
from PIL import ImageTk
import sv_ttk
import os

# UI Module imports
import UIModules.start_page as start_page
import UIModules.ide as ide
import UIModules.ui_editor as ui_editor

# Wizard UI imports
import UIModules.settings_wizard as settings_wizard

class app():
    def __init__(self):
        # Globalise vars created here
        global main_frame
        global left_pane
        global right_pane
        global bottom_pane
        global module_tabs
        global main
        global close_button
        global pop_button

        main = tkinter.Tk(None,None," Start Page - Crumbl Engine Editor")
        main.geometry("1366x720")

        # Theme system (Sun Valley clone)
        if settings_wizard.theme == "sun_valley":
            if settings_wizard.darkMode:
                sv_ttk.set_theme("dark")
                sv_ttk.use_dark_theme()
            else:
                sv_ttk.set_theme("light")
                sv_ttk.use_light_theme()
        elif settings_wizard.theme == "forest":
            if settings_wizard.darkMode:
                main.tk.call('source', os.path.join(fileHandler.IconDir,'forest-dark.tcl'))
                ttk.Style().theme_use('forest-dark')
            else:
                main.tk.call('source', os.path.join(fileHandler.IconDir,'forest-light.tcl'))
                ttk.Style().theme_use('forest-light')
        else:
            if settings_wizard.darkMode:
                ttk.Style().theme_use('alt')
        # Iconography
        logo_icon = tkinter.PhotoImage(master = main,file = fileHandler.crumbl_logo)

        run_icon = tkinter.PhotoImage(master = main,file = fileHandler.run_asset)
        build_icon = tkinter.PhotoImage(master = main,file = fileHandler.build_asset)
        # Set window icon
        main.iconphoto(True,logo_icon)

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

        viewmenu = tkinter.Menu(menubar, tearoff=0)
        viewmenu.add_command(label="IDE",command = lambda mod = "ide":app.runMod(mod))
        viewmenu.add_command(label="UI editor",command = lambda mod = "ui_editor":app.runMod(mod))
        viewmenu.add_command(label="Asset preview")
        viewmenu.add_separator()
        viewmenu.add_command(label = "Asset viewer")
        viewmenu.add_command(label = "Python console")
        viewmenu.add_command(label = "Objects")
        menubar.add_cascade(label="View", menu=viewmenu)

        pluginmenu = tkinter.Menu(menubar, tearoff= 0)
        pluginmenu.add_command(label="No plugins installed...", state= "disabled")
        menubar.add_cascade(label="Plugins", menu= pluginmenu)

        helpmenu = tkinter.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="Documentation")
        helpmenu.add_command(label="About...")
        menubar.add_cascade(label="Help", menu=helpmenu)

        main.config(menu = menubar)

        # Menu ribbon
        ribbon_frame = tkinter.Frame(main)
        ribbon_frame.pack(side = "top", fill = "x", expand = 0)

        ribbon_tabs = ttk.Notebook(ribbon_frame)
        ribbon_tabs.pack(side = "top", fill = "x", expand = 0)

        #Ribbon menu
        
        start_ribbon = tkinter.Frame(ribbon_tabs)
        start_ribbon.pack(side = "top",fill = "x")
        ui_ribbon = tkinter.Frame(ribbon_tabs)
        ui_ribbon.pack(side = "top",fill = "x")
        debug_ribbon = tkinter.Frame(ribbon_tabs)
        debug_ribbon.pack(side = "top",fill = "x")
        compile_ribbon = tkinter.Frame(ribbon_tabs)
        compile_ribbon.pack(side = "top",fill = "x")

        #Ribbon tab definitions

        ribbon_tabs.add(start_ribbon,text = "Start")
        ribbon_tabs.add(ui_ribbon,text = "UI")
        ribbon_tabs.add(debug_ribbon,text = "Debug")
        ribbon_tabs.add(compile_ribbon,text = "Compile")

        #Add widgets to "start" ribbon

        run_button = ttk.Button(start_ribbon,text = "Run",image= run_icon, compound= "top")
        run_button.pack(side = "left")
        build_button = ttk.Button(start_ribbon,text = "Build",image= build_icon, compound= "top")
        build_button.pack(side = "left")

        main_frame = tkinter.Frame(main)
        main_frame.pack(side = "top", fill = "both", expand = 0)

        left_pane = tkinter.Frame(main_frame)
        left_pane.pack(side = "left", fill = "y", expand = 0)
        
        right_pane = tkinter.Frame(main_frame)
        right_pane.pack(side = "right", fill = "y", expand = 0)

        bottom_pane = tkinter.Frame(main_frame)
        bottom_pane.pack(side = "bottom", fill = "x", expand = 0)

        canvas_frame = tkinter.Frame(main_frame)
        canvas_frame.pack(fill = "both", expand = 0)
        close_bar = tkinter.Frame(canvas_frame)
        close_bar.pack(side = "top",fill = "x",expand = 1)

        close_button = ttk.Button(close_bar,text = "X",state='disabled')
        close_button.pack(side = "right")
        restore_button = ttk.Button(close_bar,text = "🗗")
        restore_button.pack(side = "right")
        pop_button = ttk.Button(close_bar,text = "➚",state='disabled')
        pop_button.pack(side = "right")

        module_tabs = ttk.Notebook(canvas_frame)
        module_tabs.bind("<<NotebookTabChanged>>", app.windowTitleChange)
        module_tabs.pack(fill = "both", expand = 1)

        nbPage = app.notebookAdd("Start Page")
        start_page.NotebookPage.start_page(nbPage)

        main.mainloop()
        
    def runMod(mod):
        if mod == "start_page":
            currentTab = app.notebookAdd("Start page",closeable = True,poppable = True)
            start_page.NotebookPage.start_page(currentTab)
        if mod == "ide":
            currentTab = app.notebookAdd("IDE",renameable = True,closeable = True,poppable = True)
            ide.NotebookPage.start_page(currentTab)
        if mod == "ui_editor":
            currentTab = app.notebookAdd("UI Editor",renameable = True,closeable = True,poppable = True)
            ui_editor.NotebookPage.start_page(currentTab)
        if mod == "help_page":
            currentTab = app.notebookAdd("Help viewer",closeable = True,poppable = True)
            start_page.NotebookPage.start_page(currentTab,True)

    def windowTitleChange(event):
        global module_tabs
        tab_name = module_tabs.tab(module_tabs.select(), "text")
        main.title = tab_name +" - Crumbl Engine Editor"
        tab_no = module_tabs.index(module_tabs.select())
        print(tab_no)
        if module_tabs.closes[tab_no]:
            close_button.config(state = 'normal')
        else:
            close_button.config(state = 'disabled')
        if module_tabs.poppable[tab_no]:
            pop_button.config(state = 'normal')
        else:
            pop_button.config(state = 'disabled')

    def notebookAdd(title,renameable = False,closeable = False,poppable = False):
            global module_tabs
            try:
                module_tabs.notes.append(tkinter.Frame(module_tabs))
                module_tabs.texts.append(title)
                module_tabs.renames.append(renameable)
                module_tabs.closes.append(closeable)
                module_tabs.poppable.append(poppable)
            except Exception:
                module_tabs.notes = []
                module_tabs.texts = []
                module_tabs.closes = []
                module_tabs.poppable = []
                module_tabs.renames = []
                module_tabs.notes.append(tkinter.Frame(module_tabs))
                module_tabs.texts.append(title)
            module_tabs.add(module_tabs.notes[-1],text = title)
            varName = module_tabs.notes[-1] #len(upNotebook.notes)
            print("Tab system: tab generated"+str(varName)+","+title)
            if poppable:
                close_button.config(state = 'normal')
            else:
                close_button.config(state = 'disabled')
            if poppable:
                pop_button.config(state = 'normal')
            else:
                pop_button.config(state = 'disabled')
            return varName

engine = app()