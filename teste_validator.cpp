#include "teste_validator.h"
#include "validator.h"
#include <cassert>


void test_validare_oferta() {
    Validator val;
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    assert(val.validare_oferta(of1) == true);
    Oferta of2{1, "", "destinatie1", "tip1", 100};
    try{
        static_cast<void>(val.validare_oferta(of2));
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
    Oferta of3{1, "denumire1", "", "tip1", 100};
    try{
        static_cast<void>(val.validare_oferta(of3));
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
    Oferta of4{1, "denumire1", "destinatie1", "", 100};
    try{
        static_cast<void>(val.validare_oferta(of4));
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
    Oferta of5{1, "denumire1", "destinatie1", "tip1", -1};
    try{
        static_cast<void>(val.validare_oferta(of5));
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
    Oferta of6{-1, "denumire1", "destinatie1", "tip1", 100};
    try{
        static_cast<void>(val.validare_oferta(of6));
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
}