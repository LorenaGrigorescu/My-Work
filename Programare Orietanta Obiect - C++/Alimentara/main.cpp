#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Teste.h"
#include "UI.h"
#include "Magazin_GUI.h"
#include "CosGUI.h"
#include "GUICombined.h"
#include "CosGUIDraw.h"


int main(int argc, char *argv[]) {
    std::cout << "Running tests...\n";
    testAll();
    std::cout << "All tests are OK!";
    std::cout << "\n";

    QApplication a(argc, argv);
    Repozitoriu_Magazin Repo_Magazin{};
    CosMagazin cosMagazin{};
    Service_Magazin Serv_Magazin{Repo_Magazin, cosMagazin};
    MagazinGUI Console_GUI{Serv_Magazin};
    CosGUI Console_CartGUI{Serv_Magazin};
    GUICombined guiCombined{Serv_Magazin, Console_GUI, Console_CartGUI};
//        Console_UI console{Serv_Magazin};
//        console.run_UI();
    guiCombined.show();
    return a.exec();
}

