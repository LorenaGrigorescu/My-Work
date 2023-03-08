#include <iostream>
#include <QApplication>
#include <QWidget>
#include "Tests.h"
#include "GUI.h"

int main(int arc, char **argv) {
    QApplication a{arc, argv};
    testAll();
    std::string path = "../melodii.txt";
    Repository repository{path};
    Service service{repository};
    GUI gui{service};
    gui.show();
//    return 0;
    return a.exec();
}
