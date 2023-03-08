//
// Created by Lorena on 12.05.2022.
//

#include "Magazin_GUI.h"

void MagazinGUI::initializeGUIComponents() {

    //impartim fereastra in 2: in stanga, butoane+labels+lineedits
    //iar in dreapta: tabelul cu melodii

    //"stanga" si "dreapta" pentru ca este QHBoxLayout
    //se adauga componente incepand din stanga, pe orizontala
    //aici: "left" component, then "right" component
    //care la randul lor contin alte componente

    //main layout
    QHBoxLayout *lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left part of the window
    //pentru aceasta parte setam layout-ul vertical
    QWidget *left = new QWidget;
    QVBoxLayout *lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    //componente pentru functionalitatea de adaugare a unui produs
    //folosim un QFormLayout pentru detaliile de adaugare ale unui produs
    QWidget *form = new QWidget;
    QFormLayout *lyForm = new QFormLayout;
    form->setLayout(lyForm);
    editNume = new QLineEdit;
    editTip = new QLineEdit;
    editPret = new QLineEdit;
    editProducator = new QLineEdit;


    lyForm->addRow(lblNume, editNume);
    lyForm->addRow(lblTip, editTip);
    lyForm->addRow(lblPret, editPret);
    lyForm->addRow(lblProducator, editProducator);

    btnAddProdus = new QPushButton("Adauga produs");
    lyForm->addWidget(btnAddProdus);

    editNume_S = new QLineEdit;
    lyForm->addRow(lblNumeSters, editNume_S);
    btnStersProdus = new QPushButton("Sterge produs");
    lyForm->addWidget(btnStersProdus);

    editNume_C = new QLineEdit;
    lyForm->addRow(lblNumeCautat, editNume_C);
    btnCautareProdus = new QPushButton("Cauta produs");
    lyForm->addWidget(btnCautareProdus);

    editPret_M = new QLineEdit;
    editNume_M = new QLineEdit;
    lyForm->addRow(lblPretModificat, editPret_M);
    lyForm->addRow(lblNumeModificat, editNume_M);
    btnModificarePret = new QPushButton("Modifica pret");
    lyForm->addWidget(btnModificarePret);

    btnUndoAction = new QPushButton("Actiune de undo");
    lyForm->addWidget(btnUndoAction);

    //adaugam toate componentele legate de adaugare produs
    //in layout-ul care corespunda partii din stanga a ferestrei
    lyLeft->addWidget(form);

    //Radio Buttons: ne ajuta cand trebuie sa selectam doar o optiune din mai
    //multe (doar un RadioButton poate fi selectat la un moment dat

    //cream un GroupBox pentru radiobuttons care corespund
    //criteriilor de sortare pe care le vrem (nume, pret, nume+tip) + butonul sort

    QVBoxLayout *lyRadioBox = new QVBoxLayout;
    this->groupBox->setLayout(lyRadioBox);
    lyRadioBox->addWidget(radioSrtNume);
    lyRadioBox->addWidget(radioSrtPret);
    lyRadioBox->addWidget(radioSrtNumeTip);

    btnSortProducts = new QPushButton("Sorteaza produse");
    lyRadioBox->addWidget(btnSortProducts);

    //adaugam acest grup in partea stanga,
    //dupa componentele pentru adaugare in layout-ul vertical
    lyLeft->addWidget(groupBox);

    //cream un form pentru filtrarea dupa gen
    QWidget *formFilter = new QWidget;
    QFormLayout *lyFormFilter = new QFormLayout;
    formFilter->setLayout(lyFormFilter);

    editFilterNume = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteriaNume, editFilterNume);
    btnFilterProductsNume = new QPushButton("Filtreaza produse dupa nume");
    lyFormFilter->addWidget(btnFilterProductsNume);

    editFilterPret = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteriaPret, editFilterPret);
    btnFilterProductsPret = new QPushButton("Filtreaza produse dupa pret");
    lyFormFilter->addRow(btnFilterProductsPret);

    editFilterProducator = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteriaProducator, editFilterProducator);
    btnFilterProductsProducator = new QPushButton("Filtreaza produse dupa producator");
    lyFormFilter->addRow(btnFilterProductsProducator);
    btnToCart = new QPushButton("Adauga in cos");
    lyFormFilter->addWidget(btnToCart);
    lyLeft->addWidget(formFilter);

    //Buton folosit pentru reincarcarea datelor
    //afisam toate produsele in tabel in ordinea initiala din fisier
    btnReloadData = new QPushButton("Reincarcare date");
    lyLeft->addWidget(btnReloadData);

    //componenta right - contine doar tabelul cu melodii
    QWidget *right = new QWidget;
    lyRight = new QVBoxLayout;
    right->setLayout(lyRight);
    lyButtons = new QVBoxLayout;
    lyRight->addLayout(lyButtons);
    generateInitialDButtons();
    for (auto &button: DynamicButtons) {
        lyButtons->addWidget(button);
    }
//    int noLines = 10;
//    int noColumns = 4;
//    this->tableProducts = new QTableWidget{noLines, noColumns};

    //setam header-ul tablelui
//    QStringList tblHeaderList;
//    tblHeaderList << "Nume" << "Tip" << "Pret" << "Producator";
//    this->tableProducts->setHorizontalHeaderLabels(tblHeaderList);

    //optiune pentru a se redimensiona celulele din tabel in functie de continut
//    this->tableProducts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

//    lyRight->addWidget(tableProducts);
    lyRight->addWidget(TableProducts);
    lyMain->addWidget(left);
    lyMain->addWidget(right);

}

void MagazinGUI::reloadProductsList(vector<Produs> products) {

//    this->tableProducts->clearContents();
//    this->tableProducts->setRowCount(products.size());
//        this->model = new MyTableModel{products};
    this->model->setProduse(products);

//    int lineNumber = 0;
//    for (auto &product: products) {
//        this->tableProducts->setItem(lineNumber, 0,
//                                     new QTableWidgetItem(QString::fromStdString(product.get_numeProdus())));
//        this->tableProducts->setItem(lineNumber, 1,
//                                     new QTableWidgetItem(QString::fromStdString(product.get_tipProdus())));
//        this->tableProducts->setItem(lineNumber, 2, new QTableWidgetItem(
//                QString::fromStdString(std::to_string((product.get_pretProdus())))));
//        this->tableProducts->setItem(lineNumber, 3,
//                                     new QTableWidgetItem(QString::fromStdString(product.get_producatorProdus())));
//        lineNumber++;
//    }
}

void MagazinGUI::connectSignalSlots() {
    QObject::connect(btnAddProdus, &QPushButton::clicked, this, &MagazinGUI::guiAddProducts);

    QObject::connect(btnStersProdus, &QPushButton::clicked, this, &MagazinGUI::guiDeleteProduct);

    QObject::connect(btnCautareProdus, &QPushButton::clicked, this, &MagazinGUI::guiSearchProduct);

    QObject::connect(btnModificarePret, &QPushButton::clicked, this, &MagazinGUI::guiModifyPrice);

    QObject::connect(btnUndoAction, &QPushButton::clicked, this, &MagazinGUI::guiUndoAction);

    QObject::connect(btnSortProducts, &QPushButton::clicked, [&]() {
        if (this->radioSrtNume->isChecked())
            this->reloadProductsList(service_magazin.sort_by_nume());
        else if (this->radioSrtPret->isChecked())
            this->reloadProductsList(service_magazin.sort_by_pret());
        else if (this->radioSrtNumeTip->isChecked())
            this->reloadProductsList(service_magazin.sort_by_nume_tip());
    });

    QObject::connect(btnFilterProductsNume, &QPushButton::clicked, [&]() {
        string filterNume = this->editFilterNume->text().toStdString();
        this->reloadProductsList(service_magazin.filtrareNume(filterNume));
    });

    QObject::connect(btnFilterProductsPret, &QPushButton::clicked, [&]() {
        string filterPret = this->editFilterPret->text().toStdString();
        this->reloadProductsList(service_magazin.filtrarePret(conversie_in_int(filterPret)));
    });

    QObject::connect(btnFilterProductsProducator, &QPushButton::clicked, [&]() {

        string filterProducator = this->editFilterProducator->text().toStdString();
        this->reloadProductsList(service_magazin.filtrareProducator(filterProducator));
    });

    QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
        this->reloadProductsList(service_magazin.get_all());
    });
    for (auto &button: DynamicButtons) {
        QObject::connect(button, &QPushButton::clicked, [&]() {
            this->reloadProductsList(service_magazin.filtrareProducator(button->text().toStdString()));
        });
    }
    //selectia in tabel
    QObject::connect(TableProducts->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        if (TableProducts->selectionModel()->selectedIndexes().isEmpty()) {
            editNume->setText("");
            editTip->setText("");
            editPret->setText("");
            editProducator->setText("");
        }
        int selRow = TableProducts->selectionModel()->selectedIndexes().at(0).row();
        auto cel0Index = TableProducts->model()->index(selRow, 0);
        auto cel1Index = TableProducts->model()->index(selRow, 1);
        auto cel2Index = TableProducts->model()->index(selRow, 2);
        auto cel3Index = TableProducts->model()->index(selRow, 3);
        auto cellValue1 = TableProducts->model()->data(cel0Index, Qt::DisplayRole).toString();
        auto cellValue2 = TableProducts->model()->data(cel1Index, Qt::DisplayRole).toString();
        auto cellValue3 = TableProducts->model()->data(cel2Index, Qt::DisplayRole).toString();
        auto cellValue4 = TableProducts->model()->data(cel3Index, Qt::DisplayRole).toString();

        editNume->setText(cellValue1);
        editTip->setText(cellValue2);
        editPret->setText(cellValue3);
        editProducator->setText(cellValue4);

    });
}

void MagazinGUI::guiAddProducts() {
    try {
        //incercam preluarea din QLineEdit-uri
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
//        int pret = editPret->text().toInt();
        string pret = editPret->text().toStdString();
        string producator = editProducator->text().toStdString();

        //optional golim QLineEdit-urile dupa apasarea butonului
        editNume->clear();
        editTip->clear();
        editPret->clear();
        editProducator->clear();

        bool adaugat = this->service_magazin.adaugareProdus_Service(nume, tip, pret, producator);
        this->reloadProductsList(this->service_magazin.get_all());

        //afisam un mesaj pentru a anunta utilizatorul ca produsul s a adaugat
        if (adaugat) {
            QMessageBox::information(this, "Info", QString::fromStdString("Produsul a fost adaugat cu succes!"));
            bool flag = false;
            for (auto &button: DynamicButtons) {
                std::string content = button->text().toStdString();

                if (producator == content) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                QPushButton *new_button = new QPushButton(QString::fromStdString(producator));
                DynamicButtons.push_back(new_button);
                lyButtons->addWidget(new_button);
                for (auto &button: DynamicButtons) {
                    QObject::connect(button, &QPushButton::clicked, [&]() {
                        this->reloadProductsList(service_magazin.filtrareProducator(button->text().toStdString()));
                    });
                }
            }

        }
        if (!adaugat)
            QMessageBox::information(this, "Info",
                                     QString::fromStdString("Produsul cu numele cautat exista deja in lista!"));
    } catch (MyException &myException) {
        QMessageBox::information(this, "Warning", QString::fromStdString(myException.getErrorMessage()));
    }
}

void MagazinGUI::guiDeleteProduct() {
    try {
        string numeprodus = editNume_S->text().toStdString();
        editNume_S->clear();
        std::string producator;
        for (auto &produs: this->service_magazin.get_all()) {
            if (produs.get_numeProdus() == numeprodus) {
                producator = produs.get_producatorProdus();
                break;
            }
        }
        bool sters = this->service_magazin.stergeProdus_Service(numeprodus);
        this->reloadProductsList(this->service_magazin.get_all());
        if (sters) {
            QMessageBox::information(this, "Info", QString::fromStdString("Produsul a fost sters cu succes!"));
            bool cautare_producator = this->service_magazin.existaProducator(producator);
            if (!cautare_producator) {
                for (int i = 0; i < DynamicButtons.size(); i++) {
                    QPushButton *button = DynamicButtons[i];
                    if (button->text().toStdString() == producator) {
                        button->hide();
                        lyButtons->removeWidget(button);
                        delete button;
                        DynamicButtons.erase(DynamicButtons.begin() + i);
                        break;
                    }
                }
            }
        }
        if (!sters)
            QMessageBox::information(this, "Info", QString::fromStdString("Produsul cu numele cautat nu exista!"));
    } catch (MyException &myexception) {
        QMessageBox::information(this, "Warning", QString::fromStdString(myexception.getErrorMessage()));
    }

}

void MagazinGUI::guiSearchProduct() {
    string nume_cautat = editNume_C->text().toStdString();
    editNume_C->clear();

    bool cautat = this->service_magazin.cautareProdus_Service(nume_cautat);
    if (cautat) {
        Produs prod;
        for (auto &produs: this->service_magazin.get_all()) {
            if (produs.get_numeProdus() == nume_cautat) {
                prod = produs;
                break;
            }
        }
        vector<Produs> list;
        list.push_back(prod);
        this->reloadProductsList(list);
        QMessageBox::information(this, "Info", QString::fromStdString("Produsul cautat a fost gasit cu succes!"));
    }
    if (!cautat) {
        QMessageBox::information(this, "Warning", QString::fromStdString("Produsul cautat nu a fost gasit!"));
    }
}

void MagazinGUI::guiModifyPrice() {
    string pret_produs = editPret_M->text().toStdString();
    string nume_produs = editNume_M->text().toStdString();
    editPret_M->clear();
    editNume_M->clear();
    bool modificat = this->service_magazin.modificarePretProdus_Service(nume_produs, pret_produs);
    if (modificat) {
        this->reloadProductsList(this->service_magazin.get_all());
        QMessageBox::information(this, "Info", QString::fromStdString("Produsul si-a modificat pretul cu succes!"));
    }
    if (!modificat)
        QMessageBox::information(this, "Warning", QString::fromStdString("Produsul nu a fost gasit!"));
}

void MagazinGUI::guiUndoAction() {
    this->service_magazin.undo();
    this->reloadProductsList(this->service_magazin.get_all());
    QMessageBox::information(this, "Info", QString::fromStdString("Operatie de undo realizata cu succes!"));
}

void MagazinGUI::generateInitialDButtons() {
    for (auto &produs: this->service_magazin.get_all()) {
        std::string producator = produs.get_producatorProdus();
        bool flag = false;
        for (auto &button: DynamicButtons) {
            std::string content = button->text().toStdString();
            if (content == producator) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            DynamicButtons.push_back(new QPushButton(QString::fromStdString(producator)));
        }

    }
}
