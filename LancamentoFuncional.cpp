#include "FileDialog.h"
#include "HandlePdf.h"

using namespace LancamentoFuncional;

int main()
{
    FileDialog fileDialog;

    HandlePdf handlePDF(fileDialog.GetStringPath());

    return 0;
}
