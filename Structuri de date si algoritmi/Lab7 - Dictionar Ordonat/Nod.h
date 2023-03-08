//
// Created by Lorena on 29.05.2022.
//

#ifndef LAB7SDA_NOD_H
#define LAB7SDA_NOD_H

#include <utility>

typedef int TCheie;
typedef int TValoare;
#define NULL_TVALOARE -1

typedef std::pair<TCheie, TValoare> TElem;

class Nod {
private:
    TElem e;
    Nod *stanga;
    Nod *dreapta;
    Nod *parinte;
public:
    Nod() {
        e.first = NULL_TVALOARE;
        e.second = NULL_TVALOARE;
        this->parinte = nullptr;
        this->dreapta = nullptr;
        this->stanga = nullptr;
    }

    friend class DO;

    friend class Iterator;
    ~Nod()=default;
};


#endif //LAB7SDA_NOD_H
