//
// Created by Lorena on 20.06.2022.
//

#ifndef EXAMEN_SERVICE_H
#define EXAMEN_SERVICE_H


#include "Repository.h"

class Service {
    Repository& repository;
public:
    Service(Repository& repository): repository(repository){};
    std::vector<Melodie> getMelodii();
    /// Metoda adauga o melodie in lista de melodii pe baza atributelor
    /// \param id - (int) : id-ul melodiei pe care vrem sa o adaugam
    /// \param titlu - (string) : titlul piesei pe care vrem sa o adaugam
    /// \param artist - (string) : artistul piesei pe care vrem sa o adaugam
    /// \param gen - (string) : genul melodiei pe care vrem sa o adaugam
    /// \return - True - daca stergerea a fost realizata cu succes, False - in caz contrar sau daca genul acesteia nu se afla in lista de genuri
    bool adaugaMelodie(int id, const std::string& titlu, const std::string& artist, const std::string gen);
    /// Metoda sterge o melodie din lista de melodii pe baza id-ului
    /// \param id - (int) : id-ul pe baza careia vrem sa stergem o melodie
    /// \return - True daca stergerea a fost realizata cu succes, False - in caz contrar
    bool stergeMelodie(int id);
    /// Metoda returneaza cate dintre melodiile din lista au acelasi artist ca si cel dat ca parametru
    /// \param autor - (string) : autorul/artistul melodiei dupa care cautam numarul acestora
    /// \return (int) - numarul  de melodii care au acelasi autor ca cel dat ca parametru
    int acelasiAutor(std::string autor);
    /// Metoda returneaza cate dintre melodiile din lista au acelasi gen ca cel dat ca parametru
    /// \param gen - (string) : genul melodiei dupa care se cauta numarul acestora
    /// \return - (int) :numarul de melodii care au acelasi gen ca cel dat ca parametru
    int acelasiGen(std::string gen);
};


#endif //EXAMEN_SERVICE_H
