//
// Created by Lorena on 20.06.2022.
//

#ifndef EXAMEN_GUI_H
#define EXAMEN_GUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Service.h"
#include "MyTableModel.h"
#include <QPushButton>
#include <QTableView>
#include <QMessageBox>
#include <QPainter>

class GUI : public QWidget {
    QHBoxLayout *mainly;
    QHBoxLayout *leftly;
    QVBoxLayout *rightly;

    QTableView *tableView;
    MyTableModel *model;

    QLabel *titlulbl;
    QLineEdit *titluLE;

    QLabel *artistlbl;
    QLineEdit *artistLE;

    QLabel *genlbl;
    QLineEdit *genLE;

    QPushButton *butonAdauga;
    QPushButton *butonSterge;

    Service &service;

    void initializeGUIComponents();

    void populate();

    void connectSignalSlots();

    void paintEvent(QPaintEvent* event);

public:
    GUI(Service &service) : service(service) {
        initializeGUIComponents();
        populate();
        connectSignalSlots();
    };
};


#endif //EXAMEN_GUI_H
