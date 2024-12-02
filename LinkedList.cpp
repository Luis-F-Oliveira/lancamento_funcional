#include "LinkedList.h"
#include <iostream>

using namespace std;

namespace LancamentoFuncional
{
	void LinkedList::insert(const Node& node)
	{
		Node* newNode = new Node(node);
		newNode->next = head;
		head = newNode;
	}

	void LinkedList::remove()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void LinkedList::print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << "Matr�cula: " << current->enrollment
				<< ", Servidor: " << current->servant
				<< ", Tipo de Curr�culo: " << current->type_curriculum
				<< ", Descri��o do Curr�culo: " << current->desc_curriculum << endl;
			current = current->next;
		}
	}

	LinkedList::~LinkedList()
	{
		while (head != nullptr)
		{
			remove();
		}
	}
}
