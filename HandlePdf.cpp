#include "HandlePdf.h"
#include <iostream>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <regex>

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32


using namespace std;
using namespace poppler;

namespace LancamentoFuncional
{
    HandlePdf::HandlePdf(string path)
    {
        #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        #endif // _WIN32

        try
        {
            document* doc = document::load_from_file(path);
            const int pagesNbr = doc->pages();
            cout << "N�mero de p�ginas: " << pagesNbr << endl;

            regex CurriculoRegex(R"(Tipo de Curr�culo:\s*(\d+)\s*-\s*([^-\n]+))");
            smatch match;

            for (int i = 0; i < pagesNbr; i++)
            {
                string text = doc->create_page(i)->text().to_latin1().c_str();

                auto matches_begin = sregex_iterator(text.begin(), text.end(), CurriculoRegex);
                auto matches_end = sregex_iterator();

                if (matches_begin == matches_end)
                {
                    cerr << "N�o funcionei na p�gina " << i + 1 << endl;
                }
                else
                {
                    for (auto it = matches_begin; it != matches_end; ++it)
                    {
                        wstring tipoCurriculo = wstring(it->str(1).begin(), it->str(1).end());
                        wstring descricaoCurriculo = wstring(it->str(2).begin(), it->str(2).end());

                        wcout << L"Tipo de Curr�culo encontrado: " << tipoCurriculo << endl;
                        wcout << L"Descri��o do Curr�culo: " << descricaoCurriculo << endl;
                    }
                }
            }
        }
        catch (const exception& e)
        {
            cerr << "Erro: " << e.what() << endl;
        }
    }
}
