//
// Created by Lorena on 29.03.2022.
//

#include "UI.h"

void Console_UI::adaugare_UI() {

    std::string numeProdus;
    std::string tipProdus;
    std::string pretProdus;
    std::string producatorProdus;

    std::cout << "Introduceti numele produsului: ";
    std::cin >> numeProdus;
    std::cout << "\n";
    std::cout << "Introduceti tipul produsului: ";
    std::cin >> tipProdus;
    std::cout << "\n";
    std::cout << "Introduceti pretul produsului: ";
    std::cin >> pretProdus;
    std::cout << "\n";
    std::cout << "Introduceti producatorul produsului: ";
    std::cin >> producatorProdus;

    bool rezultat_a = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);
    if (rezultat_a)
        std::cout << "Adaugare realizata cu succes!\n";
}

void Console_UI::stergere_UI() {
    std::string numeProdus;
    std::cout << "Introduceti numele produsului: ";
    std::cin >> numeProdus;

    bool rezultat_s = Serv_Magazin.stergeProdus_Service(numeProdus);
    if (rezultat_s)
        std::cout << "Stergere efectuata cu succes!\n";
}

void Console_UI::cautare_UI() {
    std::string numeProdus;
    std::cout << "Introduceti numele produsului pe care vreti sa il cautati: ";
    std::cin >> numeProdus;

    bool rezultat_c = Serv_Magazin.stergeProdus_Service(numeProdus);
    if (rezultat_c)
        std::cout << "Elementul a fost gasit!\n";
    else std::cout << "Elementul nu a fost gasit!\n";
}

void Console_UI::modificare_pret_UI() {
    std::string numeProdus;
    std::string pretProdusfinal;

    std::cout << "Introduceti numele produsului pe care vreti sa il modificati: ";
    std::cin >> numeProdus;
    std::cout << "\n";
    std::cout << "Introduceti pretul final pe care doriti sa il aiba produsul: ";
    std::cin >> pretProdusfinal;

    bool rezultat_m = Serv_Magazin.modificarePretProdus_Service(numeProdus, pretProdusfinal);
    if (rezultat_m)
        std::cout << "Pretul produsului cautat a fost modificat cu succes!\n";
    else std::cout << "Obiectul nu a fost gasit sau pretul final este identic cu cel initial.\n";
}


void Console_UI::filtrare_dupa_camp_UI(std::string camp) {
    if (camp == "pret") {
        int pret_filtrare;
        std::cout << "Introduceti pretul de filtrare: ";
        std::cin >> pret_filtrare;
        auto filterCopy = this->Serv_Magazin.filtrarePret(pret_filtrare);
        for (auto &produs: filterCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    } else if (camp == "nume") {
        std::string nume_filtrare;
        std::cout << "Introduceti numele dupa care vreti sa filtrati: ";
        std::cin >> nume_filtrare;
        auto filterCopy = this->Serv_Magazin.filtrareNume(nume_filtrare);
        for (auto &produs: filterCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";

    } else if (camp == "producator") {
        std::string producator_filtrare;
        std::cout << "Introduceti producatorul dupa vreti sa filtrsti: ";
        std::cin >> producator_filtrare;
        auto filterCopy = this->Serv_Magazin.filtrareProducator(producator_filtrare);
        for (auto &produs: filterCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    }
}

void Console_UI::sortare_dupa_nume_UI() {
    int sorting_option;
    std::cout << "Introduceti optiunea de sortare (1 - ascendent, 0 - descendent): ";
    std::cin >> sorting_option;
    std::cout << "\n";
    if (sorting_option == 1) {
        auto sortedCopy = this->Serv_Magazin.sort_by_nume();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    } else if (sorting_option == 0) {
        auto sortedCopy = this->Serv_Magazin.sort_by_numeD();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    }
}

void Console_UI::sortare_dupa_pret_UI() {
    int sorting_option;
    std::cout << "Introduceti optiunea de sortare (1 - ascendent, 0 - descendent): ";
    std::cin >> sorting_option;
    std::cout << "\n";
    if (sorting_option == 1) {
        auto sortedCopy = this->Serv_Magazin.sort_by_pret();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    } else if (sorting_option == 0) {
        auto sortedCopy = this->Serv_Magazin.sort_by_pretD();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    }

}

void Console_UI::sortare_dupa_nume_tip_UI() {
    int sorting_option;
    std::cout << "Introduceti optiunea de sortare (1 - ascendent, 0 - descendent): ";
    std::cin >> sorting_option;
    std::cout << "\n";
    if (sorting_option == 1) {
        auto sortedCopy = this->Serv_Magazin.sort_by_nume_tip();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    } else if (sorting_option == 0) {
        auto sortedCopy = this->Serv_Magazin.sort_by_nume_tipD();
        for (auto &produs: sortedCopy)
            std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                      << "Tip produs: " << produs.get_tipProdus() << "\n"
                      << "Pret produs: " << produs.get_pretProdus() << "\n"
                      << "Producator produs: " << produs.get_producatorProdus() << "\n";
    }
}

void Console_UI::division_by2_UI() {

    bool result_allof = Serv_Magazin.allof_function();
    if (result_allof)
        std::cout << "Toate produsele au pretul un numar par.\n";
    else
        std::cout << "Nu toate produsele au pretul un numar par.\n";
}

void Console_UI::printare_UI() {
    for (int i = 0; i < this->Serv_Magazin.get_all().size(); i++)
        std::cout << "Nume produs: " << this->Serv_Magazin.get_all()[i].get_numeProdus() << "\n"
                  << "Tip produs: " << this->Serv_Magazin.get_all()[i].get_tipProdus() << "\n"
                  << "Pret produs: " << this->Serv_Magazin.get_all()[i].get_pretProdus() << "\n"
                  << "Producator produs: " << this->Serv_Magazin.get_all()[i].get_producatorProdus() << "\n";

}

void Console_UI::addProdusCos_UI() {
    int suma_cos = 0;
    int capacitate_initiala = Serv_Magazin.ToateDinCos().size();
    std::string numeProdus;
    std::string tipProdus;
    int pretProdus;
    std::string producatorProdus;

    std::cout << "Introduceti numele produsului: ";
    std::cin >> numeProdus;
    std::cout << "\n";
    std::cout << "Introduceti tipul produsului: ";
    std::cin >> tipProdus;
    std::cout << "\n";
    std::cout << "Introduceti pretul produsului: ";
    std::cin >> pretProdus;
    std::cout << "\n";
    std::cout << "Introduceti producatorul produsului: ";
    std::cin >> producatorProdus;

    this->Serv_Magazin.addToCos(numeProdus, tipProdus, pretProdus, producatorProdus);
    std::vector<Produs> cos = this->Serv_Magazin.ToateDinCos();
    for (Produs &produs: cos)
        suma_cos += produs.get_pretProdus();
    std::cout << "Suma produselor din cos este: " << suma_cos << "\n";
}

void Console_UI::addRandom_UI() {
    int capacitate;
    int suma_cos = 0;
    std::cout << "Introduceti numarul de elemente pe care vreti sa il adaugati in cos:\n";
    std::cin >> capacitate;
    this->Serv_Magazin.addRandom(capacitate);
//    this->cos = cos1;
    std::vector<Produs> cos = this->Serv_Magazin.ToateDinCos();
    for (auto &produs: cos)
        suma_cos += produs.get_pretProdus();
    std::cout << "Suma produselor din cos este: " << suma_cos << "\n";
}

void Console_UI::goleste_cos_UI() {
    this->Serv_Magazin.golesteCos();
    int suma_cos = 0;
    std::cout << "Suma tuturor produselor adaugate in cos este: " << suma_cos << "\n";
}

void Console_UI::Toate_Din_Cos_UI() {
    std::vector<Produs> cos = this->Serv_Magazin.ToateDinCos();
    for (auto &produs: cos)
        std::cout << "Nume produs: " << produs.get_numeProdus() << "\n"
                  << "Tip produs: " << produs.get_tipProdus() << "\n"
                  << "Pret produs: " << produs.get_pretProdus() << "\n"
                  << "Producator produs: " << produs.get_producatorProdus() << "\n";
}

void Console_UI::Undo_UI() {
    this->Serv_Magazin.undo();
}

void Console_UI::ExportCVS_UI() {
    std::string file_name;
    std::cout << "Introducteti numele fisierului in care doriti sa exportati cosul de cumparaturi:\n";
    std::cin >> file_name;
    this->Serv_Magazin.exportaCosCVS(file_name);
}

void Console_UI::print_menu_UI() {
    std::cout << "1-Adaugare produs\n";
    std::cout << "2-Stergere produs\n";
    std::cout << "3-Cautare produs\n";
    std::cout << "4-Modificare pret produs\n";
    std::cout << "5-Filtrare dupa camp (nume, pret, productor)\n";
    std::cout << "6-Sortare dupa nume 1 - ascendent, 0 - descendent\n";
    std::cout << "7-Sortare dupa pret 1 - ascendent, 0 - descendent\n";
    std::cout << "8-Sortare dupa nume+tip 1 - ascendent, 0 - descendent\n";
    std::cout << "9-Printarea produselor\n";
    std::cout << "10-All of function\n";
    /// Operatii pe cos
    std::cout << "11-Adauga produs in cos\n";
    std::cout << "12-Adauga produse random produse in cos\n";
    std::cout << "13-Golirea intregului cos\n";
    std::cout << "14-Toate elementele din cos\n";
    std::cout << "15-Operatie de undo\n";
    std::cout << "16-Exportarea cosului de cumparaturi\n";
}

void Console_UI::run_UI() {
    std::string cmd;
    while (true) {
        try {
            this->print_menu_UI();
            std::cin >> cmd;
            if (cmd == "1") {
                this->adaugare_UI();
            } else if (cmd == "2") {
                this->stergere_UI();
            } else if (cmd == "3") {
                this->cautare_UI();
            } else if (cmd == "4") {
                this->modificare_pret_UI();
            } else if (cmd == "5") {
                std::string camp;
                std::cout << "Introduceti numele campului dupa care vreti sa filtrati(nume, pret, producator): ";
                std::cin >> camp;
                std::cout << "\n";
                this->filtrare_dupa_camp_UI(camp);
            } else if (cmd == "6") {
                this->sortare_dupa_nume_UI();
            } else if (cmd == "7") {
                this->sortare_dupa_pret_UI();
            } else if (cmd == "8") {
                sortare_dupa_nume_tip_UI();
            } else if (cmd == "9") {
                printare_UI();
            } else if (cmd == "10") {
                division_by2_UI();
            } else if (cmd == "11") {
                addProdusCos_UI();
            } else if (cmd == "12") {
                addRandom_UI();
            } else if (cmd == "13") {
                goleste_cos_UI();
            } else if (cmd == "14") {
                Toate_Din_Cos_UI();
            } else if (cmd == "15") {
                Undo_UI();
                std::cout << "Operatia de undo realizata cu succes!\n";
            } else if (cmd == "16") {
                ExportCVS_UI();
                std::cout << "Cosul a fost exportat in fisier!\n";
            } else if (cmd == "0") {
                return;
            } else std::cout << "Comanda invalida!\n";
        } catch (MyException &e) {
            std::cout << e.getErrorMessage();
        }
    }
}






