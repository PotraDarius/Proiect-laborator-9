#include "repository.h"
#include <algorithm>
#include <fstream>
#include <cstring>
#include <sstream>

using std::find_if;
using std::stringstream;

void Repo::store_oferta(const Oferta &of) {
    /*for(const Oferta& of1: this->oferte){
        if(of1 == of){
            throw RepoException("Oferta exista deja!");
        }
    }*/
    auto it = find_if(oferte.begin(), oferte.end(),
                      [&of](const Oferta &o){ return o == of;});
    if(it == oferte.end()) {
        this->oferte.push_back(of);
    }
    else{
        throw RepoException("Oferta exista deja!");
    }
}

void RepoWishlist::store_oferta(const Oferta &of) {
    oferte.push_back(of);
}

void RepoWishlist::del_all_elements() {
    oferte.clear();
}

vector<Oferta>& RepoWishlist::get_all() {
    return oferte;
}

Oferta Repo::del_oferta(const int &id) {
    /*int i = 0;
    for(const Oferta& of: this->oferte){
        if(of.get_id() == id){
            this->oferte.erase(oferte.begin() + i);
            return;
        }
        i++;
    }*/
    auto it = find_if(oferte.begin(), oferte.end(),
                      [&id](const Oferta &o){ return o.get_id() == id;});

    if(it != oferte.end()){
        Oferta aux = *it;
        oferte.erase(it);
        return aux;
    }
    throw RepoException("Nu exista oferta cu acest id!");
}

Oferta Repo::modificare_oferta(const int &id, const Oferta &new_of) {
    for(Oferta& of1: this->oferte){
        if(of1.get_id() == id){
            Oferta aux = of1;
            of1 = new_of;
            return aux;
        }
    }
    throw RepoException("Nu exista oferta cu acest id!");
}

vector<Oferta>& Repo::get_all()  {
    return oferte;
}

void Repo::del_all_elements() {
    oferte.clear();
}




void RepoFisier::load_from_file() {
    std::ifstream fin(filename);
    string line;
    while(getline(fin, line)){
        stringstream ss(line);
        int id, pret;
        string denumire, destinatie, tip;
        ss >> id;
        ss >> denumire;
        ss >> destinatie;
        ss >> tip;
        ss >> pret;
        Repo::store_oferta(Oferta(id, denumire, destinatie, tip, pret));
    }

    fin.close();
}

void RepoFisier::load_to_file() {
    std::ofstream fout(filename);

    for(const auto&o : get_all()){
        fout <<  o.get_id() <<  " " << o.get_denumire() << " " << o.get_destinatie() << " " << o.get_tip() << " " << o.get_pret() << "\n";
    }

    fout.close();
}

void RepoLab::store_oferta(const Oferta &of) {
    double prob = probabiliate_random();
    if(prob > probabilitate) {
        for (auto &it: oferte) {
            if (it.second == of) {
                throw RepoException("Exista deja o oferta ce aceste date!");
            }
        }
        oferte.insert({of.get_id(), of});
    }
    else{
        throw RepoException("Probabilitate prea mica!");
    }
}

Oferta RepoLab::del_oferta(const int &id) {
    double prob = probabiliate_random();
    if(prob > probabilitate) {
        if(oferte.find(id) == oferte.end()){
            throw RepoException("Nu exista o oferta cu acest id!");
        }
        Oferta aux = oferte.find(id)->second;
        oferte.erase(id);
        return aux;
    }
    else{
        throw RepoException("Probabilitate prea mica!");
    }
}

Oferta RepoLab::modificare_oferta(const int &id, const Oferta &new_of) {
    double prob = probabiliate_random();
    if(prob > probabilitate) {
        auto it = oferte.find(id);
        if(it == oferte.end()){
            throw RepoException("Nu exista o oferta cu acest id!");
        }
        Oferta aux = it->second;
        oferte.erase(it);
        oferte.insert({id, new_of});
        return aux;
    }
    else{
        throw RepoException("Probabilitate prea mica!");
    }
}

vector<Oferta>& RepoLab::get_all() {
    double prob = probabiliate_random();
    if(prob > probabilitate) {
        toate_ofertele.clear();
        for(const auto & it: oferte){
            toate_ofertele.push_back(it.second);
        }
        return toate_ofertele;
    }
    else{
        throw RepoException("Probabilitate prea mica!");
    }
}

void RepoLab::del_all_elements() {
    double prob = probabiliate_random();
    if(prob > probabilitate) {
        oferte.clear();
    }
    else{
        throw RepoException("Probabilitate prea mica!");
    }
}


