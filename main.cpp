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
    ///Init
    Controleur *control = new Controleur(argc, argv, &logNotification);
    int numbersOfCookers = control->getNumbersOfCooker();
    int numbersOfKitchens = control->getNumbersOfKitchens();
    int baseTime = control->getBaseTime();
    std::queue<Command> listOfCommands;
    try {
        control->readFile(argv[1]);
        listOfCommands = control->getTheCommands();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    /// End Init
    return 0;
}

