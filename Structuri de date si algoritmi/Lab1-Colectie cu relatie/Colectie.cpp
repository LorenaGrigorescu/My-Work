#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    /* de adaugat */
    if (e1 <= e2)
        return true;
    return false;
}

Colectie::Colectie() {
    capacitate_colectie = 5;
    dimensiune_colectie = 0;
    numarPerechi = 0;
    lista_elemente = new std::pair<TElem, int>[capacitate_colectie];
    /* de adaugat */
}

void Colectie::adauga(TElem e) {
    /* de adaugat */
    int i = 0;
    int pozitie_inserare = 0;
    if (numarPerechi == capacitate_colectie - 1)
        redimensionare();

    while (i < this->numarPerechi) {
        if (this->lista_elemente[i].first == e) {
            this->lista_elemente[i].second++;
            this->dimensiune_colectie++;
            return;
        }
        if (rel(this->lista_elemente[i].first, e))
            pozitie_inserare++;
        else break;
        i++;
    }

    //daca relatia accepta egalitate, elemntul pe care il adaugam poate sa fie pe pozitia imediat precedenta valorii pozitie_inserare
    //altfel, daca relatia nu accepta

    for (i = this->numarPerechi; i > pozitie_inserare; i--) {
        lista_elemente[i].first = lista_elemente[i - 1].first;
        lista_elemente[i].second = lista_elemente[i - 1].second;
    }
    lista_elemente[pozitie_inserare].first = e;
    lista_elemente[pozitie_inserare].second = 1;
    numarPerechi++;

    dimensiune_colectie++;

}


bool Colectie::sterge(TElem e) {
    /* de adaugat */
    int i, pozitie_stergere = 0;
    bool ok_de_sters = false;
    for (i = 0; i < numarPerechi; i++)
        if (this->lista_elemente[i].first == e) {
            ok_de_sters = true;
            pozitie_stergere = i;
            break;
        }
    if (!ok_de_sters)
        return false;
    if (lista_elemente[pozitie_stergere].second == 1) {
        for (i = pozitie_stergere; i < numarPerechi - 1; i++) {
            lista_elemente[i].first = lista_elemente[i + 1].first;
            lista_elemente[i].second = lista_elemente[i + 1].second;
        }
        numarPerechi--;
    } else if (lista_elemente[pozitie_stergere].second > 1)
        lista_elemente[pozitie_stergere].second--;
    dimensiune_colectie--;
    return true;

}


bool Colectie::cauta(TElem elem) const {
    /* de adaugat */
    int i = 0;
    bool ok = false;
    for (i = 0; i < numarPerechi; i++)
        if (this->lista_elemente[i].first == elem) {
            ok = true;
            break;
        }
    return ok;
}


int Colectie::nrAparitii(TElem elem) const {
    /* de adaugat */
    int i = 0;
    for (i = 0; i < numarPerechi; i++) {
        if (lista_elemente[i].first == elem) {
            return lista_elemente[i].second;
        }
    }
    return 0;
}


int Colectie::dim() const {
    /* de adaugat */
    return dimensiune_colectie;
}


bool Colectie::vida() const {
    /* de adaugat */
    return dimensiune_colectie == 0;
}

void Colectie::redimensionare() {
    /* de adaugat*/
    capacitate_colectie *= 2;
    auto *lista_elemente_new = new std::pair<TElem, int>[capacitate_colectie];
    for (int i = 0; i < capacitate_colectie / 2; i++) lista_elemente_new[i] = lista_elemente[i];

    delete[] lista_elemente;
    lista_elemente = lista_elemente_new;


}

IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}


Colectie::~Colectie() {
    /* de adaugat */
}
