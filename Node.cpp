#include "Node.h"
#include <windows.h>

using namespace std;

namespace LancamentoFuncional
{
	Node::Node(
		const string& enrollment, const string& servant,
		const string& type_curriculum, const string& desc_curriculum
	)
	{
		this->enrollment = enrollment;
		this->servant = servant;
		this->type_curriculum = type_curriculum;
		this->desc_curriculum = desc_curriculum;
		this->next = nullptr;
	}
}
