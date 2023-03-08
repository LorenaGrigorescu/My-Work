//
// Created by Lorena on 29.03.2022.
//

#include "Teste.h"
#include <cassert>
#include <iostream>
//Repozitoriu_Magazin Repo_Magazin ;

void test_utils() {
    std::string s = "12340";
    int numar = conversie_in_int(s);
    assert(numar == 12340);

}

void test_compareNumeTip() {
    std::string numeProdus = "paine";
    std::string tipProdus = "integrala";
    int pretProdus = 10;
    std::string producatorProdus = "Larisa";

    std::string numeProdus1 = "paine";
    std::string tipProdus1 = "fara gluten";
    int pretProdus1 = 20;
    std::string producatorProdus1 = "velpitar";

    Produs produs1 = Produs(numeProdus, tipProdus, pretProdus, producatorProdus);
    Produs produs2 = Produs(numeProdus1, tipProdus1, pretProdus1, producatorProdus1);
    bool ok_comparare = compare_nume_tip(produs1, produs2);
    assert(ok_comparare == 0);

    std::string numeProdus2 = "prajitura";
    std::string tipProdus2 = "de post";
    int pretProdus2 = 25;
    std::string producatorProdus2 = "lemnul verde";

    Produs produs3 = Produs(numeProdus2, tipProdus2, pretProdus2, producatorProdus2);
    bool ok_comparare1 = compare_nume_tip(produs3, produs1);
    assert(ok_comparare == 0);

    std::string numeProdus4 = "painica";
    std::string tipProdus4 = "de frupt";
    int pretP4 = 4;
    std::string producatorProdus4 = "VelPitar";
    Produs produs4 = Produs(numeProdus4, tipProdus4, pretP4, producatorProdus4);

    std::string numeProdus5 = "painica";
    std::string tipProdus5 = "de post";
    int pretP5 = 5;
    std::string producatorP5 = "VelPitar";
    Produs produs5 = Produs(numeProdus5, tipProdus5, pretP5, producatorP5);
    bool ok_comparare5 = cmpNumeTipD(produs4, produs5);
    assert(ok_comparare5 == false);
}

void test_getter() {
    std::string nume_produs = "Paine";
    std::string tip_produs = "VelPitar";
    int pret = 4;
    std::string producator_produs = "VelPitar";
    Produs produs = Produs(nume_produs, tip_produs, pret, producator_produs);
    assert(produs.get_numeProdus() == "Paine");
    assert(produs.get_tipProdus() == "VelPitar");
    assert(produs.get_pretProdus() == 4);
    assert(produs.get_producatorProdus() == "VelPitar");
}

void test_validare() {
    std::string nume_Produs = "sapun";
    std::string tip_Produs = "solid";
    std::string pret_Produs = "2";
    std::string producator_Produs = "Dove";

    try {
        Validare_produs(nume_Produs, tip_Produs, pret_Produs, producator_Produs);
        assert(true);
    } catch (MyException &e) {
        assert(false);
    }

    std::string nume_Produs1 = "";
    std::string tip_Produs1 = "aromat 82% grasime";
    std::string pret_Produs1 = "22";
    std::string producator_Produs1 = "Napolact";

    try {
        Validare_produs(nume_Produs1, tip_Produs1, pret_Produs1, producator_Produs1);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }

    std::string nume_Produs2 = "mar";
    std::string tip_Produs2 = "";
    std::string pret_Produs2 = "3";
    std::string producator_Produs2 = "Aroma";

    try {
        Validare_produs(nume_Produs2, tip_Produs2, pret_Produs2, producator_Produs2);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }

    std::string nume_Produs3 = "lapte";
    std::string tip_Produs3 = "soia";
    std::string pret_Produs3 = "-12";
    std::string producator_Produs3 = "Pilos";

    try {
        Validare_produs(nume_Produs3, tip_Produs3, pret_Produs3, producator_Produs3);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }

    std::string nume_Produs4 = "unt";
    std::string tip_Produs4 = "82%grasime";
    std::string pret_Produs4 = "";
    std::string producator_Produs4 = "Pilos";

    try {
        Validare_produs(nume_Produs4, tip_Produs4, pret_Produs4, producator_Produs4);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }

    std::string nume_Produs5 = "zahar";
    std::string tip_Produs5 = "brun";
    std::string pret_Produs5 = "5";
    std::string producator_Produs5 = "";

    try {
        Validare_produs(nume_Produs5, tip_Produs5, pret_Produs5, producator_Produs5);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }
}

void test_vector() {
    Repozitoriu_Magazin Repo_Magazin;
    assert(Repo_Magazin.get_lista().size() == 10);
    std::vector<Produs> produse = Repo_Magazin.get_lista();
    assert(produse.size() == 10);
}

void test_adaugaProdus() {
    Repozitoriu_Magazin Repo_Magazin;

    std::string nume_Produs = "sapun";
    std::string tip_Produs = "solid";
    int pret_Produs = 2;
    std::string producator_Produs = "Dove";
    Produs produs = Produs(nume_Produs, tip_Produs, pret_Produs, producator_Produs);
    bool ok_adauga = Repo_Magazin.adaugaProdus(produs);
    assert(ok_adauga == 1);
    assert(Repo_Magazin.get_lista().size() == 11);

    bool ok_adauga_din_nou = Repo_Magazin.adaugaProdus(produs);
    assert(ok_adauga_din_nou == 0);
    assert(Repo_Magazin.get_lista().size() == 11);

    std::string nume_Produs1 = "jacheta";
    std::string tip_Produs1 = "lana";
    int pret_Produs1 = 160;
    std::string producator_Produs1 = "HM";
    Produs produs1 = Produs(nume_Produs1, tip_Produs1, pret_Produs1, producator_Produs1);
    bool ok_adauga2 = Repo_Magazin.adaugaProdus(produs1);
    assert(ok_adauga2 == 1);
    assert(Repo_Magazin.get_lista().size() == 12);
}

void test_stergeProdus() {
    Repozitoriu_Magazin Repo_Magazin;

    std::string nume_Produs = "sapun";
    std::string tip_Produs = "lichid";
    int pret_Produs = 11;
    std::string producator_Produs = "Dove";
    Produs produs = Produs(nume_Produs, tip_Produs, pret_Produs, producator_Produs);
    bool ok = Repo_Magazin.adaugaProdus(produs);
    assert(Repo_Magazin.get_lista().size() == 11);
    bool ok_obiect_sters = false;
    if (ok) {
        ok_obiect_sters = Repo_Magazin.stergeProdus(nume_Produs);
    }
    assert(ok_obiect_sters == true);
    bool ok_obiect_sters_din_nou;
    ok_obiect_sters_din_nou = Repo_Magazin.stergeProdus(nume_Produs);
    assert(ok_obiect_sters_din_nou == false);
    assert(Repo_Magazin.get_lista().size() == 10);
}

void test_cautareProdus() {
    std::string numeProdus = "ulei";
    std::string tipProdus = "floarea soarelui";
    int pretProdus = 11;
    std::string producatorProdus = "bunica";
    Produs produs = Produs(numeProdus, tipProdus, pretProdus, producatorProdus);

    Repozitoriu_Magazin Repo_Magazin;
    Repo_Magazin.adaugaProdus(produs);

    std::string nume_cautare = "ulei";
    bool ok_cauta = Repo_Magazin.cautareProdus(nume_cautare);
    assert(ok_cauta == true);

    nume_cautare = "capsuni";
    ok_cauta = Repo_Magazin.cautareProdus(nume_cautare);
    assert(ok_cauta == false);
}

void test_modificarePret() {
    Repozitoriu_Magazin Repo_Magazin;

    std::string numeProdus = "apa";
    std::string tipProdus = "minerala";
    int pretProdus = 6;
    std::string producatorProdus = "Borsec";

    Produs produs = Produs(numeProdus, tipProdus, pretProdus, producatorProdus);
    Repo_Magazin.adaugaProdus(produs);

    std::string nume_produs_cautat = "apa";
    int pret_produs_1 = 5;
    bool ok1 = Repo_Magazin.modificare_pretProdus(nume_produs_cautat, pret_produs_1);
    assert(ok1 == true);

    int pret_produs_2 = 6;
    bool ok2 = Repo_Magazin.modificare_pretProdus(nume_produs_cautat, pret_produs_2);
    assert(ok2 == true);

    nume_produs_cautat = "suc";
    bool ok3 = Repo_Magazin.modificare_pretProdus(nume_produs_cautat, pret_produs_2);
    assert(ok3 == false);

}

void test_adaugaProdusS() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};

    std::string numeProdus = "painica";
    std::string tipProdus = "integrala";
    std::string pretProdus = "12";
    std::string producatorProdus = "Sunday";
    bool ok_service = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);
    assert(ok_service == 1);

    bool ok_service1 = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);;
    assert(ok_service1 == 0);

    numeProdus = "";
    tipProdus = "";
    pretProdus = "";
    producatorProdus = "";
    try {
        bool ok_service2 = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);
        assert(false);
    } catch (MyException &e) {
        assert(true);
    }

    std::string numeProdus2 = "faina";
    std::string tipProdus2 = "superioara";
    std::string pretProdus2 = "1234567890";
    std::string producatorProdus2 = "Coronita";
    bool ok_service3 = Serv_Magazin.adaugareProdus_Service(numeProdus2, tipProdus2, pretProdus2, producatorProdus2);
    assert(ok_service3 == true);
    assert(Serv_Magazin.get_all().size() == 12);
}

void test_stergeProdusS() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};

    std::string numeProdus = "painica";
    std::string tipProdus = "integrala";
    std::string pret_Produs = "12";
    std::string producatorProdus = "Sunday";

    bool ok_adaugare = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pret_Produs, producatorProdus);
    if (ok_adaugare) {
        bool ok_stergere = Serv_Magazin.stergeProdus_Service(numeProdus);
        bool ok_stergere1 = Serv_Magazin.stergeProdus_Service(numeProdus);

        assert(ok_stergere == true);
        assert(ok_stergere1 == false);
    }

    numeProdus = "";
    try {
        bool ok_stergere3 = Serv_Magazin.stergeProdus_Service(numeProdus);
    } catch (MyException &exception) { assert(true);}
//    bool ok_stergere3 = Serv_Magazin.stergeProdus_Service(numeProdus);
//
//    assert(ok_stergere3 == false);
}

void test_cautareprodusS() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};

    std::string numeProdus = "painica";
    std::string tipProdus = "integrala";
    std::string pretProdus = "12";
    std::string producatorProdus = "Sunday";

    bool ok_adaugare = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);
    if (ok_adaugare) {
        std::string numeProdus1;

        bool ok_cautare = Serv_Magazin.cautareProdus_Service(numeProdus);
        assert(ok_cautare == true);

        bool ok_cautare1 = Serv_Magazin.cautareProdus_Service(numeProdus1);
        assert(ok_cautare1 == false);
    }
}


void test_modificarePretProdusS() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};

    std::string numeProdus = "painica";
    std::string tipProdus = "integrala";
    std::string pretProdus = "12";
    std::string producatorProdus = "Sunday";

    int pret_Produs = 12;
    Produs produs1 = Produs(numeProdus, tipProdus, pret_Produs, producatorProdus);

    bool ok_adaugare = Serv_Magazin.adaugareProdus_Service(numeProdus, tipProdus, pretProdus, producatorProdus);
    if (ok_adaugare) {
        std::string numeProdus_copy = numeProdus;
        std::string pretProdus_copy = "1";

        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }

        numeProdus_copy = "cas";
        pretProdus_copy = "12";

        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }

        numeProdus_copy = numeProdus;
        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }
        assert(produs1.get_pretProdus() == 12);

        numeProdus_copy = "";
        pretProdus_copy = "";
        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }

        pretProdus_copy = "4";
        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }

        pretProdus_copy = "";
        numeProdus_copy = "paine";
        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(true);
        } catch (MyException &e) {
            assert(false);
        }

        pretProdus_copy = "1234567890";
        numeProdus_copy = "paine";
        bool ok_modificare6 = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
        assert(ok_modificare6 == true);

        pretProdus_copy = "123456rfhn";
        numeProdus_copy = "eeee";
        try {
            bool ok_modificare = Serv_Magazin.modificarePretProdus_Service(numeProdus_copy, pretProdus_copy);
            assert(false);
        } catch (MyException &e) {
            assert(true);
        }
    }
}

void test_sortareNume() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> lista_produse = Serv_Magazin.get_all();
    std::vector<Produs> CopySorted = Serv_Magazin.sort_by_nume();
    assert(CopySorted[0].get_numeProdus() == "biscuiti");
    assert(CopySorted[1].get_numeProdus() == "branza");
    assert(CopySorted[2].get_numeProdus() == "cereale");
}

void test_sortareNumeD() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> CopySortedD = Serv_Magazin.sort_by_numeD();
    assert(CopySortedD[9].get_numeProdus() == "biscuiti");
    assert(CopySortedD[8].get_numeProdus() == "branza");
    assert(CopySortedD[7].get_numeProdus() == "cereale");
}

void test_sortarePret() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    std::vector<Produs> CopySorted = Serv_Magazin.sort_by_pret();
    assert(CopySorted[0].get_pretProdus() == 3);
    assert(CopySorted[1].get_pretProdus() == 3);
    assert(CopySorted[2].get_pretProdus() == 5);

}

void test_sortarePretD() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    std::vector<Produs> CopySortedD = Serv_Magazin.sort_by_pretD();
    assert(CopySortedD[9].get_pretProdus() == 3);
    assert(CopySortedD[8].get_pretProdus() == 3);
    assert(CopySortedD[7].get_pretProdus() == 5);
}

void test_sortareNumeTip() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();

    std::vector<Produs> CopySorted = Serv_Magazin.sort_by_nume_tip();
    assert(CopySorted[0].get_numeProdus() == "biscuiti");
    assert(CopySorted[1].get_numeProdus() == "branza");
    assert(CopySorted[2].get_numeProdus() == "cereale");
}

void test_sortareNumeTipD() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    std::vector<Produs> CopySortedD = Serv_Magazin.sort_by_nume_tipD();
    assert(CopySortedD[9].get_numeProdus() == "biscuiti");
    assert(CopySortedD[8].get_numeProdus() == "branza");
    assert(CopySortedD[7].get_numeProdus() == "cereale");
}

void test_filtrare_nume() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    auto nume_filtrare = "biscuiti";
    std::vector<Produs> CopyFiltered = Serv_Magazin.filtrareNume(nume_filtrare);
    assert(CopyFiltered.size() == 1);
}

void test_filtrare_pret() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    auto pret_filtrare = 3;
    std::vector<Produs> CopyFiltered = Serv_Magazin.filtrarePret(pret_filtrare);
//    for(auto &produs: CopyFiltered)
//        std::cout<<produs.get_numeProdus()<<" ";
//std::cout<<CopyFiltered.size();
    assert(CopyFiltered.size() == 2);
}

void test_filtrare_producator() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    std::vector<Produs> sorted_list = Serv_Magazin.get_all();
    auto producator_filtrare = "Delma";
    std::vector<Produs> CopyFiltered = Serv_Magazin.filtrareProducator(producator_filtrare);
    assert(CopyFiltered.size() == 0);
}

void test_allof() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    bool ok_result = Serv_Magazin.allof_function();
    assert(ok_result == false);
    std::string nume = "paine";
    Serv_Magazin.stergeProdus_Service(nume);
    nume = "muraturi";
    Serv_Magazin.stergeProdus_Service(nume);
    nume = "ciocolata";
    Serv_Magazin.stergeProdus_Service(nume);
    ok_result = Serv_Magazin.allof_function();
    assert(ok_result == true);

}

void test_produs_cos() {
    const Produs produs = Produs{"faina", "integrala", 5, "Grania"};
    CosMagazin cos_magazin;
    cos_magazin.adauga_Cos(produs);
    assert(cos_magazin.get_Cos_Magazin().size() == 1);
}

void test_goleste_cos() {
    const Produs produs = Produs{"faina", "integrala", 5, "Grania"};
    const Produs produs1 = Produs{"paine", "fara gluten", 12, "VelPitar"};
    const Produs produs2 = Produs{"sapun", "cu aroma de castraveti", 4, "Dove"};
    CosMagazin cos_magazin;
    cos_magazin.adauga_Cos(produs);
    cos_magazin.adauga_Cos(produs1);
    cos_magazin.adauga_Cos(produs2);
    cos_magazin.adauga_Cos(produs);
    cos_magazin.adauga_Cos(produs2);
    assert(cos_magazin.get_Cos_Magazin().size() == 5);
    cos_magazin.goleste_Cos();
    assert(cos_magazin.get_Cos_Magazin().size() == 0);
}

void test_umple_cos() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cos_magazin;
    size_t capacitate = 4;
    cos_magazin.umple_Cos(capacitate, Repo_Magazin.get_lista());
    assert(cos_magazin.get_Cos_Magazin().size());
}

void test_AddToCos() {

    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    Produs produs = Serv_Magazin.get_all()[Serv_Magazin.get_all().size() - 1];
    Serv_Magazin.addToCos(produs.get_numeProdus(), produs.get_tipProdus(),
                          produs.get_pretProdus(), produs.get_producatorProdus());
    assert(cosMagazin.get_Cos_Magazin().size() == 1);
}

void test_AddRandom() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    size_t capacitate = 6;
    Serv_Magazin.addRandom(capacitate);
    assert(Serv_Magazin.ToateDinCos().size() == 6);
}

void test_GolesteCos() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    size_t capacitate = 6;
    Serv_Magazin.addRandom(capacitate);
    Serv_Magazin.golesteCos();
    assert(cosMagazin.get_Cos_Magazin().empty());
}

void test_ToateDinCos() {
    Repozitoriu_Magazin Repo_Magazin;
    CosMagazin cosMagazin;
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    size_t capacitate = 6;
    Serv_Magazin.addRandom(capacitate);
    assert(cosMagazin.get_Cos_Magazin().size() == capacitate);

}

void test_creeare_fisier() {
    std::ofstream out("ProduseTest.txt", std::ios::trunc);
    out.close(); //creeare fisier gol
    if (out.good())
        std::cout << "Fisierul este deschis!\n";
    Repozitoriu_Magazin_File repo_file{"ProduseTest.txt"};
    auto result = repo_file.adaugaProdus(Produs{"Masina", "vase", 4000, "Whirlpool"});
    assert(result == true);
    assert(repo_file.adaugaProdus(Produs{"branzica", "perle", 4, "Hochland"}) == true);
    std::string numep = "branzica";
    assert(repo_file.stergeProdus(numep) == true);
    assert(repo_file.get_lista().size() == 11);
}

void test_apelare_metode_mostenite() {
    std::ofstream out("ProduseTest.txt", std::ios::trunc);
    Repozitoriu_Magazin_File repo_file{"ProduseTest.txt"};
    auto list = repo_file.get_lista();
    assert(list.size() == 10);
    std::string nume_cautare = "aaaaaaa";
    assert(repo_file.cautareProdus(nume_cautare) == false);
    auto result = repo_file.stergeProdus(nume_cautare);
    assert(result == true);
    result = repo_file.adaugaProdus(Produs{"Ciocolata", "Tableta", 3, "Milka"});
    assert(result == true);
    assert(repo_file.get_lista().size() == 11);
    result = repo_file.stergeProdus("Ciocolata");
    assert(result == true);
    assert(repo_file.get_lista().size() == 10);
    result = repo_file.stergeProdus("Ciocolata");
    assert(result == true);
    assert(repo_file.get_lista().size() == 10);
}

void test_fake_fisier() {
    try {
        Repozitoriu_Magazin_File repo_file{"FisierFake.txt"};
        assert(false);
    } catch (MyException &err) {
        std::cout << err.getErrorMessage();
        assert(true);
    }
}

void test_LoadToFile() {
    std::ifstream in;
    Produs produs;
//    in.close();
    while (!in.eof()) {
        std::string nume;
        in >> nume;
        std::string tip;
        in >> tip;
        std::string producator;
        in >> producator;
        produs = Produs{nume, tip, 1, producator};
    }
    in.close();
    Repozitoriu_Magazin_File repo_file{"../nou.txt"};
    assert(repo_file.adaugaProdus(produs) == 1);
}

void test_WriteToFile() {
    std::ofstream out("", std::ios::in);
    out.close();

    try {
        Repozitoriu_Magazin_File repo_file{""};
        assert(false);
    } catch (MyException &) {
        assert(true);
    }
}

void test_doUndo() {
    Repozitoriu_Magazin repo;
    CosMagazin cos;
    Service_Magazin service{repo, cos};
    assert(service.get_all().size() == 10);
    std::string numeP = "branzica";
    std::string tipP = "perlute";
    std::string pretP = "5";
    std::string producatorP = "Hochland";
    service.adaugareProdus_Service(numeP, tipP, pretP, producatorP);
    numeP = "mamaliga";
    tipP = "faina de grau";
    pretP = "9";
    producatorP = "Maggie";
    service.adaugareProdus_Service(numeP, tipP, pretP, producatorP);
    assert(service.get_all().size() == 12);
    service.undo();
    service.undo();
    assert(service.get_all().size() == 10);
    numeP = "paine";
    service.stergeProdus_Service(numeP);
    assert(service.get_all().size() == 9);
    service.undo();
    assert(service.get_all().size() == 10);
    try {
        service.undo();
        assert(false);
    } catch (MyException &e) {
        std::cout << e.getErrorMessage();
        assert(true);
    }
    std::string modificare_pret = "600";
    std::string numeProdus = "pate";
    int produs_initial;
    for (auto &p: service.get_all())
        if (p.get_numeProdus() == numeProdus) {
            produs_initial = p.get_pretProdus();
            break;
        }
    service.modificarePretProdus_Service(numeProdus, modificare_pret);
    service.undo();
    Produs prod;
    for (auto &p: service.get_all())
        if (p.get_numeProdus() == numeProdus)
            prod = p;
    assert(prod.get_pretProdus() == produs_initial);

}

void test_exportCVS() {
    Repozitoriu_Magazin repo_magazin;
    CosMagazin cosMagazin;
    Service_Magazin serviceMagazin{repo_magazin, cosMagazin};
    serviceMagazin.addRandom(3);
    serviceMagazin.exportaCosCVS("testExport.cvs");
    std::ifstream in("testExport.cvs");
    assert(in.is_open());
    int countLines = 0;
    while (!in.eof()) {
        std::string line;
        in >> line;
        if (std::getline(in, line))
            countLines++;
    }
    in.close();
    assert(countLines == 3);
    try {
        serviceMagazin.exportaCosCVS("gsdds/OriceAltceva.cvs");
        assert(false);
    } catch (MyException &e) {
        std::cout << e.getErrorMessage();
        assert(true);
    }
}

void testAll() {
    test_utils();
    test_getter();
    test_validare();
    test_vector();
    test_adaugaProdus();
    test_stergeProdus();
    test_cautareProdus();
    test_modificarePret();
    test_adaugaProdusS();
    test_stergeProdusS();
    test_cautareprodusS();
    test_modificarePretProdusS();
    test_sortareNume();
    test_sortareNumeD();
    test_sortarePret();
    test_sortarePretD();
    test_sortareNumeTip();
    test_compareNumeTip();
    test_sortareNumeTipD();
    test_filtrare_nume();
    test_filtrare_pret();
    test_filtrare_producator();
    test_allof();
    std::cout << "Starting all tests (cos) ...\n";
    test_produs_cos();
    test_goleste_cos();
    test_umple_cos();
    test_AddToCos();
    test_AddRandom();
    test_GolesteCos();
    test_ToateDinCos();
    std::cout << "All tests (cos) are OK!\n";
    std::cout << "Running FileRepository tests....\n";
    test_creeare_fisier();
    test_apelare_metode_mostenite();
    test_fake_fisier();
    test_LoadToFile();
    test_WriteToFile();
    test_doUndo();
    test_exportCVS();
    std::cout << "Everything is alright!!\n";
}