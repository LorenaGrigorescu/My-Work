#include "IteratorMD.h"
#include "MD.h"

using namespace std;


using namespace std;

IteratorMD::IteratorMD(const MD &_md) : md(_md) {
    /* de adaugat */
    nod_curent = this->md.head;
}//BC=WC=Theta(1) = OC

TElem IteratorMD::element() const {
    /* de adaugat */
    if (valid()) {
        return nod_curent->informatie;
    }
    throw exception();
}//BC=WC=Theta(1) = OC

bool IteratorMD::valid() const {
    /* de adaugat */
    if (nod_curent == nullptr)
        return false;
    return true;
}//BC=WC=Theta(1) = OC

void IteratorMD::urmator() {
    /* de adaugat */
    if (nod_curent != nullptr)
        nod_curent = nod_curent->urmator;
}//BC=WC=Theta(1) = OC

void IteratorMD::prim() {
    /* de adaugat */
    nod_curent = this->md.head;
}//BC=WC=Theta(1) = OC

