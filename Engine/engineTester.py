# Crumbl Engine test project
# Designed to test new functions
# Also can show how a basic game works

import engineMain

Engine = engineMain.Engine("Crumbl Engine test program",400,200)

input("Press enter to exit")
Engine.destroyWindow()

# while 1:                               # Commented out due to recursion error
#   Engine.updateCrumblTasks(mouse=False)