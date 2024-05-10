#include "validator.h"

bool Validator::validare_oferta(const Oferta &of) const {
    string err = "";
    if(of.get_id() < 0){
        err += "Id invalid!\n";
    }
    if(of.get_denumire().empty()){
        err += "Denumire invalida!\n";
    }
    if(of.get_destinatie().empty()){
        err += "Destinatie invalida!\n";
    }
    if(of.get_tip().empty()){
        err += "Tip invalid!\n";
    }
    if(of.get_pret() < 0){
        err += "Pret invalid!\n";
    }
    if(!err.empty()){
        throw ValidatorException(err);
    }
    return true;
}


