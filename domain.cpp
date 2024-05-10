#include "domain.h"
#include <iostream>
#include <random>
#include <algorithm>


using std::string;
using std::cout;

Oferta ::Oferta(int id, string denumire, string destinatie, string tip, int pret): id {id}, denumire{denumire}, destinatie{destinatie},
tip{tip}, pret{pret}{

}

/*Oferta ::Oferta(const Oferta &ot): id{ot.get_id()}, denumire{ot.get_denumire()}, destinatie{ot.get_destinatie()},
tip {ot.get_tip()}, pret{ot.get_pret()}{
    cout << "Hello\n";

}*/

int Oferta::get_pret() const {
    return this->pret;
}

string Oferta::get_tip() const  {
    return this->tip;
}

string Oferta::get_destinatie() const {
    return this->destinatie;
}

string Oferta::get_denumire() const {
    return this->denumire;
}

int Oferta::get_id() const {
    return this->id;
}

void Oferta::set_denumire(string denumire) {
    this->denumire = denumire;
}

void Oferta::set_destinatie(string destinatie) {
    this->destinatie = destinatie;
}

void Oferta::set_tip(string tip) {
    this->tip = tip;
}

void Oferta::set_pret(int pret) {
    this->pret = pret;
}

bool Oferta::operator==(const Oferta &ot) const {
    return this->denumire == ot.denumire && this->destinatie == ot.destinatie && this->tip == ot.tip && this->pret == ot.pret;
}

void Oferta::operator=(const Oferta &ot) {
    this->id = ot.get_id();
    this->set_denumire(ot.get_denumire());
    this->set_destinatie(ot.get_destinatie());
    this->set_tip(ot.get_tip());
    this->set_pret(ot.get_pret());

}

bool compara_denumire(const Oferta& of1, const Oferta& of2) {
    if(of1.get_denumire().compare(of2.get_denumire()) < 0)
        return true;
    return false;
}

bool compara_destinatie(const Oferta& of1, const Oferta& of2){
    if(of1.get_destinatie().compare(of2.get_destinatie()) < 0)
        return true;
    return false;
}

bool compara_tip_si_pret(const Oferta& of1, const Oferta& of2){
    if(of1.get_tip().compare(of2.get_tip()) < 0)
        return true;
    else if(of1.get_tip() == of2.get_tip()){
        if(of1.get_pret() <= of2.get_pret())
            return true;
    }
    return false;
}




