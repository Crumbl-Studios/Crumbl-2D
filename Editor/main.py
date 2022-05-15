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
import UIModules.asset_preview as asset_preview
import seperatedWindow
from tkinter.colorchooser import askcolor

# Wizard UI imports
import UIModules.settings_wizard as settings_wizard

def convertRGBcolor(r,g,b):
    return "#%02x%02x%02x" %(r,g,b)

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

        wins = []
        mini_wins = []
        windowedTabs = []
        tabMode = 0
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

        viewmenu = tkinter.Menu(menubar,tearoff=0)
        viewmenu.add_radiobutton(label="🗖 Tabbed (default)")
        viewmenu.add_radiobutton(label="🗗 Windowed")
        viewmenu.add_radiobutton(label="➚ Detached")
        viewmenu.add_separator()
        viewmenu.add_command(label="X Close current tab/window")
        menubar.add_cascade(label="View", menu=viewmenu)

        winmenu = tkinter.Menu(menubar, tearoff=0)
        winmenu.add_command(label="IDE",command = lambda mod = "ide":app.runMod(mod))
        winmenu.add_command(label="UI editor",command = lambda mod = "ui_editor":app.runMod(mod))
        winmenu.add_command(label="Asset preview",command = lambda mod = "asset_preview":app.runMod(mod))
        winmenu.add_separator()
        winmenu.add_command(label = "Asset viewer")
        winmenu.add_command(label = "Python console")
        winmenu.add_command(label = "Objects")
        menubar.add_cascade(label="Window", menu=winmenu)

        pluginmenu = tkinter.Menu(menubar, tearoff= 0)
        pluginmenu.add_command(label="No plugins installed...", state= "disabled")
        menubar.add_cascade(label="Plugins", menu= pluginmenu)

        helpmenu = tkinter.Menu(menubar, tearoff=0)
        helpmenu.add_command(label="Documentation",command= lambda doc= "help/toc.crhd":start_page.NotebookPage.load_page(page = doc))
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
        winModeSeperate = ttk.Button(winModes,text="🗗")
        winModeSeperate.pack(side="right")
        winModeTabbed = ttk.Button(winModes,style = "Accent.TButton",text = "🗖")
        winModeTabbed.pack(side="right")
        progress_stat = ttk.Progressbar(status_bar)
        progress_stat.pack(side = "right")
        status_text = ttk.Label(status_bar,text = "Ready")
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
        if mod == "asset_preview":
            currentTab = app.notebookAdd("Asset Viewer",closeable = True,poppable = True)
            asset_preview.NotebookPage.start_page(currentTab,True)

    def windowTitleChange(event):
        global module_tabs
        tab_name = module_tabs.tab(module_tabs.select(),"text")
        main.winfo_toplevel().title(tab_name +" - Crumbl Engine Editor")
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

    def notebookAdd(title,renameable = False,closeable = False,poppable = False):
            global module_tabs
            global canvas_frame
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

    def convert_tabs():
        global module_tabs
        global mini_win_canvas
        global mini_wins
        global wins
        winFocus : tkinter.Frame
        for i in range(len(module_tabs.notes)):
            mini_wins.append(tkinter.Frame(mini_win_canvas))
            print("tab %s added to list" %(str(module_tabs.notes[i])))
            winFrame = mini_wins[-1]
            winFrame.dragging = False
            winFrame.winDrag = False
            winFrame.dragpos = [0,0]
            winFrame.winrResize = False
            winFrame.respos = [0,0]
            winFrame.color = [83,134,139]
            wins.append(mini_win_canvas.create_window(i*32,i*32,anchor=tkinter.NW,window=winFrame,width=640,height=320))
            winFrame.moveBar = tkinter.Frame(winFrame,cursor="fleur")
            hexCol = convertRGBcolor(winFrame.color[0],winFrame.color[1],winFrame.color[2])
            winFrame.moveBar.config(bg = hexCol)
            winFrame.moveBar.pack(side="top",fill= "x")
            winFrame.moveBar.bind("<Button-1>",lambda e,f = winFrame:dragClick(e,f))
            winFrame.moveBar.bind("<B1-Motion>",lambda e,f = winFrame,w = wins[-1]:dragOccuring(e,f,w))
            winFrame.moveBar.bind("<ButtonRelease-1>",lambda f = winFrame:dragStop(f))
            winFrame.customMenu = tkinter.Menu(winFrame.moveBar)
            if module_tabs.closes[i]:
                winFrame.customMenu.add_command(label="X Close")
            winFrame.customMenu.add_command(label="🗖 Maximize")
            winFrame.customMenu.add_command(label="🗕 Minimize")
            if module_tabs.poppable[i]:
                winFrame.customMenu.add_command(label="➚ Pop out")
            winFrame.customMenu.add_separator()
            winFrame.customMenu.add_command(label="Change window color",command=lambda a = winFrame:setWinColor(a))
            winFrame.customBar = ttk.Menubutton(winFrame.moveBar,style="Accent.TButton",text = "▼",menu=winFrame.customMenu)
            winFrame.customBar.pack(side = "left")
            winFrame.winText = tkinter.Label(winFrame.moveBar,text = module_tabs.tab(i,"text"),bg="CadetBlue4")
            winFrame.winText.pack(side="left")
            if module_tabs.closes[i]:
                winFrame.closebutton = ttk.Button(winFrame.moveBar,text = "X")
                winFrame.closebutton.pack(side = "right")
            winFrame.maximizebutton = ttk.Button(winFrame.moveBar,text = "🗖")
            winFrame.maximizebutton.pack(side = "right")
            winFrame.minimizebutton = ttk.Button(winFrame.moveBar,text = "🗕")
            winFrame.minimizebutton.pack(side = "right")
            if module_tabs.poppable[i]:
                winFrame.closebutton = ttk.Button(winFrame.moveBar,text = "➚")
                winFrame.closebutton.pack(side = "right")
            winFrame.gripFrame = tkinter.Frame(winFrame)
            winFrame.gripFrame.pack(side = "bottom",fill = "x")
            winFrame.grip = tkinter.Label(winFrame.gripFrame, text = "◢",cursor="bottom_right_corner")
            winFrame.grip.pack(side="right")
            winFrame.grip.bind("<Button-1>",lambda e,f = winFrame:resizeClick(e,f))
            winFrame.grip.bind("<B1-Motion>",lambda e,f = winFrame,w = wins[-1]:resizeOccuring(e,f,w))
            winFrame.grip.bind("<ButtonRelease-1>",lambda f = winFrame:resizeStop(f))
            try:
                module_tabs.notes[i].pack_forget()
                module_tabs.notes[i].pack(in_=winFrame,fill = "both",expand = 1)
            except Exception:
                print("copying to seperate windows failed")
        def resizeClick(ev,frame):
            frame.resizing = True
            frame.respos = (ev.x_root, ev.y_root)
            print("Now resizing")
        def resizeOccuring(ev,frame,win):
            global mini_win_canvas
            dx = ev.x_root - frame.respos[0]
            dy = ev.y_root - frame.respos[1]
            mini_win_canvas.itemconfig(win,width = ev.x_root)
            mini_win_canvas.itemconfig(win,height = ev.y_root)
        def resizeStop(frame):
            frame.resizing = False
            print("Resizing stopped")
        def setWinColor(win):
            color = askcolor()
            print(color)
            win.moveBar.config(bg = color[1])
            win.winText.config(bg = color[1])
            win.color = color[1]
        def dragClick(ev,frame):
            frame.dragging = True
            frame.dragpos = (ev.x_root, ev.y_root)
            print("Now dragging")
        def dragOccuring(ev,frame,win):
            global mini_win_canvas
            dx = ev.x_root - frame.dragpos[0]
            dy = ev.y_root - frame.dragpos[1]
            mini_win_canvas.itemconfig(win,anchor = (ev.x_root,ev.y_root))
            ## mini_win_canvas.itemconfig(win,Y = ev.y_root)
        def dragStop(frame):
            frame.dragging = False
            print("Drag stopped")
        def focus(win):
            global winFocus
            winFocus = win
            print("window %s focused"%win)
engine = app()