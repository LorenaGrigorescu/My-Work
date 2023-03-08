#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


int goToNextPrime(int nr) {
    if (nr == 2) {
        return nr;
    }
    if (nr % 2 == 0) {
        nr++;
    }
    nr -= 2;
    bool isPrime = false;
    while (!isPrime) {
        nr += 2;
        isPrime = true;
        int d;
        for (d = 3; d * d <= nr; d += 2) {
            if (nr % d == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return nr;
}


Colectie::Colectie() {
    /* de adaugat */
    capacity = 7;
    elements = new TElem[capacity];
    for (int i = 0; i < capacity; i++) {
        elements[i] = NULL_TELEM;
    }
    nrElements = 0;
}

int Colectie::h1(TElem elem) const {
    int hash = abs(elem) % capacity;
    return hash;
}

int Colectie::h2(TElem elem) const {
    int hash = 1 + abs(elem) % (capacity - 1);
    return hash;
}


int Colectie::hash(TElem elem, int i) const {
    int hash1 = h1(elem);
    int hash2 = (i * h2(elem)) ;
    int hash =  (hash1 + abs(hash2)% capacity) % capacity;
    return hash;
}


void Colectie::adauga(TElem elem) {
    /* de adaugat */
    int i = 0;
    int hash = this->hash(elem, i);
    while (i < capacity && elements[hash] != NULL_TELEM && elements[hash] != STERS) {
        i++;
        hash = this->hash(elem, i);
    }
    if (i == capacity) {
        resizeAndRehash();
        i = 0;
        hash = this->hash(elem, i);
        while (i < capacity && elements[hash] != NULL_TELEM && elements[hash] != STERS) {
            i++;
            hash = this->hash(elem, i);
        }
    }
    elements[hash] = elem;
    nrElements++;
}

bool Colectie::sterge(TElem elem) {
    /* de adaugat */
    int i = 0;
    int hash = this->hash(elem, i);
    while (i < capacity && elements[hash] != NULL_TELEM) {
        if (elements[hash] == elem) {
            elements[hash] = STERS;
            nrElements--;
            return true;
        }
        i++;
        hash = this->hash(elem, i);
    }
    return false;
}


bool Colectie::cauta(TElem elem) const {
    /* de adaugat */
    int i = 0;
    int hash = this->hash(elem, i);
    while (i < capacity && elements[hash] != NULL_TELEM) {
        if (elements[hash] == elem) {
            return true;
        }
        i++;
        hash = this->hash(elem, i);
    }
    return false;
}


int Colectie::nrAparitii(TElem elem) const {
    /* de adaugat */
    int i = 0;
    int nrApp = 0;
    int hash = this->hash(elem, i);
    while (i < capacity && elements[hash] != NULL_TELEM) {
        if (elements[hash] == elem) {
            nrApp++;
        }
        i++;
        hash = this->hash(elem, i);
    }
    return nrApp;
}

int Colectie::dim() const {
    /* de adaugat */
    return nrElements;
}


bool Colectie::vida() const {
    /* de adaugat */
    return nrElements == 0;
}

IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}

Colectie::~Colectie() {
    /* de adaugat */
    delete[]elements;
}

void Colectie::resizeAndRehash() {
    TElem *oldElements = elements;
    int oldCapacity = capacity;
    capacity *= 2;
    capacity = goToNextPrime(capacity);
    elements = new TElem[capacity];
    for (int i = 0; i < capacity; i++) {
        elements[i] = NULL_TELEM;
    }
    for (int i = 0; i < oldCapacity; i++) {
        TElem current = oldElements[i];
        if (current != NULL_TELEM && current != STERS) {
            int j = 0;
            int hash = this->hash(current, j);
            while (j < capacity && elements[hash] != NULL_TELEM) {
                j++;
                hash = this->hash(current, j);
            }
            elements[hash] = current;
        }
    }
    delete[]oldElements;
}

