# Crumbl Engine test project
# Designed to test new functions
# Also can show how a basic game works

import engineMain

Engine = engineMain.Engine("Crumbl Engine test program",1366,768,canResize=True,noDecoration=False)

while 1:                              
    Engine.UpdateCrumblTasks(mouse=False)