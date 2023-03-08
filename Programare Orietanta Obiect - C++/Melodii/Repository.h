//
// Created by Lorena on 20.06.2022.
//

#ifndef EXAMEN_REPOSITORY_H
#define EXAMEN_REPOSITORY_H

#include <string>
#include <vector>
#include "Domain.h"

class Repository {
    std::string path;
    std::vector<Melodie> melodii;

    void loadFromFile();

    void writeToFile();

public:
    std::vector<Melodie>& getMelodii();

    Repository(std::string path) : path(path) {loadFromFile();};
    /// Metoda adauga o melodie in lista de melodii
    /// \param m - Melodie : melodia care trebuie adaugata
    /// \return True - daca melodia a fost adaugata cu succes, False in caz contrar
    bool adaugaMelodie(Melodie m);
    /// Metoda sterge o melodie din lista de melodii pe baza id-ului
    /// \param id - int : id-ul dupa care se sterge melodia
    /// \return True - daca melodia a fost stearsa cu succes, False in caz contrar
    bool stergeMelodie(int id);
    ~Repository(){writeToFile();};
};

#endif //EXAMEN_REPOSITORY_H
