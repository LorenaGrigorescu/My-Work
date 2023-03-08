//
// Created by Lorena on 24.05.2022.
//

#ifndef UNTITLED7_COSGUI_H
#define UNTITLED7_COSGUI_H

#include <vector>
#include <string>
#include <QApplication>
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include "Service.h"

using std::vector;
using std::string;

class CosGUI : public QWidget, public Observer {
    Service_Magazin &service_magazin;
    QLabel *lblNume = new QLabel{"Nume produs:"};
    QLineEdit *editNume;

    QLabel *lblcateProduse  = new QLabel {"Numarul de produse pe care vreti sa il adaugati:"};
    QLineEdit *editcateProduse ;

    QLabel *lblFileExport = new QLabel{"Fisier de export:"};
    QLineEdit *editFileExport ;
    QPushButton *addProdusToCart;
    QPushButton *addRandomToCart;
    QPushButton *golesteCart;
    QPushButton *ExportCVS;


    QVBoxLayout *lyRight;
    QTableWidget *CartTable;
    QListWidget *CartWishList;

    void initializeGUICartComponents();

    void connectSignalSlots();

    void ReloadData(vector<Produs> products);
    void update() override;

public:
    void guiAddToCart();
    void guiAddRandom();
    void guiGoleste();
    void guiExportCVS();
    CosGUI(Service_Magazin &service_magazin) : service_magazin(service_magazin) {
        initializeGUICartComponents();
        connectSignalSlots();
        ReloadData(this->service_magazin.ToateDinCos());
    };
};

#endif //UNTITLED7_COSGUI_H
