#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    /* de adaugat */
    curent=0;
    deplasare();
}

void IteratorColectie::prim() {
    /* de adaugat */
    curent=0;
    deplasare();
}


void IteratorColectie::urmator() {
    /* de adaugat */
    if(!valid())
        throw std::exception();
    curent++;
    deplasare();
}


bool IteratorColectie::valid() const {
    /* de adaugat */
    return (curent<col.capacity);
}



TElem IteratorColectie::element() const {
    /* de adaugat */
    if(!valid())
        throw std::exception();
    return col.elements[curent];
}

void IteratorColectie::deplasare() {
    while ((curent<col.capacity) && col.elements[curent]==NULL_TELEM)
        curent++;
}
