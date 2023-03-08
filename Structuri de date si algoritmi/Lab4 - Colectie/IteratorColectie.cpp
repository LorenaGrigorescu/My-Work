#include <exception>
#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie &c) : col(c) {
    /* de adaugat */
    currentElement = c.head;
    currentFrequency=1;
}

void IteratorColectie::prim() {
    /* de adaugat */
    currentElement = this->col.head;
}


void IteratorColectie::urmator() {
    /* de adaugat */
    if (currentElement == -1)
        throw std::exception();
    currentFrequency++;
    if(currentFrequency>col.informatie[currentElement].second)
    {
        currentElement = this->col.urmator[currentElement];
        currentFrequency=1;
    }
}


bool IteratorColectie::valid() const {
    /* de adaugat */
    if (currentElement == -1)
        return false;
    return true;
}


TElem IteratorColectie::element() const {
    /* de adaugat */
    if (valid())
        return this->col.informatie[currentElement].first;
    return -1;
}
