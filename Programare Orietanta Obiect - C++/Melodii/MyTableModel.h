//
// Created by Lorena on 20.06.2022.
//

#ifndef EXAMEN_MYTABLEMODEL_H
#define EXAMEN_MYTABLEMODEL_H


#include <QAbstractTableModel>
#include "Service.h"

class MyTableModel : public QAbstractTableModel {
    Service &service;
public:
    MyTableModel(Service &service) : service(service) {};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return this->service.getMelodii().size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 6;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        Melodie m = this->service.getMelodii()[index.row()];
        if (role == Qt::DisplayRole) {
            if (index.column() == 0)
                return QString::fromStdString(std::to_string(m.getId()));
            if(index.column()==1)
                return QString::fromStdString(m.getTitlu());
            if(index.column()==2)
                return QString::fromStdString(m.getArtist());
            if(index.column()==3)
                return QString::fromStdString(m.getGen());
            if(index.column()==4)
                return QString::fromStdString(std::to_string(this->service.acelasiAutor(m.getArtist())));
            if(index.column()==5)
                return QString::fromStdString(std::to_string(this->service.acelasiGen(m.getGen())));
        }
        return QVariant{};
    }
    Qt::ItemFlags item(int section, Qt::Orientation orientation, int role) const
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const{
        if(role==Qt::DisplayRole)
        {
            if(orientation==Qt::Horizontal)
            {
                if(section==0)
                    return tr("Id");
                if(section==1)
                    return tr("Titlu");
                if(section==2)
                    return tr("Artist");
                if(section==3)
                    return tr("Gen");
                if(section==4)
                    return tr("Acelasi autor");
                if(section==5)
                    return tr("Acelasi gen");
                return QString("");
            }
        }
        return QVariant{};
    }
};


#endif //EXAMEN_MYTABLEMODEL_H
