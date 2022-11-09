# Load icons from UIAssets
import tkinter
import os
import platform

# FileHandler locations
raw = os.path.join(os.getcwd(),"Editor")
IconDir = os.path.join(raw,"UIAssets")

# Logos
crumbl_logo = os.path.join(IconDir,"favicon.png")
engine_logo = os.path.join(IconDir,"logo.png")
studio_logo = os.path.join(IconDir,"corp_logo.png")

# Ribbon icons
run_asset = os.path.join(IconDir,"run.png")
build_asset = os.path.join(IconDir,"build.png")

select_asset = os.path.join(IconDir,"select.png")
move_asset = os.path.join(IconDir,"move.png")
rotate_asset = os.path.join(IconDir,"rotate.png")
resize_asset = os.path.join(IconDir,"resize.png")

ruler_asset = os.path.join(IconDir,"ruler.png")

new_layer_asset = os.path.join(IconDir,"newlayer.png")
new_scene_asset = os.path.join(IconDir,"newscene.png")

new_text_asset = os.path.join(IconDir,"newtext.png")
new_button_asset = os.path.join(IconDir,"newbutton.png")
new_slider_asset = os.path.join(IconDir,"newSlider.png")
new_entry_asset = os.path.join(IconDir,"newEntry.png")
new_checkbutton_asset = os.path.join(IconDir,"newCheckbutton.png")
new_rbutton_asset = os.path.join(IconDir,"newRadioButton.png")
new_dropdown_asset = os.path.join(IconDir,"newDropdown.png")
new_object_asset = os.path.join(IconDir,"newObject.png")
new_cbutton_asset = os.path.join(IconDir,"checkbutton.png")
new_switch_asset = os.path.join(IconDir,"switch.png")

# Settings icons
sv_dark_asset = os.path.join(IconDir,"SVDarkMode.png")
sv_light_asset = os.path.join(IconDir,"SVLightMode.png")
forest_dark_asset = os.path.join(IconDir,"ForestDarkMode.png")
forest_light_asset = os.path.join(IconDir,"ForestLightMode.png")
tk_dark_asset = os.path.join(IconDir,"tkDarkMode.png")
tk_light_asset = os.path.join(IconDir,"tkLightMode.png")
changeImage = os.path.join(IconDir,"changedsetting.png")

# Splash screen assets
launcherSplash = os.path.join(IconDir,"normalSplash.png")
projectSplash = os.path.join(IconDir,"projectSplash.png")

# Launcher assets
new_project_asset = os.path.join(IconDir,"newProject.png")
open_project_asset = os.path.join(IconDir,"open.png")
git_clone_asset = os.path.join(IconDir,"git.png")
settings_asset = os.path.join(IconDir,"settings.png")

def get_save_loc():
    userOS = platform.system()
    usrHome = os.path.expanduser("~")
    if userOS == "Windows":
        location = os.path.join(usrHome,"AppData/Roaming/CrumblStudios/crumblEngine")
        try:
            os.mkdir(os.path.join(usrHome,"AppData/Roaming/CrumblStudios/"))
        except FileExistsError:
            pass
    else:
        location = os.path.join(usrHome,".crumblEngine")