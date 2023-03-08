//
// Created by Lorena on 26.04.2022.
//

#include "CosMagazin.h"

void CosMagazin::adauga_Cos(const Produs &produs) {
    Cos_Magazin.push_back(produs);
    this->notify();

}

void CosMagazin::goleste_Cos() {
    Cos_Magazin.clear();
    this->notify();

}

void CosMagazin::umple_Cos(size_t capacitate, std::vector<Produs> toateProdusele) {
//    std::shuffle(toateProdusele.begin(), toateProdusele.end(), std::default_random_engine(std::random_device{}()));
    int count = 0;
    while (count < capacitate /*&& toateProdusele.size() > 0*/) {
        count++;
        std::shuffle(toateProdusele.begin(), toateProdusele.end(), std::default_random_engine(std::random_device{}()));
        Produs P = toateProdusele.back();
        Cos_Magazin.push_back(P);
//        toateProdusele.pop_back();
    }
    this->notify();

}

const std::vector<Produs>& CosMagazin::get_Cos_Magazin() {
    return this->Cos_Magazin;
}
