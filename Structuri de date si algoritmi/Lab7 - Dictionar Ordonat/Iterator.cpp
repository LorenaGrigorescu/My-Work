#include "Iterator.h"

using namespace std;

Iterator::Iterator(const DO &d) : dict(d) {
    /* de adaugat */
    ParcurgereInordineR(dict.root);
    index = 0;
}//BC = WC = Theta(1)

void Iterator::prim() {
    /* de adaugat */
   index = 0;
}
//BC = WC =Theta(1)
void Iterator::urmator() {
    /* de adaugat */
   index++;
}
//BC = WC = Theta(1)
bool Iterator::valid() const {
    /* de adaugat */
    if(index>=valori.size())
        return false;
    return true;
}
//BC = WC = Theta(1)
TElem Iterator::element() const {
    /* de adaugat */
    if(!valid())
        throw std::exception();
    return valori[index];
}
//BC = WC = Theta(1)

void Iterator::ParcurgereInordineR(Nod* curent) {
    if(curent== nullptr)
        return;
    ParcurgereInordineR(curent->stanga);
    valori.push_back(curent->e);
    ParcurgereInordineR(curent->dreapta);
}//BC = Theta(1) WC = Theta(h) => O(h)