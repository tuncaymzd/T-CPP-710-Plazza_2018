//
// Created by damien on 11/11/18.
//

#include "include/Dispatcher.h"
#include "shared/includes/Cooker.h"
#include "shared/includes/Fantasia.h"
#include <algorithm>

std::vector<std::thread*> Dispatcher::threadPool;
std::vector<Kitchen*> Dispatcher::kitchenPool;
std::queue<ICook*> Dispatcher::cookQueue;
std::mutex Dispatcher::cookMutex;
std::mutex Dispatcher::kitchenMutex;


bool Dispatcher::startCookingProcess() {
    return false;
}

/// Add the kitchen
/// \param kitchen
void Dispatcher::addKitchen(Kitchen *kitchen) {

}

bool Dispatcher::stop() {
    return false;
}

void Dispatcher::initialize(int numberOfKitchens, std::queue<Command> pizzaCommands) {
    Command pCommand;
    string pizzaName =  "";

    for(int i = 0; i < numberOfKitchens; i++) {
        kitchenPool.push_back(new Kitchen());
    }
    while(!pizzaCommands.empty()) {
        pCommand = pizzaCommands.front();
        pizzaName = pCommand.getNamePizza();
        std::transform(pizzaName.begin(),
                       pizzaName.end(), pizzaName.begin(), ::tolower);
        if(pizzaName == "fantasia") {
            //cookQueue.push(new Fantasia(pCommand.getSize(), ))
        } else if(pizzaName == "margarita") {

        } else if(pizzaName == "regina") {

        } else if(pizzaName == "american") {

        }
    }
}
