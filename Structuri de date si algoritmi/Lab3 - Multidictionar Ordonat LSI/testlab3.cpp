//
// Created by Lorena on 15.04.2022.
//

#include "testlab3.h"

void testminmax()
{
    MD m;
    m.adauga(2, 200);
    m.adauga(3, 300);
    m.adauga(1, 500);
    m.adauga(2, 600);
    m.adauga(4, 800);
    auto diferenta = m.diferentaValoareMaxMin();
    assert(diferenta==600);

    MD m1;
    auto diferenta1 = m1.diferentaValoareMaxMin();
    assert(diferenta1==-1);
}