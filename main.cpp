#include <iostream>
#include "include/Controleur.hpp"
<<<<<<< HEAD
#include "shared/includes/Kitchen.h"
=======
#include "include/Dispatcher.h"
>>>>>>> eacfafca1ba873d7de9643c8c367adb0758f6747

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
        auto cmds = control->getTheCommands();
        Kitchen::setOnNotify(logNotification);
        Kitchen::Initialize(1000, cmds, cmds.size());
        Kitchen::run();
        //listOfCommands = control->getTheCommands();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
//    Dispatcher::initialize(numbersOfKitchens, numbersOfCookers, baseTime, listOfCommands);
//    Dispatcher::splitTheCommands();
//    Dispatcher::createKitchens();
    /// End Init
    return 0;
}

