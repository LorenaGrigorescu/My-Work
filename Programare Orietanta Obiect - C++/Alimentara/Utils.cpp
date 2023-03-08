//
// Created by Lorena on 30.03.2022.
//

#include "Utils.h"
int conversie_in_int(std::string s)
{
    int numar = 0;
    for(char i : s)
    {
        int cifra = i-'0';
        numar = numar*10+cifra;
    }
    return numar;
}

bool compare_nume_tip(const Produs& produs1, const Produs& produs2)
{
    if( produs1.get_numeProdus()!=produs2.get_numeProdus())
        return produs1.get_numeProdus()<produs2.get_numeProdus();
    return produs1.get_tipProdus()<produs2.get_tipProdus();


}
