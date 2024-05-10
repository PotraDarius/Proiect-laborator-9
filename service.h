#pragma once
#include <utility>
#include <map>
#include <memory>

#include "undo.h"
#include "domain.h"
#include "repository.h"
#include "validator.h"


using std::vector;
using std::map;
using std::unique_ptr;
using std::make_unique;


class ServiceException{
private:
    string msg;
public:
    explicit ServiceException(string msg): msg{std::move(msg)}{}
    [[nodiscard]] string get_msg() const {
        return this->msg;
    }
};

class DTO_Raport;

class Service
{
private:
    RepoGeneric& repo;
    Validator val;
    RepoWishlist wishlist;
    vector<unique_ptr<ActiuneUndo>> lista_undo;
public:
    /**
     * Constructor pentru clasa Service
     */
    explicit Service(RepoGeneric& repo): repo{repo}{};

    /**
     * Adauga o oferta in lista de oferte
     * id - int
     * denum - string
     * dest - string
     * tip - string
     * pret - int
     * @raise RepoException - exista deja o oferta cu datele date
     * @raise ValidatorException - oferta noua creata nu este valida
     */
    void add_oferta(const int& id,const string& denum, const string &dest, const string &tip, const int &pret);

    /**
     * Sterge o oferta din lista de oferte
     * id - int
     * @raise RepoException - nu exista oferta cu id-ul dat
     */
    void delete_oferta(const int& id);

    /**
     * Modifica o oferta din lista de oferte
     *  id - int
     *  denumire - string
     *  dest - string
     *  tip - string
     *  pret - int
     *  @raise RepoException - exista deja o oferta cu datele date
     * @raise ValidatorException - oferta noua creata nu este valida
     */
    void update_oferta(const int& id,const string &denumire, const string &dest, const string &tip, const int &pret);

    /**
     * Returneaza toate ofertele ce au destinatia data
     * dest - string
     * @return vector<Oferta>
     */
    vector<Oferta> filtrare_oferte_dupa_destinatie(const string& dest);

    /**
     * Returneaza toate ofertele ce au pretul mai mic sau egal decat cel dat
     * pret - int
     * @return vector<Oferta>
     */
    vector<Oferta> filtrare_oferte_dupa_pret(const int& pret);

    /**
     * Returneaza toate ofertele ce au tipul dat
     * tip - string
     * @return vector<Oferta>
     */
    vector<Oferta> sort_generic(bool (*conditie)(const Oferta&, const Oferta&));

    /**
     * Returneaza toate ofertele sortate dupa denumire
     * @return vector<Oferta>
     */
    vector<Oferta> sort_dupa_denumire();

    /**
     * Returneaza toate ofertele sortate dupa destinatie
     * @return vector<Oferta>
     */
    vector<Oferta> sort_dupa_destinatie();

    /**
     * Returneaza toate ofertele sortate dupa tip si pret
     * @return vector<Oferta>
     */
    vector<Oferta> sort_dupa_tip_si_pret();

    /**
     * Returneaza toate ofertele
     * @return vector<Oferta>
     */
    vector<Oferta>& get_all();

    /**
     * Cauta o oferta dupa destinatie
     * @param destinatie - string
     * @return Oferta
     */
    Oferta cauta_dupa_destinatie(const string& destinatie);

    /**
     * Sterge toate elementele din wishlist
     */
    void sterge_wishlist();


    /**
     * Adauga o oferta in wishlist dupa o denumire data
     * @param denumire - string
     */
    void add_wishlist_dupa_denumire(string denumire);


    /**
     * Genereaza random oferte in wishlist
     * @param numar - int
     */
    void genereaza_random_oferte_wishlist(int numar);


    /**
     * Returneaza wishlist-ul
     * @return vector<Oferta>
     */
    vector<Oferta>& returneaza_wishlist();

    /**
     * Exporta wishlist-ul intr-un fisier
     * @param nume_fisier - string
     */
    void exporta(string nume_fisier);

    /**
     * Genereaza un raport
     * @return map<string, DTO_Raport>
     */
    map<string, DTO_Raport> generare_raport();

    /**
     * Efectueaza undo
     */
    void undo();

    ~Service() = default;


};

class DTO_Raport{
private:
    string entity_type;
    int count;
public:
    DTO_Raport() = default;
    DTO_Raport(string type, int count);

    void incrementare();

    [[nodiscard]] string get_entity_type() const;

    [[nodiscard]] int get_count() const;

};


