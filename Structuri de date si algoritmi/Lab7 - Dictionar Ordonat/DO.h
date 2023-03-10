#pragma once


#include <utility>
#include "Nod.h"
#include "Iterator.h"


typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1


typedef std::pair<TCheie, TValoare> TElem;
class DO;
class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);



class DO {
    friend class Iterator;

private:
    /* aici e reprezentarea */
    Nod* root;
    int nr_elemente;
    Relatie r;

    TValoare adauga_rec(Nod *p, TCheie c, TValoare v);
    TValoare  cautare_rec(Nod*p, TCheie c)const;

public:

    // constructorul implicit al dictionarului

    DO(Relatie r);


    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
    TValoare adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
    TValoare cauta(TCheie c) const;


    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
    TValoare sterge(TCheie c);

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    int dim() const;

    //verifica daca dictionarul e vid
    bool vid() const;

    // se returneaza iterator pe dictionar
    // iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
    Iterator iterator() const;

    Nod* getMaxLeft(Nod*p);

    Nod* getMinRight(Nod*p);

    void DestroyInordine(Nod* curent);
    // destructorul dictionarului
    ~DO();
    //elimina toate elementele din dictionar
    void goleste();
};


