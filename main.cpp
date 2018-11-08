#include <iostream>
#include "include/Controleur.hpp"

int main(int argc, char* argv[])
{
    Controleur *control = new Controleur(argc, argv);

    try {
        control->readFile(argv[1]);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}