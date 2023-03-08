//
// Created by Lorena on 29.03.2022.
//

#include "Validatori.h"
#include "Exceptions.h"

void Validare_produs(std::string nume_Podus, std::string tip_Produs, std::string pret_Produs,
                     std::string producator_Produs) {
    std::string errorMessage;
    if (nume_Podus.empty()) {
        errorMessage += "Numele produsului nu poate fi gol!\n";
    }
    if (tip_Produs.empty()) {
        errorMessage += "Tipul produsului nu poate fi gol!\n";
    }
    if (pret_Produs.empty()) {
        errorMessage += "Pretul produsului nu poate fi gol!\n";
    }
    else {
        for (char i: pret_Produs) {
            if (i != '0' and i != '1' and i != '2' and i != '3' and i != '4' and
                i != '5' and i != '6' and i != '7' and i != '8' and i != '9') {
                errorMessage += "Pretul trebuie sa fie un int >= 0!\n";
                break;
            }
        }
    }
    if (producator_Produs.empty()) {
        errorMessage += "Producatorul produsului nu poate fi gol!\n";
    }
    if (!errorMessage.empty()) {
        throw MyException(errorMessage);
    }
}
