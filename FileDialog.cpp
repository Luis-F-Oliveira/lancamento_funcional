#include "FileDialog.h"
#include <windows.h>
#include <commdlg.h>

namespace LancamentoFuncional
{
	FileDialog::FileDialog()
	{
		OPENFILENAMEW ofn;
		wchar_t szFile[260] = { 0 };

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = nullptr;
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
		ofn.lpstrFilter = L"Arquivos PDF\0*.PDF\0"; // Filtra apenas arquivos PDF
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = nullptr;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = nullptr;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameW(&ofn) == TRUE) {
			path = ofn.lpstrFile;
		}
	}

	std::wstring FileDialog::GetPath()
	{
		return this->path;
	}
}
