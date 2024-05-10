#pragma once

#include "domain.h"

template <typename ElemType>
class Iterator;

template <typename ElemType>
class VectorDinamic{
private:
    int capacitate;
    int nr_elemente;
    Oferta * oferte;

    void redimensionare();

public:

    /**
     * Constructor pentru clasa VectorDinamic
     */
    VectorDinamic();

    /**
     * Constructor de copiere pentru clasa VectorDinamic
     * @param ot - VectorDinamic
     */
    VectorDinamic(const VectorDinamic& ot);

    /**
     * Destructor pentru clasa VectorDinamic
     */
    ~VectorDinamic();

    /**
     * Operator de atribuire pentru clasa VectorDinamic
     * ot - VectorDinamic
     * @return VectorDinamic
     */
    VectorDinamic& operator=(const VectorDinamic& ot);

    /**
     * Constructor de mutare pentru clasa VectorDinamic
     * ot - VectorDinamic
     */
    VectorDinamic(VectorDinamic&& ot) noexcept;

    /**
     * Operator de mutare pentru clasa VectorDinamic
     * ot - VectorDinamic
     * @return VectorDinamic
     */
    VectorDinamic& operator=(VectorDinamic&& ot) noexcept;

    /**
     * Functie care sterge elementul de pe pozitia poz
     * poz - int
     */
    void erase(int poz);

    /**
     * Functie care adauga un element la sfarsitul vectorului
     * of - ElemType
     */
    void push_back(const ElemType& of);

    /**
     * Functie care seteaza elementul de pe pozitia poz cu of
     * poz - int
     * of - ElemType
     */
    void set(int poz, const ElemType& of);

    /**
     * Functie care interschimba elementele de pe pozitiile poz1 si poz2
     * poz1 - int
     * poz2 - int
     */
    void swap(int poz1, int poz2);

    /**
     * Functie care returneaza elementul de pe pozitia poz
     * poz - int
     * @return ElemType
     */
    ElemType& get(int poz) const;

    /**
     * Functie care returneaza numarul de elemente din vector
     * @return int
     */
    int size() const noexcept;

    /**
     * Functie care returneaza capacitatea vectorului
     * @return int
     */
    int capacity() const noexcept;

    /**
     * Functie care verifica daca vectorul este gol
     * @return bool
     */
    bool empty() const noexcept;


    friend class Iterator<ElemType>;

    /**
     * Functie care returneaza un iterator la inceputul vectorului
     * @return Iterator
     */
    Iterator<ElemType> begin();

    /**
     * Functie care returneaza un iterator la sfarsitul vectorului
     * @return Iterator
     */
    Iterator<ElemType> end();

};

template <typename ElemType>
class Iterator{
private:
    const VectorDinamic<ElemType>& vec;
    int poz = 0;
public:
    /**
     * Constructor pentru clasa Iterator
     * vec - VectorDinamic
     */
    explicit Iterator(const VectorDinamic<ElemType>& vec) noexcept;

    /**
     * Constructor pentru clasa Iterator
     * vec - VectorDinamic
     * poz - int
     */
    Iterator(const VectorDinamic<ElemType>& vec, int poz) noexcept;

    /**
     * Functie care verifica daca iteratorul este valid
     * @return bool
     */
    bool valid() const;

    /**
     * Functie care returneaza elementul de pe pozitia poz
     * @return ElemType
     */
    ElemType& element() const noexcept;

    /**
     * Functie care trece la urmatorul element
     */
    void next() noexcept;

    /**
     * Operator de dereferentiere
     * @return ElemType
     */
    ElemType& operator*() const;

    /**
     * Operator de incrementare
     * @return Iterator
     */
    Iterator& operator++();

    /**
     * Operator de egalitate
     * ot - Iterator
     * @return bool
     */
    bool operator==(const Iterator& ot)  const noexcept;

    /**
     * Operator de inegalitate
     * ot - Iterator
     * @return bool
     */
    bool operator!=(const Iterator& ot) const noexcept;
};

///Iterator functions
template <typename ElemType>
Iterator<ElemType>::Iterator(const VectorDinamic<ElemType> &vec) noexcept : vec{vec} {}

template <typename ElemType>
Iterator<ElemType>::Iterator(const VectorDinamic<ElemType> &vec, int poz) noexcept : vec{vec}, poz{poz} {}

template <typename ElemType>
bool Iterator<ElemType>::valid() const {
    return poz < vec.nr_elemente;
}
template <typename ElemType>
ElemType &Iterator<ElemType>::element() const noexcept {
    return vec.get(poz);
}

template <typename ElemType>
void Iterator<ElemType>::next() noexcept {
    poz++;

}

template <typename ElemType>
ElemType &Iterator<ElemType>::operator*() const {
    return element();
}

template <typename ElemType>
Iterator<ElemType> &Iterator<ElemType>::operator++() {
    next();
    return *this;
}

template <typename ElemType>
bool Iterator<ElemType>::operator==(const Iterator &ot) const noexcept {
    return poz == ot.poz;
}

template <typename ElemType>
bool Iterator<ElemType>::operator!=(const Iterator &ot) const noexcept {
    return !(*this == ot);
}


///Vector dinamic functions

template <typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(): capacitate{5}, nr_elemente{0}, oferte{new Oferta[5]} {

}

template <typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(const VectorDinamic &ot){
    oferte = new ElemType[ot.capacitate];
    for(int i = 0; i < ot.nr_elemente; i++){
        oferte[i] = ot.oferte[i];
    }
    nr_elemente = ot.nr_elemente;
    capacitate = ot.capacitate;
}

template <typename ElemType>
VectorDinamic<ElemType>::~VectorDinamic() {
    delete[] oferte;
}

template <typename ElemType>
VectorDinamic<ElemType> &VectorDinamic<ElemType>::operator=(const VectorDinamic &ot) {
    if(this == &ot){
        return *this;
    }

    delete[] oferte;
    oferte = new ElemType[ot.capacitate];
    for(int i = 0; i < ot.nr_elemente; i++)
        oferte[i] = ot.oferte[i];
    capacitate = ot.capacitate;
    nr_elemente = ot.nr_elemente;
    return *this;
}

template <typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(VectorDinamic &&ot) noexcept {
    oferte = ot.oferte;
    capacitate = ot.capacitate;
    nr_elemente = ot.nr_elemente;

    ot.oferte = nullptr;
    ot.capacitate = 0;
    ot.nr_elemente = 0;
}

template <typename ElemType>
VectorDinamic<ElemType> &VectorDinamic<ElemType>::operator=(VectorDinamic &&ot) noexcept {
    if(this == &ot)
        return *this;

    delete[] oferte;
    oferte = ot.oferte;
    capacitate = ot.capacitate;
    nr_elemente = ot.nr_elemente;

    ot.oferte = nullptr;
    ot.capacitate = 0;
    ot.nr_elemente = 0;

    return *this;

}

template <typename ElemType>
void VectorDinamic<ElemType>::push_back(const ElemType &of) {
    redimensionare();
    oferte[nr_elemente++] = of;
}

template <typename ElemType>
void VectorDinamic<ElemType>::set(int poz, const ElemType &of) {
    oferte[poz] = of;
}

template <typename ElemType>
ElemType &VectorDinamic<ElemType>::get(int poz) const {
    return oferte[poz];
}

template <typename ElemType>
int VectorDinamic<ElemType>::size() const noexcept {
    return nr_elemente;
}

template <typename ElemType>
int VectorDinamic<ElemType>::capacity() const noexcept {
    return capacitate;
}


template <typename ElemType>
void VectorDinamic<ElemType>::redimensionare() {
    if(nr_elemente < capacitate)
        return;

    capacitate *= 2;
    Oferta* aux = new ElemType[capacitate];
    for(int i = 0; i < nr_elemente; i++)
        aux[i] = oferte[i];

    delete[] oferte;
    oferte = aux;
}


template <typename ElemType>
void VectorDinamic<ElemType>::erase(int poz) {
    for(int i = poz; i < nr_elemente-1; i++)
        oferte[i] = oferte[i+1];

    nr_elemente--;
}

template <typename ElemType>
void VectorDinamic<ElemType>::swap(int poz1, int poz2) {
    Oferta aux = this->get(poz1);
    this->set(poz1, this->get(poz2));
    this->set(poz2, aux);
}

template <typename ElemType>
bool VectorDinamic<ElemType>::empty() const noexcept {
    return nr_elemente == 0;
}
template <typename ElemType>
Iterator<ElemType> VectorDinamic<ElemType>::begin() {
    return Iterator(*this);
}

template <typename ElemType>
Iterator<ElemType> VectorDinamic<ElemType>::end() {
    return Iterator(*this, nr_elemente);
}


void test_redimensionare();
void test_erase();
void teste_vector_dinamic();