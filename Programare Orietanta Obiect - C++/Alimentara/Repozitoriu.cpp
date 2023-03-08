//
// Created by Lorena on 29.03.2022.
//

#include <algorithm>
#include "Repozitoriu.h"

Repozitoriu_Magazin::Repozitoriu_Magazin() {
    lista_produse = std::vector<Produs>();
    insertProducts();
}

std::vector<Produs> Repozitoriu_Magazin::get_lista() const &{
    return lista_produse;
}

bool Repozitoriu_Magazin::adaugaProdus(const Produs &produs) {
    bool ok_adaugare_produs = false;
//    for (int i = 0; i < lista_produse.size(); i++)
//        if (lista_produse[i].get_numeProdus() == produs.get_numeProdus()) {
//            ok_adaugare_produs = true;
//            break;
//        }
    for (auto &produs1: lista_produse)
        if (produs1.get_numeProdus() == produs.get_numeProdus()) {
            ok_adaugare_produs = true;
            break;
        }
    if (ok_adaugare_produs)
        return false;
    else {
        lista_produse.push_back(produs);
        this->notify();
        return true;
    }
}

bool Repozitoriu_Magazin::stergeProdus(const std::string &nume_Produs) {
    bool ok_obiect_cautat = false;
    int i = 0, pozitie_stergere_obiect = 0;
//    if(nume_Produs.empty())
//        throw MyException("Numele este invalid!");
    for (auto &produs: lista_produse) {
        if (produs.get_numeProdus() == nume_Produs) {
            ok_obiect_cautat = true;
            pozitie_stergere_obiect = i;
            break;
        } else i++;
    }
    if (!ok_obiect_cautat)
        return false;
    else {
        Produs produs = lista_produse[pozitie_stergere_obiect];
        lista_produse[pozitie_stergere_obiect] = lista_produse[lista_produse.size() - 1];
        lista_produse[lista_produse.size() - 1] = produs;
        lista_produse.pop_back();
        this->notify();
        return true;
    }
}

bool Repozitoriu_Magazin::cautareProdus(const std::string &numeProdus) {
    bool ok_cauta = false;
    for (auto &produs: lista_produse) {
        auto iterator = std::find_if(lista_produse.begin(), lista_produse.end(), [&numeProdus](const Produs &produs) {
            return produs.get_numeProdus() == numeProdus;
        });
        if (iterator < lista_produse.end()) {
            ok_cauta = true;
            break;
        }
        ok_cauta = false;
    }
    return ok_cauta;
}

bool Repozitoriu_Magazin::modificare_pretProdus(const std::string &numeProdus, const int &pretProdus_final) {
    bool ok_schimbare_pret = false;
    for (auto &produs: lista_produse) {
        auto iterator = std::find_if(lista_produse.begin(), lista_produse.end(), [&numeProdus](const Produs &produs) {
            return produs.get_numeProdus() == numeProdus;
        });
        if (iterator < lista_produse.end()) {
            ok_schimbare_pret = true;
            iterator->set_produs(pretProdus_final);
            this->notify();
            break;
        }
        ok_schimbare_pret = false;
    }
    return ok_schimbare_pret;
}

void Repozitoriu_Magazin::insertProducts() {
    this->adaugaProdus(Produs{"paine", "integrala", 6, "velpitar"});
    this->adaugaProdus(Produs{"gem", "caise", 5, "mandy"});
    this->adaugaProdus(Produs{"muraturi", "asortate", 10, "olympia"});
    this->adaugaProdus(Produs{"mustar", "cu hrean", 3, "bunica"});
    this->adaugaProdus(Produs{"ciocolata", "neagra", 12, "finetti"});
    this->adaugaProdus(Produs{"branza", "topita", 9, "delaco"});
    this->adaugaProdus(Produs{"sare", "de mare", 7, "olympia"});
    this->adaugaProdus(Produs{"pate", "vegetal", 3, "mandy"});
    this->adaugaProdus(Produs{"biscuiti", "integrali", 15, "velpitar"});
    this->adaugaProdus(Produs{"cereale", "cu miere", 11, "fitness"});
}

void Repozitoriu_Magazin_File::loadFromFile() {
    std::ifstream in(file_name);
    if (!in.is_open())
//        return;
    { throw MyException("Unable to open file: " + file_name + "\n"); }

    while (!in.eof()) {
        std::string nume_produs;
        in >> nume_produs;
        std::string tip_produs;
        in >> tip_produs;
        int pret_produs;
        if (in.eof()) break;
        std::string producator_produs;
        in >> producator_produs;
        Produs produs{nume_produs.c_str(), tip_produs.c_str(), pret_produs, producator_produs.c_str()};
        Repozitoriu_Magazin::adaugaProdus(produs);
    }
    in.close();
}

void Repozitoriu_Magazin_File::writeToFile() {
    std::ofstream out(file_name);
//    if(!out.is_open())
//    {
//        std::string msg("Unable to open file: " + file_name+"\n");
//        throw MyException(msg);}
    for (auto &produs: get_lista()) {
        out << produs.get_numeProdus();
        out << std::endl;
        out << produs.get_tipProdus();
        out << std::endl;
        out << produs.get_pretProdus();
        out << std::endl;
        out << produs.get_producatorProdus();
        out << std::endl;
    }
    out.close();
}

bool Repozitoriu_Magazin::existaProducator(const std::string &producator_Produs) {
    for (auto &produs: this->lista_produse) {
        if (produs.get_producatorProdus() == producator_Produs) {
            return true;
        }
    }
    return false;

}
