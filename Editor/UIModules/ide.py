import tkinter
from tkinter import scrolledtext, ttk

class NotebookPage():
    def start_page(nbPage):
        idetext = scrolledtext.ScrolledText(nbPage)
        idetext.pack(fill = "both",expand=1)