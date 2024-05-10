#include "teste_domain.h"
#include "domain.h"
#include <cassert>

void test_creare_oferta(){
    Oferta of{1, "denumire", "destinatie", "tip", 100};

    assert(of.get_id() == 1);
    assert(of.get_denumire() == "denumire");
    assert(of.get_destinatie() == "destinatie");
    assert(of.get_tip() == "tip");
    assert(of.get_pret() == 100);

    of.set_denumire("denumire2");
    of.set_destinatie("destinatie2");
    of.set_tip("tip2");
    of.set_pret(200);

    assert(of.get_denumire() == "denumire2");
    assert(of.get_destinatie() == "destinatie2");
    assert(of.get_tip() == "tip2");
    assert(of.get_pret() == 200);

    Oferta of2{1, "denumire2", "destinatie2", "tip2", 200};
    assert(of == of2);

    Oferta of3{3, "denumire3", "destinatie3", "tip3", 300};
    of = of3;
    assert(of == of3);


}

void test_compara_denumire(){
    Oferta of{1, "denumire", "destinatie", "tip", 100};
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};

    assert(of.get_denumire() == "denumire");
    assert(of2.get_denumire() == "denumire2");

    assert(compara_denumire(of, of2) == 1);
    assert(compara_denumire(of2, of) == 0);
}

void test_compara_destinatie(){
    Oferta of{1, "denumire", "destinatie", "tip", 100};
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};

    assert(of.get_destinatie() == "destinatie");
    assert(of2.get_destinatie() == "destinatie2");

    assert(compara_destinatie(of, of2) == 1);
    assert(compara_destinatie(of2, of) == 0);
}

void test_compara_tip_si_pret(){
    Oferta of{1, "denumire", "destinatie", "tip", 100};
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};

    assert(of.get_tip() == "tip");
    assert(of2.get_tip() == "tip2");

    assert(of.get_pret() == 100);
    assert(of2.get_pret() == 200);

    assert(compara_tip_si_pret(of, of2) == 1);
    assert(compara_tip_si_pret(of2, of) == 0);

}

void teste_domain(){
    test_creare_oferta();
    test_compara_denumire();
    test_compara_destinatie();
    test_compara_tip_si_pret();
}