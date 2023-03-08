//
// Created by Lorena on 20.06.2022.
//

#include "Domain.h"

int Melodie::getId() const {
    return id;
}

const std::string &Melodie::getTitlu() const {
    return titlu;
}

const std::string &Melodie::getArtist() const {
    return artist;
}

const std::string &Melodie::getGen() const {
    return gen;
}
