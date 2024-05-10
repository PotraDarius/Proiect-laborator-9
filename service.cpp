#include "service.h"
#include "domain.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include <utility>

using std::copy_if;
using std::back_inserter;
using std::sort;
using std::find_if;
using std::map;


void Service::add_oferta(const int& id, const string& denum, const string &dest, const string &tip, const int &pret){
    Oferta o{id, denum,dest, tip, pret};
    try {
        this->val.validare_oferta(o);
        this->repo.store_oferta(o);
        lista_undo.push_back(make_unique<UndoAdauga>(repo, o));
    }
    catch(ValidatorException& e){
        throw e;
    }
    catch(RepoException& e){
        throw e;
    }
}

void Service::delete_oferta(const int& id){
    try{
        Oferta of_stearsa = this->repo.del_oferta(id);
        lista_undo.push_back(make_unique<UndoSterge>(repo, of_stearsa));
    }
    catch(RepoException& e){
        throw e;
    }
}

void Service::update_oferta(const int& id, const string &denumire, const string &dest, const string &tip, const int &pret){
    Oferta o{id, denumire, dest, tip, pret};
    try{
        this->val.validare_oferta(o);
        Oferta oferta_modificata = this->repo.modificare_oferta(id,o);
        lista_undo.push_back(make_unique<UndoModifica>(repo, oferta_modificata, id));
    }
    catch(ValidatorException& e){
        throw e;
    }
    catch(RepoException& e){
        throw e;
    }
}

vector<Oferta>& Service::get_all() {
    return this->repo.get_all();
}

vector<Oferta> Service::filtrare_oferte_dupa_destinatie(const string& dest){
    vector oferte = this->repo.get_all();
    vector<Oferta> rez;

    copy_if(oferte.begin(), oferte.end(), back_inserter(rez),
            [&dest](const Oferta& o){return o.get_destinatie() == dest;} );
    return rez;
}

vector<Oferta> Service::filtrare_oferte_dupa_pret(const int& pret){
    vector oferte = this->repo.get_all();
    vector<Oferta> rez;

    copy_if(oferte.begin(), oferte.end(), back_inserter(rez),
            [&pret](const Oferta& o){return o.get_pret() <= pret;});
    return rez;
}


vector<Oferta> Service::sort_generic(bool (*conditie)(const Oferta &, const Oferta &)) {
    vector<Oferta> rezultat = repo.get_all();
    sort(rezultat.begin(), rezultat.end(), conditie);

    return rezultat;}

vector<Oferta> Service::sort_dupa_denumire() {
    return sort_generic(compara_denumire);
}


vector<Oferta> Service::sort_dupa_destinatie() {
    return sort_generic(compara_destinatie);
}

vector<Oferta> Service::sort_dupa_tip_si_pret() {
    return sort_generic(compara_tip_si_pret);
}

Oferta Service::cauta_dupa_destinatie(const std::string &destinatie) {
        vector<Oferta> rez = repo.get_all();
        auto it = find_if(rez.begin(), rez.end(),
                          [&destinatie](const Oferta &o) { return o.get_destinatie() == destinatie; });

        if(it != rez.end()){
            return *it;
        }
        else{
            throw ServiceException("Nu exista o oferta cu aceasta destinatie!\n");
        }
}


void Service::sterge_wishlist() {
        wishlist.del_all_elements();

}

void Service::add_wishlist_dupa_denumire(std::string denumire) {
    vector<Oferta> rez = repo.get_all();
    auto it = find_if(rez.begin(), rez.end(),
                      [&denumire](const Oferta &o) { return o.get_denumire() == denumire; });
    if (it != rez.end()) {
        wishlist.store_oferta(*it);
    }
    else{
        throw ServiceException("Nu exista oferta cu aceasta denumire!");
    }

}

vector<Oferta>& Service::returneaza_wishlist() {
    return wishlist.get_all();
}



void Service::genereaza_random_oferte_wishlist(int numar) {
        vector<Oferta> all = repo.get_all();
        if(all.empty()){
            throw ServiceException("Nu exista inca oferte in lista!\n");
        }
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        for (int i = 1; i <= numar; i++) {
            std::shuffle(all.begin(), all.end(), std::default_random_engine(seed));
            wishlist.store_oferta(all[0]);

        }

}

void Service::undo() {
    if(lista_undo.empty())
        throw ServiceException("Nu mai exista operatii!");

    lista_undo.back()->doUndo();
    lista_undo.pop_back();
}


void Service::exporta(std::string nume_fisier) {
    nume_fisier += ".csv";
    std::ofstream exp(nume_fisier);

    vector<Oferta> oferte = wishlist.get_all();
    for (const auto& o : oferte) {
        exp <<  o.get_id() <<  "/" << o.get_denumire() << "/" << o.get_destinatie() << "/" << o.get_tip() << "/" << o.get_pret() << "\n";

    }

    exp.close();

}


DTO_Raport::DTO_Raport(std::string type, int count):entity_type{std::move(type)}, count{count}{}

void DTO_Raport::incrementare() {
    count++;
}

string DTO_Raport::get_entity_type() const{
    return entity_type;
}

int DTO_Raport::get_count() const {
    return count;
}

map<string, DTO_Raport> Service::generare_raport() {
    vector<Oferta> all = repo.get_all();
    map<string,DTO_Raport> rezultat;
    for(const auto & of : all){
        string aux = of.get_tip();
        if(rezultat.find(aux) != rezultat.end()){
            rezultat[aux].incrementare();
        }
        else{
            rezultat.insert({aux, DTO_Raport(aux, 1)});
        }
    }

    return rezultat;

}