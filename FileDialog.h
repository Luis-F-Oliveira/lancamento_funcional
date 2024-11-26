#pragma once
#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <string>

namespace LancamentoFuncional
{
	class FileDialog
	{
	protected:
		std::wstring path;

	public:
		FileDialog();
		std::wstring GetPath();
	};
}

#endif // FILEDIALOG_H
