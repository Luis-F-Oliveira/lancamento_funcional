#include <iostream>
#include "FileDialog.h"

int main()
{
    LancamentoFuncional::FileDialog fileDialog;
    std::wcout << L"Caminho do arquivo selecionado: " << fileDialog.GetPath() << std::endl;

    return 0;
}
