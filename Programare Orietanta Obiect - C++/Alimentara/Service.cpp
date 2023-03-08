//
// Created by Lorena on 29.03.2022.
//

#include "Service.h"

Service_Magazin::Service_Magazin(Repozitoriu_Magazin &Repo_Magazin, CosMagazin &cosMagazin) : Repo_Magazin{
        Repo_Magazin}, cos_magazin{cosMagazin} {}

bool Service_Magazin::adaugareProdus_Service(std::string &numeProdus, std::string &tipProdus,
                                             std::string &pretProdus, std::string &producatorProdus) {
    try {
        Validare_produs(numeProdus, tipProdus, pretProdus, producatorProdus);
    } catch (MyException &e) {
        throw MyException(e.getErrorMessage());
    }
    int pret_Produs = conversie_in_int(pretProdus);
    Produs produs = Produs(numeProdus, tipProdus, pret_Produs, producatorProdus);
    bool ok_adaugare = this->Repo_Magazin.adaugaProdus(produs);
    undoActions.push_back(std::make_unique<UndoAdauga>(Repo_Magazin, produs));
    return ok_adaugare;

}

bool Service_Magazin::stergeProdus_Service(std::string &numeProdus) {
    bool ok_validare = true;
    if(numeProdus.empty())
        throw MyException("Numele este invalid!");
//    if (numeProdus.empty())
//        ok_validare = false;
    if (ok_validare) {
        for (auto &produs: Repo_Magazin.get_lista())
            if (produs.get_numeProdus() == numeProdus) {
                Produs produs_sters = produs;
                undoActions.push_back(std::make_unique<UndoSterge>(Repo_Magazin, produs_sters));
                break;
            }
        bool ok_stergere = this->Repo_Magazin.stergeProdus(numeProdus);
        return ok_stergere;
    }

    return false;
}

bool Service_Magazin::cautareProdus_Service(std::string &numeProdus) {
    bool ok_validare = true;
    if (numeProdus.empty())
        ok_validare = false;
    if (ok_validare)
        return this->Repo_Magazin.cautareProdus(numeProdus);
    return false;
}

bool Service_Magazin::modificarePretProdus_Service(std::string &numeProdus, std::string &pretProdusfinal) {
    if (numeProdus.empty()) {
        return false;
    }
    if (pretProdusfinal.empty()) {
        return false;
    } else {
        for (char i: pretProdusfinal)
            if (i != '0' and i != '1' and i != '2' and i != '3' and i != '4' and
                i != '5' and i != '6' and i != '7' and i != '8' and i != '9') {
                throw MyException("Pretul trebuie sa fie un int >0");
            }
    }
    int pret_Produs_final = conversie_in_int(pretProdusfinal);
    int pret_initial =0;
    std::string nume_produs = numeProdus;
    for(auto &produs: this->get_all())
        if(produs.get_numeProdus()==numeProdus)
        {
            pret_initial=produs.get_pretProdus();
            nume_produs=numeProdus;
            break;
        }
    undoActions.push_back(std::make_unique<UndoModificaPret>(Repo_Magazin, pret_initial, nume_produs));
    return this->Repo_Magazin.modificare_pretProdus(numeProdus, pret_Produs_final);
}

std::vector<Produs> Service_Magazin::get_all() const &{
    return this->Repo_Magazin.get_lista();
}

std::vector<Produs> Service_Magazin::sort_by_nume() {
    auto sortedCopy = Repo_Magazin.get_lista();
    sort(sortedCopy.begin(), sortedCopy.end(), cmpName);
    return sortedCopy;}

std::vector<Produs> Service_Magazin::sort_by_numeD() {
    auto sortedCopy = Repo_Magazin.get_lista();
    sort(sortedCopy.begin(), sortedCopy.end(), cmpNameD);
    return sortedCopy;}

std::vector<Produs> Service_Magazin::sort_by_pret() {
    auto sortedCopy = Repo_Magazin.get_lista();
    sort(sortedCopy.begin(), sortedCopy.end(), cmpPret);
    return sortedCopy;}

std::vector<Produs> Service_Magazin::sort_by_pretD() {
    auto sortedCopy = Repo_Magazin.get_lista();
    sort(sortedCopy.begin(), sortedCopy.end(), cmpPretD);
    return sortedCopy;}


std::vector<Produs> Service_Magazin::sort_by_nume_tip() {

    return generalSort(cmpNumeTip);
}

std::vector<Produs> Service_Magazin::sort_by_nume_tipD() {
    return generalSort(cmpNumeTipD);
}

//std::vector<Produs> Service_Magazin::filter(function<bool(const Produs &)> fct) {
//    std::vector<Produs> filteredProducts;
//    for (const auto &produs: Repo_Magazin.get_lista()) {
//        if (fct(produs))
//            filteredProducts.push_back(produs);
//    }
//    return filteredProducts;
//
//}

std::vector<Produs> Service_Magazin::generalSort(bool (*MaiMicF)(const Produs &, const Produs &)) {
    std::vector<Produs> produse{Repo_Magazin.get_lista()};
    for (size_t i = 0; i < produse.size(); i++) {
        for (size_t j = i + 1; j < produse.size(); j++) {
            if (!MaiMicF(produse[i], produse[j])) {
                Produs aux = produse[i];
                produse[i] = produse[j];
                produse[j] = aux;
            }

        }
    }
    return produse;}

std::vector<Produs> Service_Magazin::filtrarePret(int pret) {
//    return filter([=](const Produs &produs) { return produs.get_pretProdus() == pret; });
    std::vector<Produs> lista_produse = this->get_all();
    std::vector<Produs> filteredPrice(lista_produse.size());
    auto iterator = std::copy_if(lista_produse.begin(), lista_produse.end(), filteredPrice.begin(),
                                 [&pret](const Produs &produs) { return produs.get_pretProdus() == pret; });
    filteredPrice.resize(std::distance(filteredPrice.begin(), iterator));
    return filteredPrice;
}

std::vector<Produs> Service_Magazin::filtrareNume(std::string nume) {
//    return filter([nume](const Produs &produs) { return produs.get_numeProdus() == nume; });
    std::vector<Produs> lista_produse = this->get_all();
    std::vector<Produs> filteredNume(lista_produse.size());
    auto iterator = std::copy_if(lista_produse.begin(), lista_produse.end(), filteredNume.begin(),
                                 [&nume](const Produs &produs) { return produs.get_numeProdus() == nume; });
    filteredNume.resize(std::distance(filteredNume.begin(), iterator));
    return filteredNume;
}

std::vector<Produs> Service_Magazin::filtrareProducator(std::string producator) {
//    return filter([producator](const Produs &produs) { return produs.get_producatorProdus() == producator; });
    std::vector<Produs> lista_produse = this->get_all();
    std::vector<Produs> filteredProducator(lista_produse.size());
    auto iterator = std::copy_if(lista_produse.begin(), lista_produse.end(), filteredProducator.begin(),
                                 [&producator](const Produs &produs) {
                                     return produs.get_producatorProdus() == producator;
                                 });
    filteredProducator.resize(std::distance(filteredProducator.begin(), iterator));
    return filteredProducator;
}

bool Service_Magazin::allof_function() {
    std::vector<Produs> products = this->get_all();
    if (std::all_of(products.begin(), products.end(),
                    [](const Produs &produs) { return produs.get_pretProdus() % 2 == 1; }))
        return true;
    return false;
}

void Service_Magazin::addToCos(const std::string &nume_produs, const std::string &tip_produs, int pret_produs,
                               const std::string &producator_produs) {
    if (this->Repo_Magazin.cautareProdus(nume_produs) == 1) {
        const Produs &produs = Produs{nume_produs, tip_produs, pret_produs, producator_produs};
        cos_magazin.adauga_Cos(produs);
    }

}

void Service_Magazin::addRandom(int capacitate) {
    cos_magazin.umple_Cos(capacitate, this->get_all());
}

void Service_Magazin::golesteCos() {
    cos_magazin.goleste_Cos();
}

const std::vector<Produs> &Service_Magazin::ToateDinCos() {
    return cos_magazin.get_Cos_Magazin();
}

void Service_Magazin::undo() {
    if (undoActions.empty())
        throw MyException("Nu mai exista operatii!\n");
    undoActions.back()->doUndo();
    undoActions.pop_back(); //iau dintr-o lista si il pun a doua
}

void Service_Magazin::exportaCosCVS(std::string file_name) {
    exportToCVS(file_name, cos_magazin.get_Cos_Magazin());
}

bool Service_Magazin::existaProducator(std::string &produsProducator) {
    return this->Repo_Magazin.existaProducator(produsProducator);
}

CosMagazin &Service_Magazin::getCos() {
    return cos_magazin;
}

