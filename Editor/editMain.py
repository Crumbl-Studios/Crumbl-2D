##    Crumbl 2D Editor
##    Copyright (C) 2022 Crumbl Studios

##    This program is free software; you can redistribute it and/or modify
##    it under the terms of the GNU General Public License as published by
##    the Free Software Foundation; version 2 of the License

##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.

##    You should have received a copy of the GNU General Public License along
##    with this program; if not, write to the Free Software Foundation, Inc.,
##    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

import tkinter
from tkinter import Menu, ttk, font, scrolledtext
import fileHandler
from PIL import ImageTk,Image,ImageFont,ImageDraw
import sv_ttk
import os

# UI Module imports
import UIModules.start_page as start_page
import UIModules.ide as ide
import UIModules.ui_editor as ui_editor
import UIModules.asset_preview as asset_preview
import UIModules.about as about
import seperatedWindow
from tkinter.colorchooser import askcolor

# Wizard UI imports
import UIModules.settings_wizard as settings_wizard

def convertRGBcolor(r,g,b):
    return "#%02x%02x%02x" %(r,g,b)

class app():
    def __init__(self,projectDir,isANewDirectory,template = "",projectTitle = ""):
        # Globalise vars created here
        global main_frame
        global left_pane
        global right_pane
        global bottom_pane
        global module_tabs
        global main
        global close_button
        global pop_button
        global windowedTabs
        global close_bar
        global mini_win_canvas
        global mini_wins
        global winModeDetached
        global winModeSeperate
        global winModeTabbed
        global tabMode
        global wins
        global canvas_frame
        global win_mode
        global move_frames
        global select_button
        global move_button
        global rotate_button
        global resize_button
        global quick_select_button
        global quick_move_button
        global quick_rotate_button
        global quick_resize_button
        global isFullscreen

        wins = []
        mini_wins = []
        windowedTabs = []
        tabMode = 0
        win_mode = "tabbed"
        main = tkinter.Tk(None,None," Loading - Crumbl 2D Editor")
        
        # Project and settings splash screen (Setup and use main window)
        main.resizable(False,False)
        main.geometry("1000x600")
        self.splashImage = ImageTk.PhotoImage(Image.open(fileHandler.launcherSplash).resize((700,400)))
        self.imageText = tkinter.Label(image=self.splashImage)
        self.imageText.pack()
        loadArea = tkinter.Frame(main)
        loadArea.pack(side="bottom",fill="x")
        currentoptext = tkinter.StringVar(loadArea,"Loading")
        currentoplabel = tkinter.Label(loadArea,textvariable = currentoptext)
        currentoplabel.pack(side="left")
        loadBar = ttk.Progressbar(loadArea)
        loadBar.pack(side="right")
        main.update()
        main.defaultFont = font.nametofont("TkDefaultFont")
        main.defaultFont.configure(family="Source Sans Pro")
        currentoptext.set("Compositing splash screen")
        launcherSplash = app.compositeSplashScreen(fileHandler.projectSplash,projectTitle,"author")
        self.splashImage = ImageTk.PhotoImage(Image.open(launcherSplash).resize((700,400)))
        self.imageText = tkinter.Label(image=self.splashImage)
        self.imageText.pack()
        loadBar.step(25)
        if isANewDirectory:    
            fileHandler.openFiles()
        else:
            fileHandler.loadFiles()
        settings_wizard.NotebookPage.applySettings(main,currentoptext,loadBar)

        currentoplabel.destroy()
        loadBar.destroy()
        main.resizable(True,True)
        main.geometry("1366x720")
        isFullscreen = False
        
        # Iconography
        logo_icon = tkinter.PhotoImage(master = main,file = fileHandler.crumbl_logo)

        select_icon = tkinter.PhotoImage(master = main,file = fileHandler.select_asset)
        move_icon = tkinter.PhotoImage(master = main,file = fileHandler.move_asset)
        rotate_icon = tkinter.PhotoImage(master = main,file = fileHandler.rotate_asset)
        resize_icon = tkinter.PhotoImage(master = main,file = fileHandler.resize_asset)

        ruler_icon = tkinter.PhotoImage(master = main,file = fileHandler.ruler_asset)

        run_icon = tkinter.PhotoImage(master = main,file = fileHandler.run_asset)
        build_icon = tkinter.PhotoImage(master = main,file = fileHandler.build_asset)
                
        scene_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_scene_asset)
        layer_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_layer_asset)
        text_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_text_asset)
        button_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_button_asset)
        slider_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_slider_asset)
        entry_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_entry_asset)
        checkbutton_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_checkbutton_asset)
        radiobutton_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_rbutton_asset)
        object_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_object_asset)
        cbutton_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_cbutton_asset)
        switch_icon = tkinter.PhotoImage(master = main,file = fileHandler.new_switch_asset)

        # Set window icon
        main.iconphoto(True,logo_icon)

        # File/Edit/Help Menu

        menubar = tkinter.Menu(main)

        filemenu = tkinter.Menu(menubar, tearoff=0)
        filemenu.add_command(label="New project",command=self.generateNew)
        filemenu.add_command(label="Open project")
        filemenu.add_command(label="Save")
        filemenu.add_separator()
        filemenu.add_command(label="Configure Git")
        filemenu.add_command(label="Clone repo")
        filemenu.add_command(label="Push to repo")
        filemenu.add_separator()
        filemenu.add_command(label="Settings",command = lambda mod = "settings":app.runMod(mod))
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

        viewmenu = tkinter.Menu(menubar,tearoff=0)
        viewmenu.add_radiobutton(label="🗖 Tabbed (default)",command=app.max_win)
        viewmenu.add_radiobutton(label="🗗 Windowed",command=app.tabMiniWin)
        viewmenu.add_radiobutton(label="➚ Detached")
        viewmenu.add_separator()
        viewmenu.add_command(label="X Close current tab/window")
        viewmenu.add_separator()
        viewmenu.add_command(label="Fullscreen mode",command = app.fullscreen)
        menubar.add_cascade(label="View", menu=viewmenu)

        winmenu = tkinter.Menu(menubar, tearoff=0)
        winmenu.add_command(label="IDE",command = lambda mod = "ide":app.runMod(mod))
        winmenu.add_command(label="UI editor",command = lambda mod = "ui_editor":app.runMod(mod))
        winmenu.add_command(label="Asset preview",command = lambda mod = "asset_preview":app.runMod(mod))
        winmenu.add_separator()
        winmenu.add_command(label = "File viewer")
        winmenu.add_command(label = "Python console")
        winmenu.add_command(label = "Objects")
        menubar.add_cascade(label="Window", menu=winmenu)

        pluginmenu = tkinter.Menu(menubar, tearoff= 0)
        pluginmenu.add_command(label="No plugins installed...", state= "disabled")
        menubar.add_cascade(label="Plugins", menu= pluginmenu)

        helpmenu = tkinter.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="Documentation",command= lambda doc= "help/toc.crhd":start_page.NotebookPage.load_page(page = doc))
        helpmenu.add_command(label="About...",command = lambda mod = "about":app.runMod(mod))
        menubar.add_cascade(label="Help", menu=helpmenu)

        main.config(menu = menubar)

        # Menu ribbon
        ribbon_frame = tkinter.Frame(main)
        ribbon_frame.pack(side = "top", fill = "x", expand = 0)

        ribbon_tabs = ttk.Notebook(ribbon_frame)
        ribbon_tabs.pack(side = "top", fill = "x", expand = 0)

        # Ribbon menu
        
        start_ribbon = tkinter.Frame(ribbon_tabs)
        start_ribbon.pack(side = "top",fill = "x")
        ui_ribbon = tkinter.Frame(ribbon_tabs)
        ui_ribbon.pack(side = "top",fill = "x")
        debug_ribbon = tkinter.Frame(ribbon_tabs)
        debug_ribbon.pack(side = "top",fill = "x")
        compile_ribbon = tkinter.Frame(ribbon_tabs)
        compile_ribbon.pack(side = "top",fill = "x")

        # Ribbon tab definitions

        ribbon_tabs.add(start_ribbon,text = "Start")
        ribbon_tabs.add(ui_ribbon,text = "UI")
        ribbon_tabs.add(debug_ribbon,text = "Debug")
        ribbon_tabs.add(compile_ribbon,text = "Compile")

        # Add widgets to "start" ribbon

        quick_move_frames = ttk.Frame(start_ribbon)
        quick_move_frames.pack(side="left",padx=2,fill = "x")
        quick_select_button = ttk.Button(quick_move_frames,text="Select",image = select_icon,compound="top",
                                   style = "Accent.TButton",command=lambda x = 0:app.UIEditMoveModeChange(x))
        quick_select_button.pack(side = "left",anchor="n")
        quick_move_button = ttk.Button(quick_move_frames,text="Move",image = move_icon,compound="top",
                                command=lambda x = 1:app.UIEditMoveModeChange(x))
        quick_move_button.pack(side = "left",anchor="n")
        quick_rotate_button = ttk.Button(quick_move_frames,text="Rotate",image = rotate_icon,compound="top",
                                   command=lambda x = 2:app.UIEditMoveModeChange(x))
        quick_rotate_button.pack(side = "right",anchor="ne")
        quick_resize_button = ttk.Button(quick_move_frames,text="Resize",image = resize_icon,compound="top",
                                   command=lambda x = 3:app.UIEditMoveModeChange(x))
        quick_resize_button.pack(anchor="ne")
        quick_move_text = tkinter.Label(quick_move_frames,text="Transform")
        quick_move_text.pack(side = "bottom",anchor="s",expand=1)

        quick_frames = ttk.Frame(start_ribbon)
        quick_frames.pack(side="left",padx=2)
        run_button = ttk.Button(quick_frames,text = "Run",image= run_icon, compound= "top")
        run_button.pack(side = "left",anchor = "n")
        build_button = ttk.Button(quick_frames,text = "Build",image= build_icon, compound= "top")
        build_button.pack(anchor = "n")
        quick_text = tkinter.Label(quick_frames,text="Quick Build")
        quick_text.pack(side = "bottom",anchor="s",expand=1)

        # Add widgets to "UI" ribbon

        move_frames = ttk.Frame(ui_ribbon)
        move_frames.pack(side="left",padx=2,fill = "x")
        select_button = ttk.Button(move_frames,text="Select",image = select_icon,compound="top",
                                   style = "Accent.TButton",command=lambda x = 0:app.UIEditMoveModeChange(x))
        select_button.pack(side = "left",anchor="n")
        move_button = ttk.Button(move_frames,text="Move",image = move_icon,compound="top",
                                command=lambda x = 1:app.UIEditMoveModeChange(x))
        move_button.pack(side = "left",anchor="n")
        rotate_button = ttk.Button(move_frames,text="Rotate",image = rotate_icon,compound="top",
                                   command=lambda x = 2:app.UIEditMoveModeChange(x))
        rotate_button.pack(side = "right",anchor="ne")
        resize_button = ttk.Button(move_frames,text="Resize",image = resize_icon,compound="top",
                                   command=lambda x = 3:app.UIEditMoveModeChange(x))
        resize_button.pack(anchor="ne")
        move_text = tkinter.Label(move_frames,text="Transform")
        move_text.pack(side = "bottom",anchor="s",expand=1)

        tool_frames = ttk.Frame(ui_ribbon)
        tool_frames.pack(side="left",padx=2,fill = "x")
        ruler_button = ttk.Button(tool_frames,text="Ruler",image = ruler_icon,compound="top")
        ruler_button.pack(anchor="n")
        tool_text = tkinter.Label(tool_frames,text="Tools")
        tool_text.pack(side = "bottom",anchor="s",expand=1)

        layer_frames = ttk.Frame(ui_ribbon)
        layer_frames.pack(side="left",padx=2,fill = "x")
        scene_button = ttk.Button(layer_frames,text="New scene",image = scene_icon,compound="top")
        scene_button.pack(side = "left",anchor="n")
        layer_button = ttk.Button(layer_frames,text="New layer",image = layer_icon,compound="top")
        layer_button.pack()
        layer_text = tkinter.Label(layer_frames,text="Scene/Layer")
        layer_text.pack(side = "bottom",anchor="s",expand=1)

        object_frames = ttk.Frame(ui_ribbon)
        object_frames.pack(side="left",padx=2,fill = "x")
        text_button = ttk.Button(object_frames,text="Text",image = text_icon,compound="top")
        text_button.pack(side = "left",anchor="n")
        button_button = ttk.Button(object_frames,text="Button",image = button_icon,compound="top")
        button_button.pack(side = "left",anchor="n")
        slider_button = ttk.Button(object_frames,text="Slider",image = slider_icon,compound="top")
        slider_button.pack(side = "left",anchor="n")
        entry_button = ttk.Button(object_frames,text="Entry",image = entry_icon,compound="top")
        entry_button.pack(side = "right",anchor="ne")
        check_type_menu = tkinter.Menu(object_frames)
        object_button = ttk.Button(object_frames,text="Object",image = object_icon,compound="top")
        object_button.pack(side = "right",anchor="ne")
        check_button = ttk.Menubutton(object_frames,text="Checkbutton",image = checkbutton_icon,compound="top",menu=check_type_menu)
        check_button.pack(side = "right",anchor="ne")
        check_type_menu.add_command(label = "Checkbutton",image=cbutton_icon,compound="left")
        check_type_menu.add_command(label = "Switch",image=switch_icon,compound="left")
        radio_button = ttk.Button(object_frames,text="Radiobutton",image = radiobutton_icon,compound="top")
        radio_button.pack(anchor="ne")
        object_text = tkinter.Label(object_frames,text="Insert object")
        object_text.pack(side = "bottom",anchor="s",expand=1)

        option_frames = ttk.Frame(ui_ribbon)
        option_frames.pack(side="left",padx=2,fill = "x")
        show_rulers = ttk.Checkbutton(option_frames,text="Show border rulers")
        show_rulers.pack(anchor = "n")
        grid_snap = ttk.Checkbutton(option_frames,text="Snap to grid")
        grid_snap.pack(anchor = "n")
        use_max_friendly = ttk.Checkbutton(option_frames,text="Use variable-size friendly X/Y values")
        use_max_friendly.pack(anchor = "n")
        tool_text = tkinter.Label(option_frames,text="Options")
        tool_text.pack(side = "bottom",anchor="s",expand=1)
        grid_size_frame = ttk.Frame(ui_ribbon)
        grid_size_frame.pack(side="left",anchor="ne")
        grid_size_text = tkinter.Label(grid_size_frame,text = "Grid snap size (in px):")
        grid_size_text.pack()
        grid_size_select = ttk.Spinbox(grid_size_frame,from_ = 1,to = 100)
        grid_size_select.pack()

        vert_frame = ttk.PanedWindow(main, orient = tkinter.VERTICAL)
        vert_frame.pack(side = "top", fill = "both", expand = 1)
        main_frame = ttk.Panedwindow(vert_frame, orient = tkinter.HORIZONTAL)

        left_pane = tkinter.Frame(main_frame)
        
        right_pane = tkinter.Frame(main_frame)

        status_bar = ttk.Frame(main,relief="raised",borderwidth=1)
        status_bar.pack(side = "bottom", fill = "x", expand = 0)

        bottom_pane = tkinter.PanedWindow(vert_frame,orient=tkinter.VERTICAL)

        winModes = ttk.Frame(status_bar)
        winModes.pack(side="right")
        winModeDetached = ttk.Button(winModes,text = "➚")
        winModeDetached.pack(side="right")
        winModeSeperate = ttk.Button(winModes,text="🗗",command=app.tabMiniWin)
        winModeSeperate.pack(side="right")
        winModeTabbed = ttk.Button(winModes,style = "Accent.TButton",text = "🗖",command=app.max_win)
        winModeTabbed.pack(side="right")
        progress_stat = ttk.Progressbar(status_bar)
        progress_stat.pack(side = "right")
        stat_var = tkinter.StringVar(status_bar,"Ready")
        status_text = ttk.Label(status_bar,textvariable=stat_var)
        status_text.pack(side = "right")

        canvas_frame = tkinter.Frame(main_frame)
        canvas_frame.pack(fill = "both", expand = 1)
        mini_win_canvas = tkinter.Canvas(canvas_frame)
        close_bar = tkinter.Frame(canvas_frame)
        close_bar.pack(side = "top",fill = "x")

        main_frame.add(left_pane)
        main_frame.add(canvas_frame)
        main_frame.add(right_pane)
        vert_frame.add(main_frame)
        vert_frame.add(bottom_pane)

        close_button = ttk.Button(close_bar,text = "X",state='disabled',command=app.tabClose)
        close_button.pack(side = "right")
        restore_button = ttk.Button(close_bar,text = "🗗",command=app.tabMiniWin)
        restore_button.pack(side = "right")
        pop_button = ttk.Button(close_bar,text = "➚",state='disabled',command=app.tabDetach)
        pop_button.pack(side = "right")

        module_tabs = ttk.Notebook(canvas_frame)
        module_tabs.pack(fill = "both",expand=1)
        module_tabs.bind("<<NotebookTabChanged>>", app.windowTitleChange)

        nbPage = app.notebookAdd("Start Page")
        start_page.NotebookPage.start_page(nbPage,stat_var,progress_stat)

        main.mainloop()
        

    # Image compositing
    def compositeSplashScreen(splashScreen,title,author):
        splashImage = Image.open(fileHandler.projectSplash)
        title_font = ImageFont.truetype(fileHandler.defaultFont, 150)
        editedSplash = ImageDraw.Draw(splashImage)
        editedSplash.text([60,140],title,[255,255,255],title_font)
        return splashImage


    def fullscreen():
        global main
        global isFullscreen
        if not isFullscreen:
            main.attributes('-fullscreen',True)
            isFullscreen = True
        else:
            main.attributes('-fullscreen',False)
            isFullscreen = False

    def UIEditMoveModeChange(mode):
            global select_button
            global move_button
            global rotate_button
            global resize_button
            global quick_select_button
            global quick_move_button
            global quick_rotate_button
            global quick_resize_button
            if mode == 0:
                select_button.config(style = "Accent.TButton")
                move_button.config(style = "")
                rotate_button.config(style = "")
                resize_button.config(style = "")
                quick_select_button.config(style = "Accent.TButton")
                quick_move_button.config(style = "")
                quick_rotate_button.config(style = "")
                quick_resize_button.config(style = "")
            if mode == 1:
                select_button.config(style = "")
                move_button.config(style = "Accent.TButton")
                rotate_button.config(style = "")
                resize_button.config(style = "")
                quick_select_button.config(style = "")
                quick_move_button.config(style = "Accent.TButton")
                quick_rotate_button.config(style = "")
                quick_resize_button.config(style = "")
            if mode == 2:
                select_button.config(style = "")
                move_button.config(style = "")
                rotate_button.config(style = "Accent.TButton")
                resize_button.config(style = "")
                quick_select_button.config(style = "")
                quick_move_button.config(style = "")
                quick_rotate_button.config(style = "Accent.TButton")
                quick_resize_button.config(style = "")
            if mode == 3:
                select_button.config(style = "")
                move_button.config(style = "")
                rotate_button.config(style = "")
                resize_button.config(style = "Accent.TButton")
                quick_select_button.config(style = "")
                quick_move_button.config(style = "")
                quick_rotate_button.config(style = "")
                quick_resize_button.config(style = "Accent.TButton")

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
        if mod == "asset_preview":
            currentTab = app.notebookAdd("Asset Viewer",closeable = True,poppable = True)
            asset_preview.NotebookPage.start_page(currentTab,True)
        if mod == "settings":
            tab = app.notebookAdd("Settings",closeable=True)
            settings_wizard.NotebookPage.start_page(tab)
        if mod == "about":
            tab = app.notebookAdd("About",closeable=True)
            about.NotebookPage.start_page(tab)

    def windowTitleChange(event = None,title = None):
        global module_tabs
        if win_mode == "tabbed":
            tab_name = module_tabs.tab(module_tabs.select(),"text")
            main.winfo_toplevel().title(tab_name +" - Crumbl 2D Editor")
            tab_list = [module_tabs.tab(i, option="text") for i in module_tabs.tabs()]
            tab_no = tab_list.index(tab_name)
            print(tab_no)
            if module_tabs.closes[tab_no]:
                close_button.config(state = 'normal')
            else:
                close_button.config(state = 'disabled')
            if module_tabs.poppable[tab_no]:
                pop_button.config(state = 'normal')
            else:
                pop_button.config(state = 'disabled')
        if win_mode == "miniwindow":
            main.winfo_toplevel().title(title +" - Crumbl 2D Editor")

    def notebookAdd(title,renameable = False,closeable = False,poppable = False):
        global win_mode
        global module_tabs
        global canvas_frame
        if win_mode == "tabbed":
            try:
                module_tabs.notes.append(tkinter.Frame(canvas_frame))
                module_tabs.texts.append(title)
                module_tabs.renames.append(renameable)
                module_tabs.closes.append(closeable)
                module_tabs.poppable.append(poppable)
            except Exception:
                print("No module lists")
                module_tabs.notes = []
                module_tabs.texts = []
                module_tabs.closes = []
                module_tabs.poppable = []
                module_tabs.renames = []
                module_tabs.notes.append(tkinter.Frame(canvas_frame))
                module_tabs.texts.append(title)
                module_tabs.renames.append(renameable)
                module_tabs.closes.append(closeable)
                module_tabs.poppable.append(poppable)
            module_tabs.add(module_tabs.notes[-1],text = title)
            varName = module_tabs.notes[-1]
            print("Tab system: tab generated"+str(varName)+","+title)
            if poppable:
                close_button.config(state = 'normal')
            else:
                close_button.config(state = 'disabled')
            if poppable:
                pop_button.config(state = 'normal')
            else:
                pop_button.config(state = 'disabled')
            module_tabs.select(module_tabs.index(varName))
        if win_mode == "miniwindow":
            varName = app.generateMiniWin(0,0,640,320,title,closeable,poppable)
        return varName

    def tabClose():
        global module_tabs
        tab_name = module_tabs.tab(module_tabs.select(),"text")
        tab_list = [module_tabs.tab(i, option="text") for i in module_tabs.tabs()]
        tab_no = tab_list.index(tab_name)
        module_tabs.notes[tab_no].destroy()

    def tabDetach():
        global module_tabs
        global windowedTabs
        tab_name = module_tabs.tab(module_tabs.select(),"text")
        tab_list = [module_tabs.tab(i, option="text") for i in module_tabs.tabs()]
        tab_no = tab_list.index(tab_name)
        windowedTabs.append(seperatedWindow.seperatedWin())
        windowedTabs[-1].additems(tab_name,module_tabs.notes)

    def tabMiniWin():
        global module_tabs
        global close_bar
        global winModeDetached
        global winModeSeperate
        global winModeTabbed
        global win_mode
        tab_name = module_tabs.tab(module_tabs.select(),"text")
        tab_list = [module_tabs.tab(i, option="text") for i in module_tabs.tabs()]
        tab_no = tab_list.index(tab_name)
        module_tabs.pack_forget()
        close_bar.pack_forget()
        mini_win_canvas.pack(fill="both",expand=1)
        print("Canvas replaced")
        app.convert_tabs()
        winModeTabbed.config(style="TButton")
        winModeDetached.config(style="TButton")
        winModeSeperate.config(style="Accent.TButton")
        win_mode = "miniwindow"

    def generateMiniWin(x,y,sx,sy,title,closable = True,poppable = True):
        mini_wins.append(tkinter.Frame(mini_win_canvas,borderwidth=1))
        winFrame = mini_wins[-1]
        winFrame.dragging = False
        winFrame.winDrag = False
        winFrame.dragpos = [0,0]
        winFrame.winrResize = False
        winFrame.respos = [0,0]
        winFrame.color = [105,166,171]
        wins.append(mini_win_canvas.create_window(x,y,anchor=tkinter.NW,window=winFrame,width=sx,height=sy))
        winFrame.moveBar = tkinter.Frame(winFrame,cursor="fleur")
        hexCol = convertRGBcolor(winFrame.color[0],winFrame.color[1],winFrame.color[2])
        winFrame.moveBar.config(bg = hexCol)
        winFrame.moveBar.pack(side="top",fill= "x")
        winFrame.moveBar.bind("<Button-1>",lambda e,f = winFrame,t=title:app.dragClick(e,f,t))
        winFrame.moveBar.bind("<B1-Motion>",lambda e,f = winFrame,w = wins[-1]:app.dragOccuring(e,f,w))
        winFrame.moveBar.bind("<ButtonRelease-1>",lambda f = winFrame:app.dragStop(f))
        winFrame.customMenu = tkinter.Menu(winFrame.moveBar)
        winFrame.bind("<FocusIn>",lambda e,w = winFrame:app.focus(w,title))
        winFrame.bind("<Button-1>",lambda e,w = winFrame:app.focus(w,title))
        if closable:
            winFrame.customMenu.add_command(label="X Close",command=lambda w =winFrame:app.close_win(w))
        winFrame.customMenu.add_command(label="🗖 Maximize",command=app.max_win)
        winFrame.customMenu.add_command(label="🗕 Minimize")
        if poppable:
            winFrame.customMenu.add_command(label="➚ Pop out")
        winFrame.customMenu.add_separator()
        winFrame.customMenu.add_command(label="Change window color",command=lambda a = winFrame:app.setWinColor(a))
        winFrame.customBar = ttk.Menubutton(winFrame.moveBar,style="Accent.TButton",text = "▼",menu=winFrame.customMenu)
        winFrame.customBar.pack(side = "left")
        winFrame.winText = tkinter.Label(winFrame.moveBar,text = title,bg=hexCol)
        winFrame.winText.pack(side="left")
        if closable:
            winFrame.closebutton = ttk.Button(winFrame.moveBar,text = "X",command=lambda w =winFrame:app.close_win(w))
            winFrame.closebutton.pack(side = "right")
        winFrame.maximizebutton = ttk.Button(winFrame.moveBar,text = "🗖",command=app.max_win)
        winFrame.maximizebutton.pack(side = "right")
        winFrame.minimizebutton = ttk.Button(winFrame.moveBar,text = "🗕")
        winFrame.minimizebutton.pack(side = "right")
        if poppable:
            winFrame.closebutton = ttk.Button(winFrame.moveBar,text = "➚")
            winFrame.closebutton.pack(side = "right")
        winFrame.gripFrame = tkinter.Frame(winFrame)
        winFrame.gripFrame.pack(side = "bottom",fill = "x")
        winFrame.grip = tkinter.Label(winFrame.gripFrame, text = "◢",cursor="bottom_right_corner")
        winFrame.grip.pack(side="right")
        winFrame.grip.bind("<Button-1>",lambda e,f = winFrame,t=title:app.resizeClick(e,f,t))
        winFrame.grip.bind("<B1-Motion>",lambda e,f = winFrame,w = wins[-1]:app.resizeOccuring(e,f,w))
        winFrame.grip.bind("<ButtonRelease-1>",lambda f = winFrame:app.resizeStop(f))
        return winFrame
    
    def close_win(win):
        win.destroy()
        print("Window %s closed" %win)

    def max_win():
        global module_tabs
        global mini_win_canvas
        global mini_wins
        global wins
        global winFocus
        global win_mode
        global main
        mini_win_canvas.pack_forget()
        close_bar.pack(side = "top",fill = "x")
        module_tabs.pack(fill="both",expand = 1)
        win_mode = "tabbed"
        winModeTabbed.config(style="Accent.TButton")
        winModeDetached.config(style="TButton")
        winModeSeperate.config(style="TButton")
        for i in range(len(wins)):
            module_tabs.notes[i].pack_forget()
            newtab = app.notebookAdd(module_tabs.texts[i],module_tabs.renames[i])
            module_tabs.notes[i].pack(in_=newtab,fill = "both",expand = 1)
            print("Tab %s converted" %module_tabs.texts[i])

    def convert_tabs():
        global module_tabs
        global mini_win_canvas
        global mini_wins
        global wins
        global winFocus
        for i in range(len(module_tabs.notes)):
            print("tab %s added to list" %(str(module_tabs.notes[i])))
            cTitle = module_tabs.tab(module_tabs.notes[i],"text")
            winFrame = app.generateMiniWin(i*32,i*32,640,320,cTitle,module_tabs.closes[i],module_tabs.poppable[i])
            try:
                module_tabs.notes[i].pack_forget()
                module_tabs.notes[i].pack(in_=winFrame,fill = "both",expand = 1)
                module_tabs.notes[i].bind("<FocusIn>",lambda e,w = winFrame:app.focus(w,cTitle))
                module_tabs.notes[i].bind("<Button-1>",lambda e,w = winFrame:app.focus(w,cTitle))
            except Exception:
                print("copying to seperate windows failed")
        winFocus = winFrame

    def resizeClick(ev,frame):
        frame.resizing = True
        frame.respos = (ev.x_root, ev.y_root)
        print("Now resizing")

    def resizeOccuring(ev,frame,win):
        global mini_win_canvas
        dx = ev.x_root - frame.dragpos[0] - frame.respos[0]
        dy = ev.y_root - frame.dragpos[1] - frame.respos[1]
        mini_win_canvas.itemconfig(win,width = dx)
        mini_win_canvas.itemconfig(win,height = dy)

    def resizeStop(frame):
        frame.resizing = False
        print("Resizing stopped")

    def setWinColor(win):
        color = askcolor()
        print(color)
        win.moveBar.config(bg = color[1])
        win.winText.config(bg = color[1])
        win.color = color[1]

    def dragClick(ev,frame,title):
        frame.dragging = True
        frame.dragpos = (ev.x_root, ev.y_root)
        app.focus(frame,title)
        print("Now dragging")

    def dragOccuring(ev,frame,win):
        global mini_win_canvas
        dx = ev.x_root - frame.dragpos[0]
        dy = ev.y_root - frame.dragpos[1]
        mini_win_canvas.moveto(win,dx,dy)
        ## mini_win_canvas.itemconfig(win,Y = ev.y_root)

    def dragStop(frame):
        frame.dragging = False
        print("Drag stopped")

    def focus(win,title):
        global winFocus
        if not winFocus == win:
            try:
                c = winFocus.color
                c[0] += 32
                c[1] += 32
                c[2] += 32
                winFocus.color = c
                ac = convertRGBcolor(c[0],c[1],c[2])
                winFocus.moveBar.config(bg = ac)
                winFocus.moveText.config(bg = ac)
            except Exception:
                pass
            winFocus = win
            app.windowTitleChange(None,title)
            c = winFocus.color
            c[0] = int(c[0])
            c[1] = int(c[1])
            c[2] = int(c[2])
            c[0] -= 32
            c[1] -= 32
            c[2] -= 32
            winFocus.color = c
            winFocus.moveBar.config(bg = ac)
            winFocus.moveText.config(bg = ac)
            print("window %s focused"%win)

    def about(self):
        tab = self.notebookAdd("About",closeable=True)
        about.NotebookPage.start_page(tab)