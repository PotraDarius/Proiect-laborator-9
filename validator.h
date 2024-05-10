#pragma once
#include "domain.h"

class ValidatorException{
private:
    string msg;
public:
    ValidatorException(string msg): msg{msg}{}
    string get_msg() const{
        return this->msg;
    }
};

class Validator {
public:
    Validator() = default;

    /**
     * Valideaza o oferta
     * of - Oferta
     * @return true daca oferta este valida, throw ValidatorException daca id-ul este negativ, denumirea, destinatia sau tipul sunt goale sau pretul este negativ
     */
    bool validare_oferta(const Oferta& of) const;

};


