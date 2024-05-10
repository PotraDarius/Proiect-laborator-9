#pragma once
#include <string>

using std::string;

class Oferta{
private:
    int id;
    string denumire;
    string destinatie;
    string tip;
    int pret;

public:
    Oferta() = default;

    /**
     * Constructor pentru clasa Oferta
     * id - int
     * denumire - string
     * destinatie - string
     * tip - string
     * pret - int
     */
    Oferta(int id, string denumire, string destinatie, string tip, int pret);

    //Oferta(const Oferta& ot);

    /**
     * Getter pentru tip
     * @return string
     */
    [[nodiscard]]string  get_tip() const;

    /**
     * Getter pentru destinatie
     * @return string
     */
    [[nodiscard]] string get_destinatie() const;

    /**
     * Getter pentru denumire
     * @return string
     */
    [[nodiscard]] string get_denumire() const;

    /**
     * Getter pentru pret
     * @return int
     */
    [[nodiscard]]int get_pret() const;

    /**
     * Getter pentru id
     * @return int
     */
    [[nodiscard]]int get_id() const;

    /**
     * Setter pentru denumire
     * denumire - string
     */
    void set_denumire(string denumire);

    /**
     * Setter pentru destinatie
     * destinatie - string
     */
    void set_destinatie(string destinatie);

    /**
     * Setter pentru tip
     * tip - string
     */
    void set_tip(string tip);

    /**
     * Setter pentru pret
     * pret - int
     */
    void set_pret(int pret);

    /**
     * Operator de egalitate
     * ot - Oferta
     * @return bool
     */
    bool operator==(const Oferta& ot) const;

    /**
     * Operator de atribuire
     * ot - Oferta
     */
    void operator=(const Oferta& ot);

    ~Oferta() = default;

};

/*
 * Functii de comparare pentru sortare

 */

/**
 * Functie de comparare pentru sortare dupa denumire
 * of1 - Oferta
 * of2 - Oferta
 */
bool compara_denumire(const Oferta& of1, const Oferta& of2);

/**
 * Functie de comparare pentru sortare dupa destinatie
 * of1 - Oferta
 * of2 - Oferta
 */
bool compara_destinatie(const Oferta& of1, const Oferta& of2);

/**
 * Functie de comparare pentru sortare dupa tip si pret
 * of1 - Oferta
 * of2 - Oferta
 */
bool compara_tip_si_pret(const Oferta& of1, const Oferta& of2);

