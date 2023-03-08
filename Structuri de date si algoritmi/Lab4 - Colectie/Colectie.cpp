#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
    /* de adaugat */
    capacitate = 10;
    informatie = new std::pair<TElem, int>[capacitate];
    urmator = new int[capacitate];
    anterior = new int[capacitate];
    head = -1;
    tail = -1;
    firstEmpty = 0;
    nrElem = 0;
    for (int i = 0; i < capacitate; i++) {
        urmator[i] = i + 1;
        anterior[i] = i - 1;
        informatie[i] = std::make_pair(NULL_TELEM, 0);
    }
    urmator[capacitate - 1] = -1;
}


void Colectie::adauga(TElem elem) {
    /* de adaugat */
    int copy_head = head;
    while (copy_head != -1) {
        if (informatie[copy_head].first == elem) {
            informatie[copy_head].second++;
            nrElem++;
            return;
        }
        copy_head = urmator[copy_head];
    }
    if (firstEmpty == -1)
        resize();
    if (head == -1) {
        head = firstEmpty;
        firstEmpty = urmator[firstEmpty];
        informatie[head] = std::make_pair(elem, 1);
        anterior[head] = -1;
        urmator[head] = -1;
        tail = head;
    } else {
        informatie[firstEmpty].first = elem;
        informatie[firstEmpty].second = 1;
        urmator[tail] = firstEmpty;
        anterior[firstEmpty] = tail;
        tail = firstEmpty;
        firstEmpty = urmator[firstEmpty];
        urmator[tail] = -1;
    }
    nrElem++;
    if (firstEmpty != -1)
        anterior[firstEmpty] = -1;
}


bool Colectie::sterge(TElem elem) {
    /* de adaugat */
    int copy_head = head;
    while (copy_head != -1) {
        if (informatie[copy_head].first == elem) {
            break;
        }
        copy_head = urmator[copy_head];
    }

    if (copy_head == -1) {
        return false;
    }
    if (informatie[copy_head].second > 1) {
        informatie[copy_head].second--;
        nrElem--;
        return true;
    } else if (copy_head == head) {
        head = urmator[head];
        anterior[head] = -1;
    } else if (copy_head == tail) {
        tail = anterior[copy_head];
        urmator[tail] = -1;
    } else {
        urmator[anterior[copy_head]] = urmator[copy_head];
        anterior[urmator[copy_head]] = anterior[copy_head];
    }
    anterior[copy_head] = -1;
    urmator[copy_head] = firstEmpty;
    anterior[firstEmpty] = copy_head;
    firstEmpty = copy_head;
//    int copy_firstEmpty = firstEmpty;
//    while (copy_firstEmpty < copy_head) {
//        copy_firstEmpty = urmator[copy_firstEmpty];
//    }
//    urmator[copy_head] = copy_firstEmpty;
//    anterior[copy_head] = anterior[copy_firstEmpty];
//    anterior[copy_firstEmpty] = copy_head;
//    if (copy_firstEmpty == firstEmpty) {
//        firstEmpty = copy_head;
//    }
    informatie[copy_head].first = NULL_TELEM;
    informatie[copy_head].second = 0;
    nrElem--;
    return true;

//    if (informatie[head].first == elem) {
//        if (informatie[head].second == 1) {
//            head = -1;
//            anterior[head] = -1;
//            urmator[head] = -1;
//            tail = -1;
//            nrElem--;
//        } else {
//            informatie[head].second--;
//        }
//        return true;
//    }
//    int copy_head = head;
//    while (copy_head != -1) {
//        if (informatie[copy_head].first == elem) {
//            if (informatie[copy_head].second > 1) {
//                informatie[copy_head].second--;
//                return true;
//            } else {
//                anterior[copy_head] = firstEmpty;
//                urmator[copy_head] = urmator[firstEmpty];
//                nrElem--;
//                return true;
//            }
//        }
//        if (informatie[tail].first == elem) {
//            if (informatie[tail].second > 1) {
//                informatie[tail].second--;
//                return true;
//            } else {
//                anterior[tail] = firstEmpty;
//                urmator[tail] = -1;
//                nrElem--;
//                return true;
//            }
//        }
//        copy_head = urmator[copy_head];
//    }
//    return false;
}


bool Colectie::cauta(TElem elem) const {
    /* de adaugat */
    int copy_head = head;
    while (copy_head != -1) {
        if (informatie[copy_head].first == elem)
            return true;
        copy_head = urmator[copy_head];
    }
    return false;
}

int Colectie::nrAparitii(TElem elem) const {
    /* de adaugat */
    int copy_head = head;
    while (copy_head != -1) {
        if (informatie[copy_head].first == elem)
            return informatie[copy_head].second;
        copy_head = urmator[copy_head];
    }
    return 0;
}


int Colectie::dim() const {
    /* de adaugat */
    return nrElem;
}


bool Colectie::vida() const {
    /* de adaugat */
    if (nrElem == 0)
        return true;
    return false;
}

IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}


Colectie::~Colectie() {
    /* de adaugat */
    delete[] informatie;
    delete[] urmator;
//    delete[]anterior;
}

void Colectie::resize() {
    capacitate = 2 * capacitate;
    std::pair<TElem, int> *informatie_copy = new std::pair<TElem, int>[capacitate];
    int *urmator_copy = new int[capacitate];
    int *anterior_copy = new int[capacitate];
    int copy_head = head;
    for(int i=0; i<capacitate/2; i++) {
        informatie_copy[i] = informatie[i];
        urmator_copy[i] = urmator[i];
        anterior_copy[i] = anterior[i];
    }
    delete[]informatie;
    delete[]urmator;
    //delete[]anterior;
    informatie = informatie_copy;
    urmator = urmator_copy;
    anterior = anterior_copy;
    firstEmpty = capacitate / 2;
    for (int i = capacitate / 2; i < capacitate; i++) {
        urmator[i] = i + 1;
        anterior[i] = i - 1;
        informatie[i] = std::make_pair(NULL_TELEM, 0);
    }
    anterior[capacitate/2]=-1;
    urmator[capacitate - 1] = -1;
}


