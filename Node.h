#pragma once
#ifndef NODE
#define NODE

#include <string>

using namespace std;

namespace LancamentoFuncional
{
	class Node
	{
	public:
		string enrollment;
		string servant;
		string type_curriculum;
		string desc_curriculum;
		Node* next;
		Node(
			const string& enrollment, const string& servant,
			const string& type_curriculum, const string& desc_curriculum
		);
	};
}

#endif // NODE


