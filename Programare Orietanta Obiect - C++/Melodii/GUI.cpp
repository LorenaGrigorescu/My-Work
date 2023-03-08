//
// Created by Lorena on 20.06.2022.
//

#include "GUI.h"

void GUI::initializeGUIComponents() {
    mainly = new QHBoxLayout;
    leftly = new QHBoxLayout;
    rightly = new QVBoxLayout;

    tableView = new QTableView;
    this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model = new MyTableModel(service);

    titlulbl = new QLabel("Titlu");
    titluLE = new QLineEdit;
    rightly->addWidget(titlulbl);
    rightly->addWidget(titluLE);

    artistlbl = new QLabel("Artist");
    artistLE = new QLineEdit;
    rightly->addWidget(artistlbl);
    rightly->addWidget(artistLE);

    genlbl = new QLabel("Gen");
    genLE = new QLineEdit;
    rightly->addWidget(genlbl);
    rightly->addWidget(genLE);

    butonAdauga = new QPushButton("Adauga melodie");
    rightly->addWidget(butonAdauga);
    butonSterge = new QPushButton("Sterge melodie");
    rightly->addWidget(butonSterge);

    leftly->addWidget(tableView);
    mainly->addLayout(leftly);
    mainly->addLayout(rightly);
    this->setLayout(mainly);

}

void GUI::populate() {
    this->tableView->setModel(nullptr);
    this->tableView->setModel(model);
}

void GUI::connectSignalSlots() {
    QObject::connect(butonAdauga, &QPushButton::clicked, this, [&]() {
        std::string titlu = titluLE->text().toStdString();
        std::string artist = artistLE->text().toStdString();
        std::string gen = genLE->text().toStdString();
        if (gen != "pop" && gen != "rock" && gen != "folk" && gen != "disco") {
            QMessageBox::information(this, "Warning", "Genul nu corespunde cerintelor");
            return;
        }
        int id = rand() % 1000;
        bool adaugat = this->service.adaugaMelodie(id, titlu, artist, gen);
        while (!adaugat) {
            id = rand() % 1000;
            adaugat = this->service.adaugaMelodie(id, titlu, artist, gen);
        }
        populate();
        titluLE->clear();
        artistLE->clear();
        genLE->clear();
    });

    QObject::connect(butonSterge, &QPushButton::clicked, this, [&]() {
        auto index = this->tableView->currentIndex();
        int id = model->sibling(index.row(), 0, index).data().toString().toInt();
        this->service.stergeMelodie(id);
        populate();
    });
}

void GUI::paintEvent(QPaintEvent *event) {
    int startAngle = 0 * 16;
    int spanAngle = 360 * 16;
    int catePop = this->service.acelasiGen("pop");
    int cateFolk = this->service.acelasiGen("folk");
    int cateRock = this->service.acelasiGen("rock");
    int cateDisco = this->service.acelasiGen("disco");

    QPainter painterPop(this);
    QPainter painterRock(this);
    QPainter painterFolk(this);
    QPainter painterDisco(this);

    for (int i = 0; i < catePop; i++) {
        QRectF rectanglePop(0 - 10 * i, 0 - 10 * i, 80.0 + i * 50, 80.0 + i * 50);
        painterPop.drawArc(rectanglePop, startAngle, spanAngle);

    }
    for (int i = 0; i < cateRock; i++) {
        QRectF rectangleRock(0 - 40 * i, this->height() - 40 * i, 80.0 + i * 50, 80.0 + i * 50);
        painterRock.drawArc(rectangleRock, startAngle, spanAngle);

    }

    for (int i = 0; i < cateFolk; i++) {
        QRectF rectangleFolk(this->width() - 40.0*i, this->height() - 40.0*i, 80.0+i*50, 80.0+i*50);
        painterFolk.drawArc(rectangleFolk, startAngle, spanAngle);
    }

    for(int i=0; i<cateDisco; i++)

    {
        QRectF rectangleDisco(this->width() - 40.0*i, 0 - 40.0*i, 80.0+i*50, 80.0+i*50);
        painterDisco.drawArc(rectangleDisco, startAngle, spanAngle);
    }

}
