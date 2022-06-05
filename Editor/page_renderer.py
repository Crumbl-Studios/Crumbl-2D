# Custom markup reader/interpreter
# It is slightly messy, and recycled from other projects

from pickle import GLOBAL
import tkinter
from tkinter import ttk
from PIL import ImageTk,Image
import os
import webbrowser

maintext: tkinter.Frame
refresh: ttk.Button
back: ttk.Button
loadbar: ttk.Progressbar
currentop: tkinter.StringVar
currentpage: tkinter.StringVar
currenthelpdir:tkinter.StringVar
app: tkinter.Tk

searchFrame = None
cancel = 0
finalimage = []
finallimage = []
errorcon = "nil"
linesrendered = 0
linecount = 1

cwd = os.getcwd()
page_dir = os.path.join(cwd, "Editor/docs")
home_page = os.path.join(page_dir, "home.crhd")

def set_tkVars(maintextNew,refreshNew,backNew,loadbarNew,appNew,currentopNew,currentpageNew,currenthepldirNew):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global currentpage
    global currenthelpdir
    global app
    maintext = maintextNew
    refresh = refreshNew
    back = backNew
    loadbar = loadbarNew
    app = appNew
    currentop = currentopNew
    currentpage = currentpageNew
    currenthelpdir = currenthepldirNew

def loadpage(helpdi):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global currentpage
    global currentpages
    global currenthelpdir
    global app
    global finalimg
    global finallimg
    global linesrendered
    global linecount
    global page_dir
    global searchframe
    cancel = 1
    try:
        maintext.pack(fill = "both",expand = 1)
        searchframe.pack_forget()
    except Exception:
        pass
    currentop.set("loading page "+str(helpdi))
    currentpage.set(str(helpdi).rstrip("\n"))
    currenthelpdir.set(helpdi)
    app.configure(cursor = "watch")
    maintext.configure(state="normal")
    maintext.delete(1.0, tkinter.END)
    loads = loadbar
    loads.pack(fill = "x")
    END = tkinter.INSERT
    refresh.config(text = "X")
    refresh.config(command = stop)
    try:
        currentpages = os.path.join(page_dir,helpdi)
        print("Page renderer: opening page "+currentpages)
        helpdoc = open(currentpages,mode = "r")
        linesrendered = 0
        linecount = len(open(currentpages).readlines())
        isinfile = True
    except Exception:
        errorcon = currentpages+" is not a real place"
        helpdoc = open(cwd+"/Editor/docs/errors/error.crhd",mode = "r")
        isinfile = True
        currentop.set("An error occured")
    for i in range(linecount):
        line = helpdoc.readline()
        Linepercent = linesrendered/linecount
        loads['value'] = Linepercent*100
        app.update()
        if line == "=!@TITLE\n":
            fulltitle = helpdoc.readline()
            currentpage.set(fulltitle.rstrip("\n"))
            linesrendered += 2
            currentop.set("Inserting title ("+str(round(Linepercent*100))+"%)")
            maintext.insert(END,fulltitle,"title")
            app.update()
        elif line == "=!@SUBTITLE\n":
            linesrendered += 2
            maintext.insert(END,helpdoc.readline(),"subtitle")
            app.update()
        elif line == "=!@LINK\n":
            linktext = helpdoc.readline().rstrip("\n")
            currentop.set("text: "+linktext)
            link = helpdoc.readline().rstrip("\n")
            linklo = link
            currentop.set("location:" +link + "("+str(Linepercent*100)+"%)")
            maintext.tag_add(link,END)
            maintext.tag_config(link,foreground="blue",underline = 1)
            maintext.tag_bind(link,"<Enter>",lambda e,linkloc = linklo: enter(linkloc))
            maintext.tag_bind(link,"<Leave>",lambda e,linkloc = linklo: leave(linkloc))
            maintext.tag_bind(link,"<Button-1>",lambda e,linkloc = linklo: click(linkloc))
            maintext.insert(END,linktext,link)
            linesrendered += 2
            app.update()
        elif line == "=!@IMAGE\n":
            image = helpdoc.readline().rstrip("\n")
            currentop.set("img:" +image)
            try:
                img=Image.open(cwd+"/home"+image)
                finalimg.append(ImageTk.PhotoImage(img))
                maintext.image_create(END,image= finalimg[-1])
                maintext.insert(END,"\n")
                currentop.set("Image " + image +" loaded successfully ("+str(round(Linepercent*100))+"%)")
                linesrendered += 2
                app.update()
            except Exception:
                currentop.set("Image "+ image +" not found ("+str(round(Linepercent*100))+"%)")
                maintext.insert(END,"(Image not found [ERROR 05])")
                linesrendered += 2
                app.update()
        elif line == "=!@LINKIMAGE\n":
            image = helpdoc.readline().rstrip("\n")
            currentop.set("img:" +image)
            try:
                linkforimg =""
                img=Image.open(cwd+"/home"+image)
                link = helpdoc.readline().rstrip("\n")
                finallimg.append(ImageTk.PhotoImage(img))
                maintext.image_create(END,image= finallimg[-1])
                maintext.tag_add(link,"{0}-1 char".format(END),END)
                maintext.tag_bind(link,"<Enter>",lambda e,linkforimg= link: imgenter(linkforimg))
                maintext.tag_bind(link,"<Leave>",imgleave)
                maintext.tag_bind(link,"<Button-1>",lambda e,linkforimg= link: click(linkforimg))
                maintext.insert(END,"\n")
                currentop.set("Image " + image +" loaded successfully ("+str(round(Linepercent*100))+"%)")
                linesrendered += 2
                app.update()
            except Exception:
                currentop.set("Image "+ image +" not found ("+str(round(Linepercent*100))+"%)")
                maintext.insert(END,"(Image not found [ERROR 05])",)
                linesrendered += 2
                app.update()
        elif line == "=!@WEBLINK\n":
            linktext = helpdoc.readline().rstrip("\n")
            currentop.set("text: "+linktext)
            link = helpdoc.readline().rstrip("\n")
            linklo = link
            currentop.set("location:" +link + "("+str(Linepercent*100)+"%)")
            maintext.tag_add(link,END)
            maintext.tag_config(link,foreground="blue",underline = 1)
            maintext.tag_bind(link,"<Enter>",lambda e,linkloc = linklo: enter(linkloc,True))
            maintext.tag_bind(link,"<Leave>",lambda e,linkloc = linklo: leave(linkloc))
            maintext.tag_bind(link,"<Button-1>",lambda e,linkloc = linklo: webclick(linkloc))
            maintext.insert(END,"%s➚"%linktext,link)
            linesrendered += 2
        elif line == "=!@ERRCON\n":
            maintext.insert(END,errorcon,"normal")
            linesrendered += 1
            app.update()
        elif line == "=!@ITALIC\n":
            nextline = helpdoc.readline().rstrip("\n")
            currentop.set("placing italic text:"+nextline +" ("+str(round(Linepercent*100))+"%)")
            maintext.insert(END,nextline,"italic")
            linesrendered += 2
            app.update()
        elif line == "=!@BOLD\n":
            nextline = helpdoc.readline().rstrip("\n")
            currentop.set("placing italic text:"+nextline + " ("+str(round(Linepercent*100))+"%)")
            maintext.insert(END,nextline,"bold")
            linesrendered += 2
            app.update()
        elif line == "=!@CODE\n":
            nextline = helpdoc.readline().rstrip("\n")
            currentop.set("placing italic text:"+nextline + " ("+str(round(Linepercent*100))+"%)")
            maintext.insert(END,nextline,"code")
            linesrendered += 2
            app.update()
        elif line == "=!@EOF" or line == "=!@EOF\n" or line == "=!@EOF \eof" or line == "\n=!@EOF" or not line:
            currentop.set("End detected ("+str(round(Linepercent*100))+"%)")
            isinfile = False
            app.update()
            currentop.set("Ready")
            break
        elif not line == "=!@TITLE" or line == "=!@LINK" or line == "=!@IMAGE" or line == "=!@FIELD" or line == "=!@EOF"or line == "=!@EOF\n" or line == "=!@EOF \eof" or line == "\n=!@EOF":
            currentop.set("placing text ("+str(round(Linepercent*100))+"%)")
            maintext.insert(END,line.rstrip("=!@TITLE"),"normal")
            linesrendered += 1
            app.update()
        else:
            print("Invalid command or text ran out")
            app.update()
    maintext.config(state = "disabled")
    app.configure(cursor = "")
    refresh.config(text = "↺")
    refresh.config(command = lambda helpdir = None: reload(helpdir))
    loads["value"] = 100
    cancel = 0

def handle(obj):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global currentpage
    global locations
    global titles
    global tabs
    global lastdir
    global helpdir
    sel = tabs.selection()[0]
    select = tabs.item(sel,str("text"))
    title = select.replace(" ","_")
    itemno = titles.index(title)
    loc = locations[itemno]
    lastdir = loc
    helpdir = loc
    loadpage(loc)

def enter(place,external = False): # Show warning if enteing links to external website
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global app
    maintext.config(cursor = "hand2")
    maintext.tag_config(place,foreground="magenta",underline = 0)
    app.update()
    if not external:
        currentop.set("Link to: "+str(place)+" (click to navigate)")
    else:
        currentop.set("External link to: "+str(place)+" (click to navigate, this will take you outside the Crumbl Engine Editor)")

def leave(place):
    maintext.config(cursor = "xterm")
    maintext.tag_config(place,foreground="blue",underline = 1)
    app.update()
    currentop.set("Ready")

def imgenter(e):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global app
    maintext.config(cursor = "hand2")
    currentop.set("Image contains a link to: "+str(e)+" (click to navigate)")

def imgleave(e):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global app
    maintext.config(cursor = "xterm")
    currentop.set("Ready")

def click(link):
    global errorcon
    global page_dir
    helpdir = page_dir+link # This somehow didnt work with os.path.join()
    currentop.set("GOING TO PAGE: "+str(helpdir))
    currentop.set(helpdir)
    errorcon = "no errors found"
    loadpage(helpdir)

def webclick(link):
    global errorcon
    global page_dir
    helpdir = page_dir+link # This somehow didnt work with os.path.join()
    currentop.set("GOING TO PAGE: "+str(helpdir))
    webbrowser.open(link)
    errorcon = "no errors found"

def stop(helpdir):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global app
    global currentpage
    global loads
    global isinfile
    isinfile = False
    app.update()
    currentop.set("Ready (rendering prematurely stopped, full page not shown)")
    loads.destroy()
    loadbar.pack_forget()
    maintext.config(state = "disabled")
    app.configure(cursor = "")
    refresh.config(text = "↺")
    refresh.config(command = lambda helpdir,maintext,refresh,back,loadbar,app,currentop,
    searchframe = None: reload(helpdir,maintext,refresh,back,loadbar,app,currentop,searchframe = None))

def reload(helpdir):
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global currentpage
    global app
    loadpage(helpdir)

def home():
    global maintext
    global refresh
    global back
    global loadbar
    global currentop
    global currentpage
    global app
    loadpage(home_page)

