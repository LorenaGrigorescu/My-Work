//
// Created by Lorena on 26.04.2022.
//

#ifndef MAGAZIN_LAB8_9_COSMAGAZIN_H
#define MAGAZIN_LAB8_9_COSMAGAZIN_H

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include "Domeniu.h"
#include "Observer.h"

class CosMagazin: public Observable {
    std::vector<Produs> Cos_Magazin;
public:
    CosMagazin() = default;

    /*functia adauga un produs in cos*/
    void adauga_Cos(const Produs &produs);

    /*functia goleste intregul cos*/
    void goleste_Cos();

    /*functia adauga produse in mod aleator in cos*/
    void umple_Cos(size_t capacitate, std::vector<Produs> all);

    /*functia returneaza lista cu produse din cos*/
    const std::vector<Produs>& get_Cos_Magazin();
};


#endif //MAGAZIN_LAB8_9_COSMAGAZIN_H
