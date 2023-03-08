//
// Created by Lorena on 27.05.2022.
//

#ifndef UNTITLED7_COSGUIDRAW_H
#define UNTITLED7_COSGUIDRAW_H

#include <QWidget>
#include "Observer.h"
#include "Service.h"

class CosGUIDraw: public QWidget, public Observer{
private:
    Service_Magazin &service_magazin;
public:
    CosGUIDraw(Service_Magazin &service_magazin) : service_magazin(service_magazin){};
    void update() override;
    void paintEvent(QPaintEvent*) override;
};
#endif //UNTITLED7_COSGUIDRAW_H
