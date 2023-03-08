//
// Created by Lorena on 01.06.2022.
//

#ifndef UNTITLED7_MYTABLEMODEL_H
#define UNTITLED7_MYTABLEMODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include <Qt>
#include <vector>
#include <qdebug.h>
#include <QFont>
#include "Domeniu.h"

using std::vector;

class MyTableModel : public QAbstractTableModel {
    std::vector<Produs> produse;
public:
    MyTableModel(const std::vector<Produs> &produse) : produse{produse} {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return produse.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::ForegroundRole) {
            auto produs = this->produse[index.row()];
            if (produs.get_producatorProdus() == "mandy") {
                return QBrush(Qt::magenta);
            }
        }
        if (role == Qt::FontRole) {
            QFont f;
            f.setItalic(index.row() % 10 == 2);
            f.setBold(index.row() % 10 == 2);
            return f;
        }
        if (role == Qt::DisplayRole) {
            Produs p = this->produse[index.row()];
            if (index.column() == 0)
                return QString::fromStdString(p.get_numeProdus());
            if (index.column() == 1)
                return QString::fromStdString(p.get_tipProdus());
            if (index.column() == 2)
                return QString::number(p.get_pretProdus());
            if (index.column() == 3)
                return QString::fromStdString(p.get_producatorProdus());
        }
        if (role == Qt::BackgroundRole) {

//            int row = index.row();
//            QModelIndex i = index.sibling(index.row(), 1);
//            if (i.data().toString() == "sare") {
//                QBrush bg(Qt::yellow);
//                return bg;
            auto produs = produse[index.row()];
            if(produs.get_pretProdus()>5){
                return QBrush(Qt::yellow);
            }
        }
        return QVariant{};
    }

    void setProduse(const vector<Produs> produse) {
        this->produse = produse;
        auto topLeft = createIndex(0, 0);
        auto bottomR = createIndex(rowCount()-1, columnCount()-1);
        emit dataChanged(topLeft, bottomR);
        emit layoutChanged();
    }

    Qt::ItemFlags flags(const QModelIndex & /*index*/) const {
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }

    bool insertRows(int row, int count, const QModelIndex &parent) override {
        beginInsertRows(parent, row, row+count-1);
        endInsertRows();
        return true;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) {
        if (role == Qt::DisplayRole) {
            if (orientation == Qt::Horizontal) {
                switch (section) {
                    case 0:
                        return tr("Nume");
                    case 1:
                        return tr("Tip");
                    case 2:
                        return tr("Pret");
                    case 3:
                        return tr("Producator");
                    default:
                        return QString("");

                }
            }
        }
        return QVariant();
    }
};

#endif //UNTITLED7_MYTABLEMODEL_H
