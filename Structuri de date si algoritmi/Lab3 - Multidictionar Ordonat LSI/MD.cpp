#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


MD::MD() {
    /* de adaugat */
    head = nullptr;
    this->numar_perechi = 0;
}//BC = WC = Theta(1) = OC


void MD::adauga(TCheie c, TValoare v) {
    /* de adaugat */
    Node *p = head;
    if (head == nullptr) {
        head = new Node;
        head->informatie = make_pair(c, v);
        this->numar_perechi++;
        head->urmator = nullptr;
        return;
    }

    Node *newNode = new Node;
    newNode->informatie = make_pair(c, v);
    newNode->urmator = head;
    head = newNode;
    numar_perechi++;
}//BC=WC=Theta(1) = OC

bool MD::sterge(TCheie c, TValoare v) {
    /* de adaugat */
    if (head == nullptr)
        return false;
    if (head != nullptr and head->informatie.first == c and head->informatie.second == v) {
        Node *copy_head = head->urmator;
        delete head;
        head = copy_head;
        numar_perechi--;
        return true;
    }
    Node *nod_cautat = head;
    Node *previous_nod_cautat = nod_cautat;
    while (nod_cautat != nullptr) {
        if (nod_cautat->informatie.first == c && nod_cautat->informatie.second == v) {
            break;
        }
        previous_nod_cautat = nod_cautat;
        nod_cautat = nod_cautat->urmator;
    }
    if (nod_cautat == nullptr)
        return false;
    previous_nod_cautat->urmator = nod_cautat->urmator;
    numar_perechi--;
    return true;
}//BC=Theta(1), WC=Theta(n) OC = O(n)


vector<TValoare> MD::cauta(TCheie c) const {
    /* de adaugat */
    vector<TValoare> Valori;
    Node *p = head;
    while (p != nullptr) {
        if (p->informatie.first == c)
            Valori.push_back(p->informatie.second);
        p = p->urmator;

    }
    return Valori;
}//BC=WC=Theta(n) = OC

int MD::dim() const {
    /* de adaugat */
    return numar_perechi;
}//BC=WC=Theta(1) = OC
//
//
bool MD::vid() const {
    /* de adaugat */
    if (numar_perechi == 0)
        return true;
    return false;
}//BC=WC=Theta(1) = OC

IteratorMD MD::iterator() const {
    return IteratorMD(*this);
}
//BC=WC=Theta(1) = OC


MD::~MD() {
    /* de adaugat */
    Node *p;
    p = head;
    Node *pointer_precedent;
    while (p != nullptr) {
        pointer_precedent = p;
        p = p->urmator;
        delete pointer_precedent;
    }
}//BC = WC = Theta(n) = OC


int MD::diferentaValoareMaxMin() const {
    if(numar_perechi==0)
        return -1;
    int min=9999999, max=-999999;
    Node* p = head;
    while(p!= nullptr)
    {
        std::pair<TCheie, TValoare> pair = p->informatie;
        if(pair.second<=min)
            min=pair.second;
        if(pair.second>=max)
            max=pair.second;
        p=p->urmator;
    }
    int diferentaMinMax = max-min;
    return diferentaMinMax;
}//BC=WC=Theta(n)=OC

