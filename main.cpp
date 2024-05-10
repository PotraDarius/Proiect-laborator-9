#include "repository.h"
#include "service.h"
#include "ui.h"
#include "teste_domain.h"
#include "teste_repository.h"
#include "teste_service.h"
#include "teste_validator.h"
#include <iostream>

using std::cout;
using std::cin;

void test_all(){
    teste_domain();
    teste_repo();
    test_validare_oferta();
    teste_service();
    teste_vector_dinamic();
}



int main() {
    test_all();
        cout << "Salvare in fisier , memorie sau in memorie cu probabilitati? \n";
        cout << "1.Memorie\n";
        cout << "2.Fisier\n";
        cout << "3.Memorie cu probabilitati\n";
        cout << "Optiunea: ";
        int opt;
        cin >> opt;
        switch (opt) {
            case 1:{
                Repo r;
                Service s{r};
                UI ui{s};
                ui.run();
                break;}
            case 2: {
                RepoFisier r{"database.txt"};
                Service s{r};
                UI ui{s};
                ui.run();
                break;
            }
            case 3:
            {
                double prob;
                cout << "Dati o probabilitate: ";
                cin >> prob;
                RepoLab r{prob};
                Service s{r};
                UI ui{s};
                ui.run();

            }
            default:
                cout << "Optiune invalida!\n";
                break;
        }


    return 0;
}
