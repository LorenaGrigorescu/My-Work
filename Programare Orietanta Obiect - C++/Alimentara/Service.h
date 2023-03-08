//
// Created by Lorena on 29.03.2022.
//

#ifndef MAGAZIN_LAB6_7_SERVICE_H
#define MAGAZIN_LAB6_7_SERVICE_H

#include "Repozitoriu.h"
#include "Validatori.h"
#include "Utils.h"
#include "algorithm"
#include <functional>
#include "Exceptions.h"
#include "CosMagazin.h"
#include "Undo.h"
#include <memory>
#include "exportCVS.h"

using std::unique_ptr;


using std::function;


class Service_Magazin {
private:
    CosMagazin &cos_magazin;
    Repozitoriu_Magazin &Repo_Magazin;

//    std::vector<Produs> filter(function<bool(const Produs &)> fct);

    std::vector<Produs> generalSort(bool(*MaiMicF)(const Produs &, const Produs &));

    std::vector<unique_ptr<ActiuneUndo>> undoActions;

public:
    /*constructorul clasei*/
    Service_Magazin(Repozitoriu_Magazin &Repo_Magazin, CosMagazin &cosMagazin);

    /*adaugare produs in service
     * returneaza true daca adaugarea a reusit
     * returneaza false daca obiectul este deja existent*/
    bool adaugareProdus_Service(std::string &numeProdus, std::string &tipProdus, std::string &pretProdus,
                                std::string &producatorProdus);

    /*sterge produs din service
     * returneaza true daca stergerea a avut loc
     * returneaza false daca obiectul a fost sters inainte*/
    bool stergeProdus_Service(std::string &numeProdus);

    /*cauta produs in service
     * returneaza true daca obiectul a fost gasit
     * returneaza false in caz contrar*/
    bool cautareProdus_Service(std::string &numeProdus);


    /*modifica pretul unui produs in service
     * returneaza true daca modificare a avut loc cu succes
     * returneaza false daca obiectul nu exista sau pretul cu care se modifica este acelasi cu cel initial*/
    bool modificarePretProdus_Service(std::string &numeProdus, std::string &pretProdusfinal);

    /*functia returneaza lista de obiecte*/
    std::vector<Produs> get_all() const &;

    /*functia sorteaza o lista  crescator dupa nume*/
    std::vector<Produs> sort_by_nume();

    /*functia sorteaza o lista descrescator dupa nume*/
    std::vector<Produs> sort_by_numeD();

    /*functia sorteaza o lista  crescator dupa pret*/
    std::vector<Produs> sort_by_pret();

    /*functia sorteaza o lista descrescator dupa pret*/
    std::vector<Produs> sort_by_pretD();

    /*functia sorteaza crescator o lista dupa nume si tip*/
    std::vector<Produs> sort_by_nume_tip();

    /*functia sorteaza descrescator o lista dupa nume si tip*/
    std::vector<Produs> sort_by_nume_tipD();

    /*functia returneaza o lista cu obiectele care au un pret dat*/
    std::vector<Produs> filtrarePret(int pret);

    /*functia returneaza o lista cu obiectele care au un anumit nume*/
    std::vector<Produs> filtrareNume(std::string nume);

    /*functia returneaza o lista cu obiectele care au un anumit producator*/
    std::vector<Produs> filtrareProducator(std::string producator);

    /*functia testeaza daca produsele au acelasi producator*/
    bool allof_function();

    //Operatii pe COS

    void addToCos(const std::string &nume_produs, const std::string &tip_produs, int pret_produs,
                  const std::string &producator_produs);

    void addRandom(int capacitate);

    void golesteCos();

    const std::vector<Produs> &ToateDinCos();

    //Operatia de Undo
    void undo();

    //Export to CVS
    void exportaCosCVS(std::string file_name);

    bool existaProducator(std::string &producatorProdus);

    CosMagazin& getCos();
};

#endif //MAGAZIN_LAB6_7_SERVICE_H
