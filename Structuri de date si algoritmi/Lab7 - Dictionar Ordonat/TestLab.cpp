//
// Created by Lorena on 03.06.2022.
//

#include "TestLab.h"
#include "DO.h"
#include <assert.h>
bool relatie4(TCheie cheie1, TCheie cheie2)
{
    if(cheie1<=cheie2)
        return true;
    return false;
}
void test_goleste()
{
    DO dictOrd = DO(relatie4);
    dictOrd.adauga(1, 2);
    dictOrd.adauga(2,3);
    dictOrd.adauga(33,44);
    assert(dictOrd.dim()==3);
    dictOrd.goleste();
    assert(dictOrd.dim()==0);
}