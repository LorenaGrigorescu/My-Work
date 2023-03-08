//
// Created by Lorena on 29.03.2022.
//

#ifndef MAGAZIN_LAB6_7_TESTE_H
#define MAGAZIN_LAB6_7_TESTE_H

#include "Domeniu.h"
#include "Validatori.h"
#include <vector>
#include "Repozitoriu.h"
#include "Utils.h"
#include "Service.h"
#include "Exceptions.h"


//-----Teste Utils
void test_utils();

void test_compareNumeTip();

//-----Teste Domeniu----
void test_getter();

//-----Teste Validare
void test_validare();

//-----Teste Repozitoriu
void test_vector();

void test_adaugaProdus();

void test_stergeProdus();

void test_cautareProdus();

void test_modificarePret();

//-----Teste Service
void test_adaugaProdusS();

void test_stergeProdusS();

void test_cautareprodusS();

void test_modificarePretProdusS();

void test_sortareNume();

void test_sortareNumeD();

void test_sortarePret();

void test_sortarePretD();

void test_sortareNumeTip();

void test_sortareNumeTipD();

void test_filtrare_nume();

void test_filtrare_pret();

void test_filtrare_producator();
void test_allof();

//Test--Cos
 void test_produs_cos();
 void test_goleste_cos();
 void test_umple_cos();
 //Test--Cos Service
void test_AddToCos();
void test_AddRandom();
void test_GolesteCos();
void test_ToateDinCos();
//Test Repozitoriu Fisier
void test_creeare_fisier();
void test_apelare_metode_mostenite();
void test_fake_fisier();
void test_LoadToFile();
void test_WriteToFile();
//Test DoUndo
void test_doUndo();
//Test ExportCVS
void test_exportCVS();
void testAll();

#endif //MAGAZIN_LAB6_7_TESTE_H
