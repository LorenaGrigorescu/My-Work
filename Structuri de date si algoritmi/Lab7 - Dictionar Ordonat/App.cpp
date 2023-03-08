#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "TestLab.h"

int main() {
    test_goleste();
    testAll();
    testAllExtins();
    std::cout << "Finished Tests!" << std::endl;
}
