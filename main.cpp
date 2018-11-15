#include <iostream>
#include "include/Controleur.hpp"
#include "shared/includes/Kitchen.h"

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
        auto cmds = control->getTheCommands();
        Kitchen::setOnNotify(logNotification);
        Kitchen::Initialize(1000, cmds, cmds.size());
        Kitchen::run();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

