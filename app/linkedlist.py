import pandas as pd
from app.node import Node

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, node):
        new_node = Node(
            node.enrollment, 
            node.servant, 
            node.type_curriculum, 
            node.desc_curriculum    
        )
        new_node.next = self.head
        self.head = new_node

    def remove(self):
        if self.head is not None:
            temp = self.head
            self.head = self.head.next
            del temp

    def print_list(self):
        current = self.head
        while current is not Node:
            print(f"Matricula: {current.enrollment}, Servidor: {current.servant}, Tipo de Curriculo: {current.type_curriculum}, Descricao do Curriculo: {current.desc_curriculum}")
            current = current.next

    def __del__(self):
        while self.head is not None:
            self.remove()

    def to_excel(self, filename: str):
        data = []
        current = self.head
        while current:
            data.append({
                "Matricula": current.enrollment,
                "Servidor": current.servant,
                "Tipo - Curriculo": current.type_curriculum,
                "Descricao - Curriculo": current.desc_curriculum
            })
            current = current.next

        df = pd.DataFrame(data)

        df.to_excel(filename, index=False)