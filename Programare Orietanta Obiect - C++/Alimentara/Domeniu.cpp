//
// Created by Lorena on 29.03.2022.
//

#include "Domeniu.h"


std::string Produs::get_numeProdus() const &{
    return nume_Produs;
}

std::string Produs::get_tipProdus() const &{
    return tip_Produs;

}

int Produs::get_pretProdus() const &{
    return pret_Produs;
}

std::string Produs::get_producatorProdus() const &{
    return producator_Produs;
}

void Produs::set_produs(const int& pret_Produsfinal){
    pret_Produs = pret_Produsfinal;
}

Produs::Produs(const std::string &numeP, const std::string &tipP, int pretP, const std::string &producatorP)
         {

    nume_Produs = numeP;
    tip_Produs = tipP;
    pret_Produs = pretP;
    producator_Produs = producatorP;

}
bool cmpName(const Produs &prod1, const Produs &prod2) {
    if (prod1.get_numeProdus() < prod2.get_numeProdus())
        return true;
    return false;
}

bool cmpNameD(const Produs &prod1, const Produs &prod2) {
    if (prod1.get_numeProdus() > prod2.get_numeProdus())
        return true;
    return false;
}

bool cmpPret(const Produs &prod1, const Produs &prod2) {
    return prod1.get_pretProdus() < prod2.get_pretProdus();
}

bool cmpPretD(const Produs &prod1, const Produs &prod2) {
    return prod1.get_pretProdus() > prod2.get_pretProdus();
}

bool cmpNumeTip(const Produs &prod1, const Produs &prod2) {
    if (prod1.get_numeProdus() == prod2.get_numeProdus()) { return prod1.get_tipProdus() < prod2.get_tipProdus(); }
    else { return prod1.get_numeProdus() < prod2.get_numeProdus(); }
}

bool cmpNumeTipD(const Produs &prod1, const Produs &prod2) {
    if (prod1.get_numeProdus() == prod2.get_numeProdus()) {
        return prod1.get_tipProdus() > prod2.get_tipProdus();
    } else {
        return prod1.get_numeProdus() > prod2.get_numeProdus();
    }
}

