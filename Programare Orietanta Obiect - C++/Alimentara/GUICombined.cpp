//
// Created by Lorena on 25.05.2022.
//

#include "GUICombined.h"

void GUICombined::initializeGUIComponents() {
        lyMain = new QHBoxLayout;
        this->setLayout(lyMain);
        magazin = new QPushButton{"Intra in magazin"};
        cosmagazin = new QPushButton {"Vizualizeaza cosul"};
        cosdraw = new QPushButton{"Figuri"};
        lyMain->addWidget(magazin);
        lyMain->addWidget(cosmagazin);
        lyMain->addWidget(cosdraw);
}

void GUICombined::connectSignalSlots() {
    QObject::connect(magazin, &QPushButton::clicked, this, [&](){
        magazingui.show();
    });
    QObject::connect(cosmagazin, &QPushButton::clicked, this, [&](){
//       cosgui.show();
       CosGUI* firstShop = new CosGUI{this->service_magazin};
       firstShop->show();
    });
    QObject::connect(cosdraw, &QPushButton::clicked, this, [&](){
        CosGUIDraw* cosdraw= new CosGUIDraw{this->service_magazin};
        cosdraw->show();
    });
}
