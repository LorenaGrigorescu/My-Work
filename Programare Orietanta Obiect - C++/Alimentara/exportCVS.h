//
// Created by Lorena on 02.05.2022.
//

#ifndef MAGAZIN_LAB8_9_EXPORTCVS_H
#define MAGAZIN_LAB8_9_EXPORTCVS_H
#include <string>
#include <vector>
#include "Domeniu.h"
#include <fstream>
#include "Exceptions.h"

void exportToCVS(std::string& file_name, const std::vector<Produs>& produse);
#endif //MAGAZIN_LAB8_9_EXPORTCVS_H
