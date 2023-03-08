#include "Iterator.h"
#include "DO.h"
#include <iostream>
#include <exception>

using namespace std;

DO::DO(Relatie r) {
    /* de adaugat */
    this->r = r;
    this->root = nullptr;
    this->nr_elemente = 0;
}
//BC=WC=Theta(1)
//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
    /* de adaugat */
    if (this->root == nullptr) {
        Nod *p = new Nod;
        p->e.first = c;
        p->e.second = v;
        this->root = p;
        this->nr_elemente++;
        return NULL_TVALOARE;
    } else {
        int rez = adauga_rec(this->root, c, v);
        if (rez == NULL_TVALOARE)
            nr_elemente++;
        return rez;
    }
}
//BC = Theta(1), WC = Theta(n) => O(n)
//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare DO::cauta(TCheie c) const {
    /* de adaugat */
    return cautare_rec(this->root, c);
}
//BC = Theta(1), WC = Theta(n)=>O(n)
//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
    /* de adaugat */
    if (nr_elemente == 0){
        return NULL_TVALOARE;
    }
    if (this->nr_elemente == 1) {
        if (this->root->e.first == c) {
            this->nr_elemente = 0;
            int valoare = this->root->e.second;
            delete root;
            this->root = nullptr;
            return valoare;
        } else { return NULL_TVALOARE; }
    } else {
        if (this->root->e.first == c) {
            if (this->root->stanga != nullptr && this->root->dreapta != nullptr) {
                Nod *p = getMaxLeft(root->stanga);
                int valoare = this->root->e.second;
                this->root->e.first = p->e.first;
                this->root->e.second = p->e.second;
                if (p == p->parinte->stanga) { p->parinte->stanga = nullptr; }
                else { p->parinte->dreapta = nullptr; }
                nr_elemente--;
                delete p;
                return valoare;
            }
            else if(this->root->dreapta != nullptr)
            {
                int valoare = this->root->e.second;
                Nod *newroot = this->root->dreapta;
                delete root;
                newroot->parinte= nullptr;
                this->root=newroot;
                nr_elemente--;
                return valoare;
            }
            else if(this->root->stanga!= nullptr)
            {
                int valoare = this->root->e.second;
                Nod *newroot = this->root->stanga;
                delete root;
                newroot->parinte= nullptr;
                this->root=newroot;
                nr_elemente--;
                return  valoare;
            }
        }
        Nod *head = this->root;
        while (head != nullptr) {
            if (head->e.first == c) {
                if (head->stanga == nullptr && head->dreapta == nullptr) {
                    if (head->parinte->stanga == head) {
                        head->parinte->stanga = nullptr;
                        int valoare = head->e.second;
                        delete head;
                        nr_elemente--;
                        return valoare;
                    } else if (head->parinte->dreapta == head) {
                        head->parinte->dreapta = nullptr;
                        int valoare = head->e.second;
                        delete head;
                        nr_elemente--;
                        return valoare;
                    }
                } else if ((head->stanga == nullptr && head->dreapta != nullptr) ||
                           (head->dreapta == nullptr && head->stanga !=
                                                        nullptr)) {
                    if (head->stanga == nullptr && head->dreapta != nullptr) {
                        if (head->parinte->dreapta == head) {
                            head->parinte->dreapta = head->dreapta;
                            int valoare = head->e.second;
                            head->dreapta->parinte = head->parinte;
                            delete head;
                            nr_elemente--;
                            return valoare;
                        } else if (head->parinte->stanga == head) {
                            head->parinte->stanga = head->dreapta;
                            int valoare = head->e.second;
                            head->dreapta->parinte = head->parinte;
                            delete head;
                            nr_elemente--;
                            return valoare;
                        }
                    } else if (head->stanga != nullptr && head->dreapta == nullptr) {
                        if (head->parinte->dreapta == head) {
                            head->parinte->dreapta = head->stanga;
                            int valoare = head->e.second;
                            head->stanga->parinte = head->parinte;
                            delete head;
                            nr_elemente--;
                            return valoare;
                        } else if (head->parinte->stanga == head) {
                            head->parinte->stanga = head->stanga;
                            int valoare = head->e.second;
                            head->stanga->parinte = head->parinte;
                            delete head;
                            nr_elemente--;
                            return valoare;
                        }
                    }
                } else if (head->stanga != nullptr && head->dreapta != nullptr) {
                    Nod *radacina = this->getMaxLeft(head->stanga);
                    int valoare = head->e.second;
                    head->e.first = radacina->e.first;
                    head->e.second = radacina->e.second;
                    if (radacina->parinte->stanga == radacina) {
                        radacina->parinte->stanga = nullptr;
                    } else if (radacina->parinte->dreapta == radacina) {
                        radacina->parinte->dreapta = nullptr;
                    }
                    delete radacina;
                    nr_elemente--;
                    return valoare;
                }
            } else if (this->r(c, head->e.first)) { head = head->stanga; }
            else if (!this->r(c, head->e.first)) { head = head->dreapta; }
        }
    }
    return NULL_TVALOARE;
}//BC = Theta(1), WC= Theta(n) => O(n)
//daca este frunza -> tai conexiune cu parinte (stanga sau dreapta) si sa sterg nodul cu informatia
//daca este nod cu un singur descendent leg descendentul de parintele nodului ce trebuie sters
// daca are 2 descendenti ->


//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
    /* de adaugat */
    return this->nr_elemente;
}//BC = WC = Theta(1)

//verifica daca dictionarul e vid
bool DO::vid() const {
    /* de adaugat */
    if (this->root != nullptr)
        return false;
    return true;
}
//BC = WC = Theta(1)
Iterator DO::iterator() const {
    return Iterator(*this);
}
//BC = WC = Theta(1)
DO::~DO() {
    /* de adaugat */
    DestroyInordine(this->root);
}
//BC = Theta(n),  WC = Theta(n) => Theta(n)
TValoare DO::adauga_rec(Nod *p, TCheie c, TValoare v) {

    if (p->e.first == c) {
        TValoare val = p->e.second;
        p->e.second = v;
        return val;
    }
    if (this->r(c, p->e.first)) {
        if (p->stanga == nullptr) {
            Nod *adaugat = new Nod;
            adaugat->e.first = c;
            adaugat->e.second = v;
            adaugat->parinte = p;
            p->stanga = adaugat;
            return NULL_TVALOARE;
        } else {
            return adauga_rec(p->stanga, c, v);
        }
    } else {
        if (p->dreapta == nullptr) {
            Nod *adaugat = new Nod;
            adaugat->e.first = c;
            adaugat->e.second = v;
            adaugat->parinte = p;
            p->dreapta = adaugat;
            return NULL_TVALOARE;
        } else {
            return adauga_rec(p->dreapta, c, v);
        }
    }
}//BC = Theta(1), WC = Theta(n) => O(n)


TValoare DO::cautare_rec(Nod *p, TCheie c) const {
    if (p == nullptr)
        return NULL_TVALOARE;
    if (p->e.first == c) {
        return p->e.second;
    }
    if (this->r(c, p->e.first)) {
        return cautare_rec(p->stanga, c);
    } else { return cautare_rec(p->dreapta, c); }
}
//BC = Theta(1), WC = Theta(h)=>O(h)

Nod *DO::getMaxLeft(Nod *start) {
    if (start->dreapta != nullptr)
        return start;
    return getMaxLeft(start->dreapta);
}
//BC = Theta(1), WC = Theta(h)=>O(h)

Nod *DO::getMinRight(Nod *start) {
    if (start->stanga != nullptr)
        return start;
    return getMaxLeft(start->stanga);
}
//BC = Theta(n), WC = Theta(h)=>O(h)

void DO::DestroyInordine(Nod* curent) {
    if(curent== nullptr)
        return;
    DestroyInordine(curent->stanga);
    DestroyInordine(curent->dreapta);
    delete curent;
}//BC = Theta(n), WC = Theta(h)=>O(h)


void DO::goleste() {
    DestroyInordine(this->root);
    this->root= nullptr;
    nr_elemente=0;

}//BC = Theta(n),  WC = Theta(n) => Theta(n)

