//
// Created by Lorena on 27.05.2022.
//

#include <QPainter>
#include "CosGUIDraw.h"

void CosGUIDraw::update() {
    repaint();
}

void CosGUIDraw::paintEvent(QPaintEvent *event){
    QPainter p{this};
    int x = 0;
    int y = 0;
    for (auto &product: this->service_magazin.ToateDinCos()) {
        x = rand() % (this->width() - 50) + 1;
        y = rand() % (this->height() - 50) + 1;
//        QRect target(x, y, 100, 94);
//        QRect source(0, 0, 732, 720);
//        QImage image;
//        image.load("./fotbal_flayer1.jpg");
//        p.drawImage(target, image,source);
        p.drawRect(QRect(x, y, 50, 50));

    }
}
