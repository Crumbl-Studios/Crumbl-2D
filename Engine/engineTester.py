# Crumbl Engine test project
# Changes background color to run through RGB sequence
# Designed to test new functions
# Also can show how a basic game works

import engineMain
import os

# Width and height
w = 1366
h = 768
# Generate window
Engine = engineMain.Engine("Crumbl Engine test program",w,h)
# Generate default font
defaultFont = Engine.loadFont(os.path.join(os.getcwd(),"build","stockAssets","SourceSansPro-Regular.ttf"),12)
# Logo image
logo = Engine.loadImage("stockAssets/build/CrumblLogo.png")

r = 0
g = 0
b = 255
colorchange = 0

Engine.changeBG(r,g,b)
while 1:
    # Engine.UpdateFrameStartTasks()
    if not r == 255 and colorchange == 0:
        b -= 1
        r += 1
    if r == 255:
        colorchange += 1
    if not g == 255 and colorchange == 1:
        r -= 1
        g += 1
    if g == 255:
        colorchange += 1
    if not b == 255 and colorchange == 2:
        g -= 1
        b += 1
    if b == 255:
        colorchange = 0
    Engine.changeBG(r,g,b)
    Engine.blit(logo,None,Engine.surface,0,0)
    Engine.uiRenderText("RGB TEST",w/2,h/2,defaultFont)
    Engine.UpdateCrumblTasks(mouse = True,framelimit = 60)