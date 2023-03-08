//
// Created by Lorena on 12.05.2022.
//
#ifndef UNTITLED7_MAGAZIN_GUI_H
#define UNTITLED7_MAGAZIN_GUI_H

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
#include "MyTableModel.h"

using std::vector;
using std::string;

class MagazinGUI : public QWidget {
private:
    Service_Magazin &service_magazin;
    QLabel *lblNume = new QLabel{"Nume produs:"};
    QLabel *lblTip = new QLabel{"Tip produs:"};
    QLabel *lblPret = new QLabel{"Pret produs:"};
    QLabel *lblProducator = new QLabel{"Producator produs:"};

    QLineEdit *editNume;
    QLineEdit *editTip;
    QLineEdit *editPret;
    QLineEdit *editProducator;

    QLabel *lblNumeSters = new QLabel{"Numele produsului de sters:"};
    QLineEdit *editNume_S;

    QLabel *lblNumeCautat = new QLabel{"Numele produsului cautat:"};
    QLineEdit *editNume_C;

    QLabel *lblPretModificat = new QLabel{"Pretul produsului modificat:"};
    QLabel *lblNumeModificat = new QLabel{"Numele produsul modificat:"};
    QLineEdit *editNume_M;
    QLineEdit *editPret_M;


    QPushButton *btnAddProdus;
    QPushButton *btnStersProdus;
    QPushButton *btnCautareProdus;
    QPushButton *btnModificarePret;
    QPushButton *btnUndoAction;
    QPushButton *btnToCart;

    QGroupBox *groupBox = new QGroupBox(tr("Tip sortare"));
    QRadioButton *radioSrtNumeTip = new QRadioButton(QString::fromStdString("Nume + Tip"));
    QRadioButton *radioSrtNume = new QRadioButton(QString::fromStdString("Nume"));
    QRadioButton *radioSrtPret = new QRadioButton(QString::fromStdString("Pret"));
    QPushButton *btnSortProducts;

    QLabel *lblFilterCriteriaNume = new QLabel{"Nume dupa care se filtreaza:"};
    QLabel *lblFilterCriteriaPret = new QLabel{"Pret dupa care se filtreaza:"};
    QLabel *lblFilterCriteriaProducator = new QLabel{"Producator dupa care se filtreaza"};
    QLineEdit *editFilterNume;
    QLineEdit *editFilterPret;
    QLineEdit *editFilterProducator;

    QPushButton *btnFilterCriteria;
    QPushButton *btnFilterProductsNume;
    QPushButton *btnFilterProductsPret;
    QPushButton *btnFilterProductsProducator;

    QPushButton *btnReloadData;
    QVBoxLayout *lyRight;
    QVBoxLayout *lyButtons;
    MyTableModel* model;
    QTableView* TableProducts = new QTableView;
//    QTableWidget *tableProducts;

    std::vector<QPushButton *> DynamicButtons;


    void initializeGUIComponents();
    void connectSignalSlots();

    void reloadProductsList(vector<Produs> products);

    void generateInitialDButtons();

public:
    MagazinGUI(Service_Magazin &serv_magazin) : service_magazin{serv_magazin} {
        initializeGUIComponents();
        this->model = new MyTableModel {service_magazin.get_all()};
        this->TableProducts->setModel(model);
        connectSignalSlots();
        reloadProductsList(service_magazin.get_all());
    }

    void guiAddProducts();

    void guiDeleteProduct();

    void guiSearchProduct();

    void guiModifyPrice();

    void guiUndoAction();

};

#endif //UNTITLED7_MAGAZIN_GUI_H
