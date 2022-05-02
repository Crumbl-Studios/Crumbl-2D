import tkinter
from tkinter import scrolledtext, ttk

class NotebookPage():
    def start_page(nbPage):
        edit = tkinter.Canvas(nbPage)
        edit.pack(fill = 'both',expand=1)