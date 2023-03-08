//
// Created by Lorena on 02.05.2022.
//

#include "exportCVS.h"

void exportToCVS(std::string &file_name, const std::vector<Produs> &produse) {
    std::ofstream out(file_name, std::ios::trunc);
    if (!out.is_open())
        throw MyException("Unable to open the file: " + file_name + "\n");
    for (auto &produs: produse) {
        out << produs.get_numeProdus() << "," << produs.get_tipProdus() << "," << produs.get_pretProdus() << ","
            << produs.get_producatorProdus() << "\n";
    }
    out.close();
}