import PyPDF2
import re
from app.filedialog import FileDialog
from app.linkedlist import LinkedList
from app.node import Node

class App:
    def main(self):
        linked_list = LinkedList()
        file_dialog = FileDialog()
        file_path = file_dialog.open_file()

        with open(file_path, 'rb') as file:
            reader = PyPDF2.PdfReader(file)
            text = ''

            for page_num in range(len(reader.pages)):
                page = reader.pages[page_num]
                text += page.extract_text()

            text = re.sub(r"\r?\n", " ", text)

            curriculo_regex = re.compile(r"Tipo de Curr\u00edculo:\s*(\d+)\s*-\s*([^-\n]+)")
            servidor_regex = re.compile(r"Servidor:\s*(\d+\.\d+)\s*-\s*([^-\n]+)")

            curriculos = []
            servidores = []

            curriculo_matches = curriculo_regex.findall(text)
            for match in curriculo_matches:
                curriculos.append((match[0], match[1]))

            servidor_matches = servidor_regex.findall(text)
            for match in servidor_matches:
                servidores.append((match[0], match[1]))

            max_items = max(len(curriculos), len(servidores))
            for i in range(max_items):
                enrollment = servidores[i][0] if i < len(servidores) else "Nao encontrado"
                servant = servidores[i][1] if i < len(servidores) else "Nao encontrado"
                type_curriculum = curriculos[i][0] if i < len(curriculos) else "Nao encontrado"
                desc_curriculum = curriculos[i][1] if i < len(curriculos) else "Nao encontrado"
                
                node = Node(enrollment, servant, type_curriculum, desc_curriculum)
                linked_list.insert(node)

            linked_list.to_excel('dados.xlsx')

if __name__ == "__main__":
    app = App()
    app.main()
