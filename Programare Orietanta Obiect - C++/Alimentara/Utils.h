//
// Created by Lorena on 30.03.2022.
//

#ifndef MAGAZIN_LAB6_7_UTILS_H
#define MAGAZIN_LAB6_7_UTILS_H
#include <cstring>
#include <string>
#include "Domeniu.h"
/*conversia unui un string numeric in int*/
int conversie_in_int(std::string s);

/*functia returneaza true daca numele produsului 1 este mai mic lexicografic decat cel al celui de-al doilea*/
/*functia returneaza true daca tipul produsului 1 este mai mic lexicografic decat cel al celui de-al doilea*/
bool compare_nume_tip(const Produs& produs1, const Produs& produs2);


/*functia returneaza true daca tipul produsului 1 este mai mic lexicografic decat cel al celui de-al doilea*/

#endif //MAGAZIN_LAB6_7_UTILS_H
