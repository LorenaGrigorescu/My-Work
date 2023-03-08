//
// Created by Lorena on 24.05.2022.
//

#include "CosGUI.h"


void CosGUI::initializeGUICartComponents() {
    this->service_magazin.getCos().addObserver(this);
    QHBoxLayout *lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left part of the window
    QWidget *left = new QWidget;
    QVBoxLayout *lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget *form = new QWidget;
    QFormLayout *lyForm = new QFormLayout;
    form->setLayout(lyForm);

    editNume = new QLineEdit;
    lyForm->addRow(lblNume, editNume);
    addProdusToCart = new QPushButton("Adauga in cos");
    lyForm->addWidget(addProdusToCart);

    editcateProduse = new QLineEdit;
    lyForm->addRow(lblcateProduse, editcateProduse);
    addRandomToCart = new QPushButton("Numar elemente adaugate random");
    golesteCart = new QPushButton("Goleste cos");
    lyForm->addWidget(addRandomToCart);

    lyForm->addWidget(golesteCart);

    editFileExport = new QLineEdit;
    lyForm->addRow(lblFileExport, editFileExport);
    ExportCVS = new QPushButton("Exportare cos");
    lyForm->addWidget(ExportCVS);
    lyLeft->addWidget(form);

    QWidget *right = new QWidget;
    lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    CartTable = new QTableWidget;
    CartWishList = new QListWidget;
//    int noLines = 10;
//    int noColumns = 4;
//    this->CartTable = new QTableWidget{noLines, noColumns};
//    QStringList tblHeaderList;
//    tblHeaderList << "Nume" << "Tip" << "Pret" << "Producator";
//    this->CartTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    lyRight->addWidget(CartWishList);
//    lyRight->addWidget(CartTable);
    lyMain->addWidget(left);
    lyMain->addWidget(right);
}

void CosGUI::connectSignalSlots() {
    QObject::connect(addProdusToCart, &QPushButton::clicked, this, &CosGUI::guiAddToCart);
    QObject::connect(addRandomToCart, &QPushButton::clicked, this, &CosGUI::guiAddRandom);
    QObject::connect(golesteCart, &QPushButton::clicked, this, &CosGUI::guiGoleste);
    QObject::connect(ExportCVS, &QPushButton::clicked, this, &CosGUI::guiExportCVS);
}

void CosGUI::guiAddToCart() {
    string nume = editNume->text().toStdString();
    bool produs_existent = false;
    editNume->clear();
    Produs p;
    for (auto &produs: this->service_magazin.get_all()) {
        if (produs.get_numeProdus() == nume) {
            p = produs;
            produs_existent = true;
            break;
        }
    }
    this->service_magazin.addToCos(p.get_numeProdus(), p.get_tipProdus(), p.get_pretProdus(), p.get_producatorProdus());
    this->ReloadData(this->service_magazin.ToateDinCos());
    if (produs_existent) {
        QMessageBox::information(this, "Info", QString::fromStdString("Produsul a fost adaugat cu succes in cos."));
    } else {
        QMessageBox::warning(this, "Warning", QString::fromStdString("Produsul nu a putut fi adaugat."));
    }
}

void CosGUI::ReloadData(vector<Produs> products) {
//    this->CartTable->clearContents();
//    this->CartTable->setRowCount(products.size());
//    int lineNumber = 0;
//    for (auto &product: products) {
//        this->CartTable->setItem(lineNumber, 0,
//                                 new QTableWidgetItem(QString::fromStdString(product.get_numeProdus())));
//        this->CartTable->setItem(lineNumber, 1,
//                                 new QTableWidgetItem(QString::fromStdString(product.get_tipProdus())));
//        this->CartTable->setItem(lineNumber, 2, new QTableWidgetItem(
//                QString::fromStdString(std::to_string((product.get_pretProdus())))));
//        this->CartTable->setItem(lineNumber, 3,
//                                 new QTableWidgetItem(QString::fromStdString(product.get_producatorProdus())));
//        lineNumber++;
//    }

    this->CartWishList->clear();
    for (auto &product: products) {
        std::string s = product.get_numeProdus() + " " + product.get_tipProdus() + " " +
                        std::to_string(product.get_pretProdus()) + " " + product.get_producatorProdus();
        this->CartWishList->addItem(new QListWidgetItem(QString::fromStdString(s)));
    }
}

void CosGUI::guiAddRandom() {
    int cateProduse = editcateProduse->text().toInt();
    editcateProduse->clear();
    this->service_magazin.addRandom(cateProduse);
    this->ReloadData(this->service_magazin.ToateDinCos());
    QMessageBox::information(this, "Info", QString::fromStdString("Produsele au fost adaugate cu succes."));
}

void CosGUI::guiGoleste() {
    this->service_magazin.golesteCos();
    this->ReloadData(this->service_magazin.ToateDinCos());
    QMessageBox::information(this, "Info", QString::fromStdString("Cosul a fost golit cu succes."));
}

void CosGUI::guiExportCVS() {
    string exportfile = editFileExport->text().toStdString();
    editFileExport->clear();
    this->service_magazin.exportaCosCVS(exportfile);
    QMessageBox::information(this, "Info", QString::fromStdString("Exportare realizata cu succes"));
}

void CosGUI::update() {
    this->ReloadData(this->service_magazin.ToateDinCos());
}

