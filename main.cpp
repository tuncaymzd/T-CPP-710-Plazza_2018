#include <iostream>
#include "include/Controleur.hpp"

std::mutex logMutex;


/// Log messages from underlying layers to the user.
/// \param text system logs.
void logNotification(string text) {
    logMutex.lock();
    std::cout << text << "\n";
    logMutex.unlock();
}

int main(int argc, char* argv[])
{
    Controleur *control = new Controleur(argc, argv, &logNotification);

    try {
        control->readFile(argv[1]);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

