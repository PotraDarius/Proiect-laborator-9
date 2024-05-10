#include "teste_service.h"
#include "service.h"
#include "repository.h"
#include "validator.h"

#include <cassert>
#include <fstream>


void teste_service(){
    test_add_oferta();
    test_delete_oferta();
    test_update_oferta();
    test_get_all_service();
    test_filtrare_oferte_dupa_destinatie();
    test_filtrare_oferte_dupa_pret();
    test_sortare_dupa_denumire();
    test_sortare_dupa_destinatie();
    test_sortate_dupa_tip_si_pret();
    test_add_wishlist_dupa_denumire();
    test_sterge_wishlist();
    test_cauta_dupa_destinatie();
    test_generare_random();
    test_export();
    test_generare_raport();
    test_undo();
}

void test_add_oferta(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    assert(s.get_all().size() == 1);
    try{
        s.add_oferta(1,"denumire","dest","tip",100);
        assert(false);
    }
    catch(RepoException& e){
        assert(true);
    }

    try{
        s.add_oferta(2, "", "", "", -48);
        assert(false);
    }
    catch (ValidatorException& e){
        assert(true);
    }
}

void test_delete_oferta(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    s.delete_oferta(1);
    assert(s.get_all().empty() == true);
    try{
        s.delete_oferta(1);
        assert(false);
    }
    catch(RepoException& e){
        assert(true);
    }

}

void test_update_oferta(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    s.update_oferta(1,"denumire","dest","tip",100);
    assert(s.get_all().size() == 1);
    try{
        s.update_oferta(2,"denumire","dest","tip",100);
        assert(false);
    }
    catch(RepoException& e){
        assert(true);
    }

    try {
        s.update_oferta(1, "", "", "", 79);
        assert(false);
    }
    catch(ValidatorException& e){
        assert(true);
    }
}

void test_get_all_service(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    s.add_oferta(2,"denumire2","dest2","tip2",200);
    s.add_oferta(3,"denumire3","dest3","tip3",300);
    assert(s.get_all().size() == 3);
}

void test_filtrare_oferte_dupa_destinatie(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    s.add_oferta(2,"denumire2","dest","tip2",100);
    s.add_oferta(3,"denumire3","dest","tip3",100);
    assert(s.filtrare_oferte_dupa_destinatie("dest").size() == 3);
    assert(s.filtrare_oferte_dupa_destinatie("dest2").empty() == true);
}

void test_filtrare_oferte_dupa_pret(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire","dest","tip",100);
    s.add_oferta(2,"denumire2","des2","tip2",100);
    s.add_oferta(3,"denumire3","dest3","tip3",100);
    assert(s.filtrare_oferte_dupa_pret(100).size() == 3);
    assert(s.filtrare_oferte_dupa_pret(50).empty() == true);
}

void test_sortare_dupa_denumire(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest","tip",100);
    s.add_oferta(2,"denumire2","des2","tip2",100);
    s.add_oferta(3,"denumire","dest3","tip3",100);

    vector<Oferta> rezultat = s.sort_dupa_denumire();
    assert(rezultat[0].get_denumire() == "denumire");
    assert(rezultat[1].get_denumire() == "denumire2");
    assert(rezultat[2].get_denumire() == "denumire3");
}

void test_sortare_dupa_destinatie(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",100);
    s.add_oferta(2,"denumire2","dest2","tip2",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    vector<Oferta> rezultat = s.sort_dupa_destinatie();

    assert(rezultat[0].get_destinatie() == "dest");
    assert(rezultat[1].get_destinatie() == "dest2");
    assert(rezultat[2].get_destinatie() == "dest3");
}

void test_sortate_dupa_tip_si_pret(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    vector<Oferta> rezultat = s.sort_dupa_tip_si_pret();

    assert(rezultat[0].get_tip() == "tip");
    assert(rezultat[0].get_pret() == 100);
    assert(rezultat[1].get_tip() == "tip");
    assert(rezultat[1].get_pret() == 200);
    assert(rezultat[2].get_tip() == "tip3");
}

void test_add_wishlist_dupa_denumire(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    s.add_wishlist_dupa_denumire("denumire");

    vector<Oferta> rez = s.returneaza_wishlist();

    assert(rez.size() == 1);
    assert(rez[0].get_denumire() == "denumire");

    try{
        s.add_wishlist_dupa_denumire("denumire4");
        assert(false);
    }
    catch (ServiceException &e){
        assert(true);
    }
}

void test_sterge_wishlist(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    s.add_wishlist_dupa_denumire("denumire");
    s.add_wishlist_dupa_denumire("denumire2");
    s.add_wishlist_dupa_denumire("denumire3");

    vector<Oferta> rez = s.returneaza_wishlist();

    assert(rez.size() == 3);

    s.sterge_wishlist();

    rez = s.returneaza_wishlist();

    assert(rez.empty() == true);
}

void test_cauta_dupa_destinatie(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    Oferta o = s.cauta_dupa_destinatie("dest");

    assert(o.get_destinatie() == "dest");
    assert(o.get_denumire() == "denumire");
    assert(o.get_pret() == 100);

    try{
        s.cauta_dupa_destinatie("dest4");
        assert(false);
    }
    catch (ServiceException &e){
        assert(true);
    }
}

void test_export(){
    string nume_fisier = "test";

    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    s.add_wishlist_dupa_denumire("denumire");

    s.exporta(nume_fisier);

    std::ifstream exp("test.csv");

    string result;
    exp >> result;
    assert(result == "3/denumire/dest/tip3/100");
    exp.close();
}

void test_generare_random(){
    Repo r;
    Service s{r};
    try{
        s.genereaza_random_oferte_wishlist(6);
        assert(false);
    }
    catch (ServiceException & e){
        assert(true);
    }

    s.add_oferta(1,"denumire", "dest", "tip", 100);

    s.genereaza_random_oferte_wishlist(2);
    vector<Oferta> rez = s.returneaza_wishlist();

    assert(rez.size() == 2);
}

void test_generare_raport(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.add_oferta(2,"denumire2","dest2","tip",100);
    s.add_oferta(3,"denumire","dest","tip3",100);

    std::map<string ,DTO_Raport> raport = s.generare_raport();

    assert(raport["tip"].get_entity_type() == "tip");
    assert(raport["tip3"].get_entity_type() == "tip3");
    assert(raport["tip"].get_count() == 2);
    assert(raport["tip3"].get_count() == 1);
}

void test_undo(){
    Repo r;
    Service s{r};
    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.undo();
    assert(s.get_all().empty() == true);
    try{
        s.undo();
        assert(false);
    }
    catch (ServiceException & e){
        assert(true);
    }

    s.add_oferta(1,"denumire3","dest3","tip",200);
    s.delete_oferta(1);
    s.undo();
    assert(s.get_all().size() == 1);

    s.update_oferta(1, "test", "dest", "t", 1 );
    s.undo();
    assert(s.get_all()[0] == Oferta(1,"denumire3", "dest3", "tip", 200));

}