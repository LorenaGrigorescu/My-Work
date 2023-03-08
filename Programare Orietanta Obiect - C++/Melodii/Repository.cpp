//
// Created by Lorena on 20.06.2022.
//

#include <fstream>
#include "Repository.h"
#include <algorithm>
std::vector<Melodie>& Repository::getMelodii() {
    std::sort(melodii.begin(), melodii.end(), [&](const Melodie& m1, const Melodie& m2){return m1.getArtist()<m2.getArtist();});
    return this->melodii;
}

void Repository::loadFromFile() {
    std::ifstream in(path);
    while (!in.eof()) {
        int id;
        in >> id;
        if (in.peek() == std::ifstream::traits_type::eof()) {
            in.close();
            return;
        }
        std::string titlu;
        in >> titlu;
        std::string artist;
        in >> artist;
        std::string gen;
        in >> gen;
        Melodie m{id, titlu, artist, gen};
        melodii.push_back(m);
        if (in.eof()) {
            return;
        }
    }
    in.close();
}

void Repository::writeToFile() {
    std::ofstream out(path);
    for( const Melodie& m: melodii)
    {
        out<<m.getId()<<"\n";
        out<<m.getTitlu()<<"\n";
        out<<m.getArtist()<<"\n";
        out<<m.getGen()<<"\n";
    }
    out.close();
}

bool Repository::adaugaMelodie(Melodie melodie) {
    for(const auto& m:melodii)
    {
        if(m.getId()==melodie.getId())
            return false;
    }
    melodii.push_back(melodie);
    return true;
}

bool Repository::stergeMelodie(int id) {
    int poz = -1;
    for(int i=0; i<melodii.size(); i++)
    {
        if(melodii[i].getId()==id)
        {
            poz = i;
            melodii.erase(melodii.begin()+poz);
            return true;
        }
    }
    return false;
}
