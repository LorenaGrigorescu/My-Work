//
// Created by Lorena on 29.03.2022.
//

#ifndef MAGAZIN_LAB6_7_REPOZITORIU_H
#define MAGAZIN_LAB6_7_REPOZITORIU_H

#include <vector>
#include "Domeniu.h"
#include <string>
#include <algorithm>
#include <fstream>
#include "Exceptions.h"
#include "Observer.h"

class Repozitoriu_Magazin: public Observable {
private:
    std::vector<Produs> lista_produse;
public:
    /*constructorul repozitorului*/
    Repozitoriu_Magazin();

    virtual ~Repozitoriu_Magazin() = default;


    /*constructorul clasei Repo*/
    std::vector<Produs> get_lista() const &;

    /*metoda adauga un obiect in lista
     * returneaza true daca obiectul a fost adaugat
     * returneaza false daca obiectul a fost deja adaugat inainte*/
    virtual bool adaugaProdus(const Produs &produs);

    /*metoda sterge un obiect din lista
     * returneaza true daca obiectul a fost sters cu succes
     * returneaza false daca obiectul nu exista sau a fost sters inainte*/
    virtual bool stergeProdus(const std::string &nume_Produs);

    /*metoda cauta un obiect in lista dupa numele lui
     * returneaza true dac obiectul a fost gasit
     * returneaza false incaz contrar*/
    bool cautareProdus(const std::string &numeProdus);

    /*metoda modifica pretul unui obiect in lista cautat dupa nume
     * returneaza  true daca modificarea s-a facut
     * returneaza false in caz contrar*/
    bool modificare_pretProdus(const std::string &numeProdus, const int &pretProdus_final);
    bool existaProducator(const std::string &producator_Produs);
    void insertProducts();

};

class Repozitoriu_Magazin_File : public Repozitoriu_Magazin {
private:
    std::string file_name;

    void loadFromFile();

    void writeToFile();

public:
    Repozitoriu_Magazin_File(std::string file_name) : Repozitoriu_Magazin(), file_name{file_name} {
        loadFromFile();
    }

    bool adaugaProdus(const Produs &produs) override {
        Repozitoriu_Magazin::adaugaProdus(produs);
        writeToFile();
        return true;
    }

    bool stergeProdus(const std::string &nume_Produs) override {
        Repozitoriu_Magazin::stergeProdus(nume_Produs);
        writeToFile();
        return true;
    }

    ~Repozitoriu_Magazin_File() override { writeToFile(); }

};

#endif //MAGAZIN_LAB6_7_REPOZITORIU_H
