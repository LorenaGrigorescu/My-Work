//
// Created by Lorena on 20.06.2022.
//

#ifndef EXAMEN_DOMAIN_H
#define EXAMEN_DOMAIN_H

#include <string>

class Melodie {
public:
    int getId() const;

    const std::string &getTitlu() const;

    const std::string &getArtist() const;

    const std::string &getGen() const;

    Melodie(int id, const std::string titlu, const std::string artist, const std::string gen) : id(id), titlu(titlu),
                                                                                             artist(artist),
                                                                                             gen(gen) {};

private:
    int id;
    std::string titlu;
    std::string artist;
    std::string gen;

};

#endif //EXAMEN_DOMAIN_H
