#include <iostream>
#include <wait.h>
#include "include/Controleur.hpp"
#include "shared/includes/Kitchen.h"
#include "include/Dispatcher.h"
std::mutex logMutex;


/// Log messages from underlying layers to the user.
/// \param text system logs.
void logNotification(string text) {
    logMutex.lock();
    std::cout << text << "\n";
    logMutex.unlock();
}

int sizeElem(std::string elem) {
    int cpt = 1;

    if (elem.size() == 0){
        return 0;
    }
    for (int i = 0; i < elem.size(); i++) {
        if(elem[i] == ' '){
            cpt++;
        }
    }
    return cpt;
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
        Dispatcher::initialize(numbersOfKitchens, numbersOfCookers, baseTime, listOfCommands);
        Dispatcher::splitTheCommands();
        Dispatcher::setOnNotify(logNotification);
        Dispatcher::createKitchens();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    /// End Init
    return 0;
}

