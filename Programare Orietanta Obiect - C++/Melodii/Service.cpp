//
// Created by Lorena on 20.06.2022.
//

#include "Service.h"

std::vector<Melodie> Service::getMelodii() {
    return this->repository.getMelodii();
}

bool Service::adaugaMelodie(int id, const std::string &titlu, const std::string &artist, const std::string gen) {
    if(gen!="pop" && gen!="rock" && gen!="folk" && gen!="disco")
        return false;
    Melodie m{id, titlu, artist, gen};
    return this->repository.adaugaMelodie(m);
}

bool Service::stergeMelodie(int id) {
    return this->repository.stergeMelodie(id);
}

int Service::acelasiAutor(std::string autor) {
    int count = 0;
    for(const auto& m: this->getMelodii())
    {
        if(m.getArtist()==autor)
        {
            count++;
        }
    }
    return count;
}

int Service::acelasiGen(std::string gen) {
    int count = 0;
    for(const auto& m: this->getMelodii())
    {
        if(m.getGen()==gen)
        {
            count++;
        }
    }
    return count;
}
