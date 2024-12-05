class Node:
    def __init__(self, enrollment, servant, type_curriculum, desc_curriculum):
        self.enrollment = enrollment
        self.servant = servant
        self.type_curriculum = type_curriculum
        self.desc_curriculum = desc_curriculum
        self.next = None