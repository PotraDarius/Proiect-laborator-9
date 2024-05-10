#pragma once
#include "service.h"

class UI
{
private:
    Service& service;
    static void adauga_oferta(Service& serv);
    static void sterge_oferta(Service& serv);
    static void modifica_oferta(Service& serv);
    static void afiseaza_oferte(Service& serv);
    static void afiseaza_oferte_dupa_destinatie(Service& serv);
    static void afiseaza_oferte_dupa_pret(Service& serv);
    static void afiseaza_oferte_sortate_dupa_denumire(Service& serv);
    static void afiseaza_oferte_sortate_dupa_destinatie(Service& serv);
    static void afiseaza_oferte_sortate_dupa_tip_si_pret(Service& serv);
    static void afiseaza_oferta_dupa_destinatie(Service& serv);
    void UI_wishlist();
    static void adauga_in_wishlist(Service &serv);
    static void genereaza_oferte_random(Service &serv);
    static void goleste_wishlist(Service &serv);
    static void afiseaza_wishlist(Service &serv);
    static void exportare(Service &serv);
    static void genereaza_rapot(Service &serv);

public:
    explicit UI(Service& serv);
    void run();
};
