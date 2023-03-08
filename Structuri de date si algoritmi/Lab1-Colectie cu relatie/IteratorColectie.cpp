#include <exception>
#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie &c) : col(c) {
    /* de adaugat */
    this->index = 0;
    this->frecventaCurenta = 1;
}

TElem IteratorColectie::element() const {
    /* de adaugat */
    if (this->index == this->col.dimensiune_colectie) {
        throw std::exception();
    }
    return this->col.lista_elemente[this->index].first;
}

bool IteratorColectie::valid() const {
    /* de adaugat */
    if (this->index < this->col.numarPerechi) {
        return true;
    } else {
        return false;
    }
}

void IteratorColectie::urmator() {
    /* de adaugat */
    if (this->index == this->col.numarPerechi) {
        throw std::exception();
    } else {
        if (this->frecventaCurenta < this->col.lista_elemente[this->index].second) {
            this->frecventaCurenta++;
        } else {
            this->index++;
            this->frecventaCurenta = 1;
        }
    }
}

void IteratorColectie::prim() {
    /* de adaugat */
    this->index = 0;
    this->frecventaCurenta = 1;
}
