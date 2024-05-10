#include "ui.h"
#include <iostream>
#include <utility>

using std::cin;
using std::cout;


void UI::adauga_oferta(Service& serv) {
    int id, pret;
    string denumire, destinatie, tip;
    cout << "Introduceti id-ul ofertei: ";
    cin >> id;
    cout << "Introduceti denumirea ofertei: ";
    cin.get();
    getline(cin, denumire);
    cout << "Introduceti destinatia ofertei: ";
    getline(cin, destinatie);
    cout << "Introduceti tipul ofertei: ";
    getline(cin, tip);
    cout << "Introduceti pretul ofertei: ";
    cin >> pret;
    serv.add_oferta(id, denumire, destinatie, tip, pret);
    cout << "Oferta adaugata cu succes!\n";
}

void UI::sterge_oferta(Service& serv) {
    int id;
    cout << "Introduceti id-ul ofertei pe care doriti sa o stergeti: ";
    cin >> id;
    serv.delete_oferta(id);
    cout << "Oferta stearsa cu succes!\n";
}

void UI::modifica_oferta(Service& serv) {
    int id, pret;
    string denumire, destinatie, tip;
    cout << "Introduceti id-ul ofertei pe care doriti sa o modificati: ";
    cin >> id;
    cout << "Introduceti noua denumire a ofertei: ";
    cin.get();
    getline(cin, denumire);
    cout << "Introduceti noua destinatie a ofertei: ";
    cin.get();
    getline(cin, destinatie);
    cout << "Introduceti noul tip al ofertei: ";
    cin.get();
    getline(cin, tip);
    cout << "Introduceti noul pret al ofertei: ";
    cin >> pret;
    serv.update_oferta(id, denumire, destinatie, tip, pret);
    cout << "Oferta modificata cu succes!\n";
}

void UI::afiseaza_oferte(Service& serv) {
    vector oferte = serv.get_all();
    if(oferte.empty()) {
        cout << "Nu exista oferte!\n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferte_dupa_destinatie(Service& serv) {
    string dest;
    cout << "Introduceti destinatia dupa care doriti sa filtrati ofertele: ";
    cin.get();
    getline(cin, dest);
    vector oferte = serv.filtrare_oferte_dupa_destinatie(dest);
    if(oferte.empty()) {
        cout << "Nu exista oferte cu destinatia " << dest << "!\n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferte_dupa_pret(Service& serv) {
    int pret;
    cout << "Introduceti pretul maxim dupa care doriti sa filtrati ofertele: ";
    cin >> pret;
    vector oferte = serv.filtrare_oferte_dupa_pret(pret);
    if(oferte.empty()) {
        cout << "Nu exista oferte cu pretul mai mic sau egal cu " << pret << "!\n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferte_sortate_dupa_denumire(Service &serv) {
    vector oferte = serv.sort_dupa_denumire();
    if(oferte.empty()) {
        cout << "Nu exista oferte disponibile! \n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferte_sortate_dupa_destinatie(Service &serv) {
    vector oferte = serv.sort_dupa_destinatie();
    if(oferte.empty()) {
        cout << "Nu exista oferte disponibile! \n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferte_sortate_dupa_tip_si_pret(Service &serv) {
    vector oferte = serv.sort_dupa_tip_si_pret();
    if(oferte.empty()) {
        cout << "Nu exista oferte disponibile! \n";
        return;
    }
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::afiseaza_oferta_dupa_destinatie(Service &serv) {
    string dest;
    cout << "Introduceti destinatia dupa care doriti sa cautati: ";
    cin.get();
    getline(cin, dest);
    Oferta o = serv.cauta_dupa_destinatie(dest);
    cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
}

void UI::adauga_in_wishlist(Service &serv) {
    string denum;
    cout << "Introduceti denumirea dupa care doriti sa adaugati in wishlist: ";
    cin.get();
    getline(cin, denum);
    serv.add_wishlist_dupa_denumire(denum);
    cout << "Adaugare reusita!\n";
}

void UI::goleste_wishlist(Service &serv) {
    serv.sterge_wishlist();
    cout << "Stergere reusita!\n";
}

void UI::genereaza_oferte_random(Service &serv) {
    int numar;
    cout << "Dati un numar de cate oferte sa se adauge in wishlist: ";
    cin >> numar;
    serv.genereaza_random_oferte_wishlist(numar);
    cout << "Adaugare reusita!\n";
}

void UI::afiseaza_wishlist(Service &serv) {
    vector<Oferta> oferte = serv.returneaza_wishlist();
    cout << "Wishlistul: \n";
    for (const auto& o : oferte) {
        cout <<  o.get_id() << ": "  << " Denumire: " << o.get_denumire() << "/ Destinatie: " << o.get_destinatie() << "/ Tip: " << o.get_tip() << "/ Pret: " << o.get_pret() << "\n";
    }
}

void UI::exportare(Service &serv) {
    string nume;
    cout << "Dati numele fisierului unde doriti sa se faca export: ";
    cin.get();
    getline(cin, nume);
    serv.exporta(nume);
}

void UI::UI_wishlist() {
    while(true){
        afiseaza_wishlist(service);
        cout << "1. Adauga in wishlist oferta dupa denumire \n";
        cout << "2. Goleste wishlist \n";
        cout << "3. Generare wishlist \n";
        cout << "4. Export \n";
        cout << "5. Inapoi \n";
        cout << "Introduceti optiunea: ";
        int optiune;
        cin >> optiune;
        try{
            switch (optiune) {
                case 1:
                    adauga_in_wishlist(service);
                    break;
                case 2:
                    goleste_wishlist(service);
                    break;
                case 3:
                    genereaza_oferte_random(service);
                    break;
                case 4:
                    exportare(service);
                    break;
                case 5:
                    return;
                default:
                    cout << "Optiune invalida\n";
            }
        }
        catch (ValidatorException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (RepoException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (ServiceException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (const std::exception &e){
            cout <<e.what();
        }
    }
}

void UI::genereaza_rapot(Service &serv) {
    std::map<string,DTO_Raport> raport = serv.generare_raport();
    for(const auto & pair : raport){
        cout << pair.second.get_entity_type() << ": " << pair.second.get_count() <<" oferte disponibile!\n";
    }
}

void UI::run() {
    while (true) {
        cout << "1. Adauga oferta\n";
        cout << "2. Sterge oferta\n";
        cout << "3. Modifica oferta\n";
        cout << "4. Afiseaza oferte\n";
        cout << "5. Filtreaza oferte dupa destinatie\n";
        cout << "6. Filtreaza oferte dupa pret\n";
        cout << "7. Sorteaza oferte dupa denumire\n";
        cout << "8. Sorteaza oferte dupa destinatie\n";
        cout << "9. Sorteaza oferte dupa tip si pret\n";
        cout << "10. Cauta oferta dupa destinatie\n";
        cout << "11. Meniu wishlist\n";
        cout << "12. Generare Raport\n";
        cout << "13.Undo\n";
        cout << "14. Exit\n";
        cout << "Introduceti optiunea: ";
        int optiune;
        cin >> optiune;
        try {
            switch (optiune) {
                case 1:
                    adauga_oferta(service);
                    break;
                case 2:
                    sterge_oferta(service);
                    break;
                case 3:
                    modifica_oferta(service);
                    break;
                case 4:
                    afiseaza_oferte(service);
                    break;
                case 5:
                    afiseaza_oferte_dupa_destinatie(service);
                    break;
                case 6:
                    afiseaza_oferte_dupa_pret(service);
                    break;
                case 7:
                    afiseaza_oferte_sortate_dupa_denumire(service);
                    break;
                case 8:
                    afiseaza_oferte_sortate_dupa_destinatie(service);
                    break;
                case 9:
                    afiseaza_oferte_sortate_dupa_tip_si_pret(service);
                    break;
                case 10:
                    afiseaza_oferta_dupa_destinatie(service);
                    break;
                case 11:
                    UI_wishlist();
                    break;
                case 12:
                    genereaza_rapot(service);
                    break;
                case 13:
                    service.undo();
                    cout << "Undo efectuat!\n";
                    break;
                case 14:
                    return;
                default:
                    cout << "Optiune invalida\n";
            }
        }
        catch (ValidatorException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (RepoException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (ServiceException& e) {
            cout << e.get_msg() << "\n";
        }
        catch (const std::exception &e){
            cout <<e.what();
        }
    }
}

UI::UI(Service &serv) :service{serv}{

}
