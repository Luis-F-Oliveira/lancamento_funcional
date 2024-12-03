#pragma once
#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

namespace LancamentoFuncional
{
	class LinkedList
	{
	private:
		Node* head;
	public:
		LinkedList() : head() {}
		void insert(const Node& node);
		void remove();
		void print();
		~LinkedList();
	};
}

#endif // LINKEDLIST
