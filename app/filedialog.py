from tkinter import filedialog

class FileDialog:
    def open_file(self):
        file = filedialog.askopenfilename(
            title="Selecione um arquivo PDF",
            filetypes=[("Arquivos PDF", "*.pdf")]
        )

        return file