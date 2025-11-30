//
// Created by Carolina P. Nogueira 2016
//

#include <iostream>
#include <string>
#include "Manager.h"


// int main(int argc, char* argv[])
// {
//     std::cout << "Nothing implemented, yet" << std::endl;
// }
#include "Manager.h"
#include <iostream>

int main() {
    ClassProject::Manager manager;
    std::cout << "Manager Initialized. True ID: " << manager.True() << std::endl;
    return 0;
}