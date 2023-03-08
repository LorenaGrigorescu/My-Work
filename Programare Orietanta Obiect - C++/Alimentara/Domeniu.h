//
// Created by Lorena on 29.03.2022.
//


#ifndef MAGAZIN_LAB6_7_DOMENIU_H
#define MAGAZIN_LAB6_7_DOMENIU_H

#include <string>
#include <cstring>

class Produs {
private:
    std::string nume_Produs;
    std::string tip_Produs;
    int pret_Produs;
    std::string producator_Produs;
public:
    /*metoda reprezinta constructorul clasei*/
    Produs(const std::string &numeP, const std::string &tipP, int pretP, const std::string &producatorP);
    Produs() = default;
    Produs(const Produs &ot)
    {
        this->nume_Produs = ot.nume_Produs;
        this->tip_Produs = ot.tip_Produs;
        this->pret_Produs = ot.pret_Produs;
        this->producator_Produs = ot.producator_Produs;
    }

//    Produs(const Produs& produs);

    /*metoda returneaza numele produsului*/
    std::string get_numeProdus() const &;

    /*metoda returneaza tipul produsului*/
    std::string get_tipProdus() const &;

    /*metoda returneaza pretul produsului*/
    int get_pretProdus() const &;

    /*metoda returneaza producatorul produsului*/
    std::string get_producatorProdus() const &;

    /*metoda seteaza pretul unui produs*/
    void set_produs(const int& pret_Produsfinal);

};
/*compara doua produse dupa nume - ascendent*/
bool cmpName(const Produs &prod1, const Produs &prod2);

/*compara doua produse dupa nume - descendent*/
bool cmpNameD(const Produs &prod1, const Produs &prod2);

/*compara doua produse dupa pret - ascendent*/
bool cmpPret(const Produs &prod1, const Produs &prod2);

/*compara doua produse dupa pretul lor - descendent*/
bool cmpPretD(const Produs &prod1, const Produs &prod2);

/*compara doua produse dupa nume (initial) si daca au acelasi nume, dupa tip - ascendent*/
bool cmpNumeTip(const Produs &prod1, const Produs &prod2);

/*compara doua produse dupa nume (initial) si daca au acelasi nume, dupa tip - descendent*/
bool cmpNumeTipD(const Produs& prod1, const Produs &prod2);

/*metoda verifica daca pretul unui produs este la fel cu unul dat*/
bool EqualName(const Produs &produs, std::string nume_produs);

#endif //MAGAZIN_LAB6_7_DOMENIU_H
