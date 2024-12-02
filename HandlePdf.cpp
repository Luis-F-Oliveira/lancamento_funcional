#include "HandlePdf.h"
#include <iostream>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <regex>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;
using namespace poppler;

namespace LancamentoFuncional
{
    HandlePdf::HandlePdf(string path)
    {
        SetConsoleOutputCP(CP_UTF8);

        try
        {
            document* doc = document::load_from_file(path);
            const int pagesNbr = doc->pages();
            cout << "N�mero de p�ginas: " << pagesNbr << endl;

            regex CurriculoRegex(R"(Tipo de Curr�culo:\s*(\d+)\s*-\s*([^-\n]+))");
            regex ServidorRegex(R"(Servidor:\s*(\d+\.\d+)\s*-\s*([^-\n]+))");
            smatch match;

            for (int i = 0; i < pagesNbr; i++)
            {
                string text = doc->create_page(i)->text().to_latin1().c_str();
                text = regex_replace(text, regex(R"(\r?\n)"), " ");

                // Combina todas as informa��es em um �nico vetor
                vector<pair<string, string>> curriculos;
                vector<pair<string, string>> servidores;

                // Extraindo Curr�culos
                auto curriculo_matches = sregex_iterator(text.begin(), text.end(), CurriculoRegex);
                for (auto it = curriculo_matches; it != sregex_iterator(); ++it)
                {
                    string tipo = (*it)[1].str();
                    string descricao = (*it)[2].str();
                    curriculos.emplace_back(tipo, descricao);
                }

                // Extraindo Servidores
                auto servidor_matches = sregex_iterator(text.begin(), text.end(), ServidorRegex);
                for (auto it = servidor_matches; it != sregex_iterator(); ++it)
                {
                    string numero = (*it)[1].str();
                    string nome = (*it)[2].str();
                    servidores.emplace_back(numero, nome);
                }

                // Combinar os Curr�culos e Servidores em ordem
                size_t max_items = max(curriculos.size(), servidores.size());
                for (size_t j = 0; j < max_items; ++j)
                {
                    cout << "-------------------------------" << endl;

                    if (j < curriculos.size())
                    {
                        cout << "Tipo de Curr�culo encontrado: " << curriculos[j].first << endl;
                        cout << "Descri��o do Curr�culo: " << curriculos[j].second << endl;
                    }
                    else
                    {
                        cout << "Tipo de Curr�culo: [N�o encontrado]" << endl;
                    }

                    if (j < servidores.size())
                    {
                        cout << "N�mero do Servidor: " << servidores[j].first << endl;
                        cout << "Nome do Servidor: " << servidores[j].second << endl;
                    }
                    else
                    {
                        cout << "Servidor: [N�o encontrado]" << endl;
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
