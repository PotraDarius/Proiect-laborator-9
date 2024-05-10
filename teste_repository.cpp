#include "teste_repository.h"
#include "repository.h"
#include "domain.h"
#include <cassert>


void test_store_oferta() {
    Repo repo;
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of2);
    assert(repo.get_all().size() == 2);
    try{
        repo.store_oferta(of1);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }
}

void test_del_oferta() {
    Repo repo;
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    repo.del_oferta(1);
    assert(repo.get_all().empty() == true);
    try{
        repo.del_oferta(1);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }
    repo.store_oferta(of1);
    repo.store_oferta(of2);
    repo.del_oferta(2);
    assert(repo.get_all().size() == 1);
}

void test_modificare_oferta() {
    Repo repo;
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{1, "denumire2", "destinatie2", "tip2", 200};
    repo.modificare_oferta(1, of2);
    assert(repo.get_all().size() == 1);
    assert(repo.get_all()[0].get_denumire() == "denumire2");
    assert(repo.get_all()[0].get_destinatie() == "destinatie2");
    assert(repo.get_all()[0].get_tip() == "tip2");
    assert(repo.get_all()[0].get_pret() == 200);
    try{
        repo.modificare_oferta(0, of2);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }
}

void test_get_all() {
    Repo repo;
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of2);
    assert(repo.get_all().size() == 2);
    vector oferte = repo.get_all();
    assert(oferte[0] == of1);
    assert(oferte[1] == of2);
}



void test_citire_scriere_fisier(){
    RepoFisier repo{"test.txt"};
    assert(repo.get_all().empty() == true);
    repo.store_oferta(Oferta(1, "denumire1", "destinatie1", "tip1", 100));
    assert(repo.get_all().size() == 1);
    repo.modificare_oferta(1, Oferta(1,"denumire", "destinatie", "tip", 50));
    assert(repo.get_all()[0].get_denumire() == "denumire");
    repo.del_oferta(1);
    assert(repo.get_all().empty() == true);
    repo.del_all_elements();


}

void test_store_repolab(){
    RepoLab repo{-1};
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of2);
    assert(repo.get_all().size() == 2);
    try{
        repo.store_oferta(of1);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }

    RepoLab repo1{101};
    try{
        repo1.store_oferta(of1);
    }catch (RepoException&){
        assert(true);
    }
}

void test_del_repolab(){
    RepoLab repo{-1};
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    repo.del_oferta(1);
    assert(repo.get_all().empty() == true);
    try{
        repo.del_oferta(1);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }
    repo.store_oferta(of1);
    repo.store_oferta(of2);
    repo.del_oferta(2);
    assert(repo.get_all().size() == 1);

    RepoLab repo1{101};
    try{
        repo1.del_oferta(1);
    }catch (RepoException&){
        assert(true);
    }
}

void test_modificare_repolab(){
    RepoLab repo{-1};

    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{1, "denumire2", "destinatie2", "tip2", 200};
    repo.modificare_oferta(1, of2);
    assert(repo.get_all().size() == 1);
    assert(repo.get_all()[0].get_denumire() == "denumire2");
    assert(repo.get_all()[0].get_destinatie() == "destinatie2");
    assert(repo.get_all()[0].get_tip() == "tip2");
    assert(repo.get_all()[0].get_pret() == 200);
    try{
        repo.modificare_oferta(0, of2);
        assert(false);
    }catch(RepoException&){
        assert(true);
    }


    RepoLab repo1{101};
    try{
        repo1.modificare_oferta(0, of2);
    }catch (RepoException&){
        assert(true);
    }
}

void test_get_all_repolab(){
    RepoLab repo{-1};
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    assert(repo.get_all().size() == 1);
    Oferta of2{2, "denumire2", "destinatie2", "tip2", 200};
    repo.store_oferta(of2);
    assert(repo.get_all().size() == 2);
    vector<Oferta> oferte = repo.get_all();
    assert(oferte[0] == of2);
    assert(oferte[1] == of1);

    RepoLab repo1{101};
    try{
        repo1.get_all();
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}

void test_dell_all_repolab(){
    RepoLab repo{-1};
    Oferta of1{1, "denumire1", "destinatie1", "tip1", 100};
    repo.store_oferta(of1);
    repo.del_all_elements();
    assert(repo.get_all().empty() == true);

    RepoLab repo1{101};
    try{
        repo1.del_all_elements();
        assert(false);
    }
    catch (RepoException&){
        assert(true);
    }
}

void teste_repo() {
    test_store_oferta();
    test_del_oferta();
    test_modificare_oferta();
    test_get_all();
    test_citire_scriere_fisier();
    test_store_repolab();
    test_del_repolab();
    test_modificare_repolab();
    test_get_all_repolab();
    test_dell_all_repolab();
}
