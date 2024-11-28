#pragma once
#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <string>

using namespace std;

namespace LancamentoFuncional
{
	class FileDialog
	{
	protected:
		wstring path;

	public:
		FileDialog();
		wstring GetWstringPath();
		string GetStringPath();
	};
}

#endif // FILEDIALOG_H
