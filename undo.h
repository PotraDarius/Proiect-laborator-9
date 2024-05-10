#pragma once
#include "repository.h"

/**
 * @brief Clasa abstracta pentru undo
 *
 */
class ActiuneUndo{
public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;
};


/**
 * @brief Clasa pentru undo la adaugare
 *
 */
class UndoAdauga: public ActiuneUndo{
private:
    Oferta oferta_adaugata;
    RepoGeneric & repo;
public:
    UndoAdauga(RepoGeneric & repo, const Oferta& of): repo{repo}, oferta_adaugata{of}{}

    /**
     * @brief Se sterge oferta adaugata
     *
     */
    void doUndo() override{
        repo.del_oferta(oferta_adaugata.get_id());
    }
};

/**
 * @brief Clasa pentru undo la stergere
 *
 */
class UndoSterge: public ActiuneUndo{
private:
    Oferta oferta_stearsa;
    RepoGeneric & repo;
public:
    UndoSterge(RepoGeneric & repo, const Oferta& of): repo{repo}, oferta_stearsa{of} {}

    /**
     * @brief Se adauga oferta stearsa
     *
     */
    void doUndo() override{
        repo.store_oferta(oferta_stearsa);
    }
};

/**
 * @brief Clasa pentru undo la modificare
 *
 */
class UndoModifica: public ActiuneUndo{
private:
    int id;
    Oferta oferta_modificata;
    RepoGeneric & repo;
public:
    UndoModifica(RepoGeneric & repo, const Oferta& of, const int& id): repo{repo},
    oferta_modificata{of}, id{id}{}

    /**
     * @brief Se modifica inapoi oferta modificata
     *
     */
    void doUndo() override{
        repo.modificare_oferta(id, oferta_modificata);
    }
};
