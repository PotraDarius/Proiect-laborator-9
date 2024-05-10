#pragma once
#include "domain.h"
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include "vector_dinamic.h"

using std::vector;
using std::unordered_map;

class RepoException: public std::exception{
private:
    string msg;
public:
    explicit RepoException(string msg): msg{std::move(msg)}{}
    [[nodiscard]] string get_msg() const{
        return this->msg;
    }
};

class RepoGeneric{
public:
    /**
     * Adauga o oferta in lista de oferte
     * of - Oferta
     * @raise RepoException - exista deja oferta data
     */
    virtual void store_oferta(const Oferta & of) = 0;

    /**
     * Sterge o oferta din lista de oferte
     * id - int
     * @raise RepoException - nu exista oferta cu id-ul dat
     */
    virtual Oferta del_oferta(const int & id) = 0;

    /**
     * Modifica o oferta din lista de oferte
     * id - int
     * new_of - Oferta
     * @raise Repoexception - nu exista oferta cu id-ul dat
     * @raise ValidatorException - new_of nu este valid
     */
    virtual Oferta modificare_oferta(const int& id, const Oferta& new_of) = 0;

    /**
     * Returneaza toate ofertele
     * @return vector<Oferta>
     */
    virtual void del_all_elements() = 0;

    /**
     * Sterge toate elementele din lista de oferte
     */
    virtual vector<Oferta>& get_all() = 0;
};


class Repo: public RepoGeneric{

private:
    vector<Oferta> oferte;
public:
    Repo() = default;


    void store_oferta(const Oferta& of) override;


    Oferta del_oferta(const int& id) override;


    Oferta modificare_oferta(const int& id, const Oferta& new_of) override;



    [[nodiscard]]vector<Oferta>& get_all() override;


     void del_all_elements() override;

    ~Repo() = default;

};

class RepoWishlist: public Repo{
private:
    vector<Oferta> oferte;
public:
    void store_oferta(const Oferta & of) override;
    void del_all_elements() override;
    vector<Oferta>& get_all() override;
};


/**
 * @brief Clasa pentru repo-ul de oferte din fisier
 * pentru a salva ofertele in fisier ele trebuie sa aiba fiecare atribut cu "-" in loc de spatiu unde sunt mai multe cuvinte
 */
class RepoFisier: public Repo{
private:
    void load_to_file();
    void load_from_file();
    string filename;
public:
    explicit RepoFisier(string filename): Repo(),  filename{std::move(filename)}{
        load_from_file();
    }

    void store_oferta(const Oferta & of) override{
        Repo::store_oferta(of);
        load_to_file();
    }

    Oferta del_oferta(const int & id) override{
        Oferta aux = Repo::del_oferta(id);
        load_to_file();
        return aux;
    }

    Oferta modificare_oferta(const int& id, const Oferta& new_of) override{
        Oferta aux = Repo::modificare_oferta(id, new_of);
        load_to_file();
        return aux;
    }

    void del_all_elements() override{
        Repo::del_all_elements();
        load_to_file();
    }

};

/**
 * @brief Clasa pentru repo-ul de oferte din memorie cu probabilitate

 */
class RepoLab: public RepoGeneric{
private:
    unordered_map<int, Oferta> oferte;
    vector<Oferta> toate_ofertele;
    double probabilitate;

    /**
     * @brief Returneaza o probabilitate random intre 0 si 100
     * @return
     */
    static double probabiliate_random(){
        return static_cast<double >(rand()) / RAND_MAX * 100;
    }
public:
    explicit RepoLab(double probabilitate): probabilitate{probabilitate}{};
    void store_oferta(const Oferta &of) override;
    Oferta del_oferta(const int &id) override;
    Oferta modificare_oferta(const int & id, const Oferta & new_of) override;
    vector<Oferta>& get_all() override;
    void del_all_elements() override;
};

