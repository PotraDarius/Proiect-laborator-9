#include "vector_dinamic.h"
#include <cassert>

void test_redimensionare(){
    VectorDinamic<Oferta> oferte;
    assert(oferte.capacity() == 5);
    Oferta of{1,"Test", "Test", "Test", 400};
    for(int i = 1; i <= 5; i++)
        oferte.push_back(of);
    oferte.push_back(of);
    assert(oferte.capacity() == 10);
}

void test_erase(){
    VectorDinamic<Oferta> oferte;
    assert(oferte.capacity() == 5);
    Oferta of{1,"Test", "Test", "Test", 400};
    for(int i = 1; i <= 5; i++)
        oferte.push_back(of);

    oferte.erase(3);
    assert(oferte.size() == 4);
}

void teste_vector_dinamic(){
    test_erase();
    test_redimensionare();
}