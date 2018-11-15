//
// Created by damien on 11/11/18.
//

#include <unistd.h>
#include "include/Dispatcher.h"
#include "shared/includes/Kitchen.h"
#include "shared/includes/Cooker.h"
#include "shared/includes/Fantasia.h"
#include "shared/includes/Margarita.h"
#include "shared/includes/Regina.h"

int Dispatcher::nbKitchens;
int Dispatcher::nbCookers;
int Dispatcher::basetime;
std::queue<Command> Dispatcher::theCommands;
std::queue<std::queue<Command>> Dispatcher::theCommandsSplit;

void Dispatcher::initialize(int numberOfKitchens, int numberOfCookers, int time, std::queue<Command> pizzaCommands) {
    nbCookers = numberOfCookers;
    nbKitchens = numberOfKitchens;
    basetime = time;
    theCommands = pizzaCommands;
}

Command Dispatcher::myPop() {
    Command res;
    res = theCommands.front();
    theCommands.pop();
    return res;
}

std::queue<Command> Dispatcher::myPopQueue() {
    std::queue<Command> res;
    res = theCommandsSplit.front();
    theCommandsSplit.pop();
    return res;
}

void Dispatcher::splitTheCommands() {
    std::queue<std::queue<Command>> res;
    std::queue<Command> tmp;
    int i = 0;
    int x = 0;
    int elem = theCommands.size();
    while (i < elem) {
        while (x < nbCookers) {
            if (!theCommands.empty()) {
                tmp.emplace(myPop());
                x++;
            } else {
                break;
            }
        }
        res.emplace(tmp);
        i += x;
        x = 0;
    }
    theCommandsSplit = res;
}

void Dispatcher::createKitchens() {
    int tmp = theCommandsSplit.size();
    pid_t pid = -1;
    if (nbKitchens > tmp) {
        tmp = nbKitchens;

    for (int i = 0; i < tmp; i++) {
        if (pid != 0)
            pid = fork();
        if (pid == 0) {
            Kitchen::Initialize((long)basetime, myPopQueue(), nbCookers);
            break;
        }
    }
}
