//
// Created by Lorena on 02.05.2022.
//

#ifndef MAGAZIN_LAB8_9_UNDO_H
#define MAGAZIN_LAB8_9_UNDO_H

#include "Domeniu.h"
#include "Repozitoriu.h"

class ActiuneUndo {
public:
    virtual bool doUndo() = 0;

    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
    Produs produs_adaugat;
    Repozitoriu_Magazin &repozitoriuMagazin;
public:
    UndoAdauga(Repozitoriu_Magazin &repozitoriuMagazin, const Produs &produs) : repozitoriuMagazin{repozitoriuMagazin},
                                                                                produs_adaugat{produs} {};

    bool doUndo() override {
        auto undo = repozitoriuMagazin.stergeProdus(produs_adaugat.get_numeProdus());
        return undo;
    }

};

class UndoSterge : public ActiuneUndo {
    Produs produs_sters;
    Repozitoriu_Magazin &repozitoriuMagazin;
public:
    UndoSterge(Repozitoriu_Magazin &repozitoriuMagazin, const Produs &produs) : repozitoriuMagazin{repozitoriuMagazin},
                                                                                produs_sters{produs} {};

    bool doUndo() override {
        auto undo = repozitoriuMagazin.adaugaProdus(produs_sters);
        return undo;
    }
};

class UndoModificaPret : public ActiuneUndo {
    int pret_final;
    std::string nume_produs;
    Repozitoriu_Magazin &repozitoriuMagazin;
public:
    UndoModificaPret(Repozitoriu_Magazin &repozitoriuMagazin, const int pret_final,
                     const std::string nume_produs) : repozitoriuMagazin{repozitoriuMagazin}, pret_final{pret_final},
                                                      nume_produs{nume_produs} {};
    bool doUndo() override
    {
        auto undo = repozitoriuMagazin.modificare_pretProdus(nume_produs, pret_final);
        return undo;
    }
};

#endif //MAGAZIN_LAB8_9_UNDO_H
