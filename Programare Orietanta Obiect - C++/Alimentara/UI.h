//
// Created by Lorena on 30.03.2022.
//

#ifndef MAGAZIN_LAB6_7_UI_H
#define MAGAZIN_LAB6_7_UI_H

#include "Service.h"
#include <iostream>
#include "Exceptions.h"

class Console_UI {
private:
    Service_Magazin &Serv_Magazin;
//    std::vector<Produs> cos;
public:
    /*constructorul consolei*/
    Console_UI(Service_Magazin &Serv_Magazin) : Serv_Magazin(Serv_Magazin) {}

    /*adaugare produs*/
    void adaugare_UI();

    /*stergere produs*/
    void stergere_UI();

    /*cautare produs*/
    void cautare_UI();

    /*modificare pret produs*/
    void modificare_pret_UI();

    /*filtrare dupa camp*/
    void filtrare_dupa_camp_UI(std::string camp);

    /*sortare dupa nume*/
    void sortare_dupa_nume_UI();

    /*sortare dupa pret*/
    void sortare_dupa_pret_UI();

    /*sortare dupa nume+tip*/
    void sortare_dupa_nume_tip_UI();

    /*functia testeaza daca preturile tuturor produselor sunt numere pare*/
    void division_by2_UI();

    /*printarea tuturor produselor*/
    void printare_UI();


    void print_menu_UI();

    void addProdusCos_UI();

    void addRandom_UI();

    void goleste_cos_UI();

    void Toate_Din_Cos_UI();

    void Undo_UI();

    void ExportCVS_UI();

    void run_UI();


};

#endif //MAGAZIN_LAB6_7_UI_H
