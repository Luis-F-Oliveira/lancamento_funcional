#include "FileDialog.h"
#include "LinkedList.h"
#include <iostream>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <regex>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;
using namespace poppler;
using namespace LancamentoFuncional;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    FileDialog fileDialog;
    LinkedList linkedList;

    try
    {
        document* doc = document::load_from_file(fileDialog.GetStringPath());
        const int pagesNbr = doc->pages();

        regex CurriculoRegex(R"(Tipo de Currículo:\s*(\d+)\s*-\s*([^-\n]+))");
        regex ServidorRegex(R"(Servidor:\s*(\d+\.\d+)\s*-\s*([^-\n]+))");
        smatch match;

        for (int i = 0; i < pagesNbr; i++)
        {
            string text = doc->create_page(i)->text().to_latin1().c_str();
            text = regex_replace(text, regex(R"(\r?\n)"), " ");

            vector<pair<string, string>> curriculos;
            vector<pair<string, string>> servidores;

            auto curriculo_matches = sregex_iterator(text.begin(), text.end(), CurriculoRegex);
            for (auto it = curriculo_matches; it != sregex_iterator(); ++it)
            {
                string tipo = (*it)[1].str();
                string descricao = (*it)[2].str();
                curriculos.emplace_back(tipo, descricao);
            }

            auto servidor_matches = sregex_iterator(text.begin(), text.end(), ServidorRegex);
            for (auto it = servidor_matches; it != sregex_iterator(); ++it)
            {
                string numero = (*it)[1].str();
                string nome = (*it)[2].str();
                servidores.emplace_back(numero, nome);
            }

            size_t max_items = max(curriculos.size(), servidores.size());
            for (size_t j = 0; j < max_items; ++j)
            {
                string enrollment = (j < servidores.size()) ? servidores[j].first : "Não encontrado";
                string servant = (j < servidores.size()) ? servidores[j].second : "Não encontrado";
                string type_curriculum = (j < curriculos.size()) ? curriculos[j].first : "Não encontrado";
                string desc_curriculum = (j < curriculos.size()) ? curriculos[j].second : "Não encontrado";

                linkedList.insert(Node(enrollment, servant, type_curriculum, desc_curriculum));
            }
        }

        linkedList.print();
    }
    catch (const exception& e)
    {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
