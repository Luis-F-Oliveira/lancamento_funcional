#include "FileDialog.h"
#include <windows.h>
#include <commdlg.h>

using namespace std;

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

	wstring FileDialog::GetWstringPath()
	{
		return this->path;
	}

	string FileDialog::GetStringPath()
	{
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, this->path.c_str(), (int)this->path.length(), nullptr, 0, nullptr, nullptr);
		string strTo(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, this->path.c_str(), (int)this->path.length(), &strTo[0], size_needed, nullptr, nullptr);
		return strTo;
	}
}

