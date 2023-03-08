//
// Created by Lorena on 25.05.2022.
//

#ifndef UNTITLED7_GUICOMBINED_H
#define UNTITLED7_GUICOMBINED_H

#include <qwidget.h>
#include "Magazin_GUI.h"
#include "CosGUI.h"
#include "CosGUIDraw.h"

class GUICombined : public QWidget {
    Service_Magazin &service_magazin;
    MagazinGUI &magazingui;
    CosGUI &cosgui;

    QHBoxLayout *lyMain;
    QPushButton *magazin;
    QPushButton *cosmagazin;
    QPushButton *cosdraw;

    void initializeGUIComponents();

    void connectSignalSlots();

public:
    GUICombined(Service_Magazin &service_magazin, MagazinGUI &magazingui, CosGUI &cosgui) : magazingui(magazingui),
                                                                                            cosgui(cosgui), service_magazin(service_magazin) {
        initializeGUIComponents();
        connectSignalSlots();
    };
};

#endif //UNTITLED7_GUICOMBINED_H
