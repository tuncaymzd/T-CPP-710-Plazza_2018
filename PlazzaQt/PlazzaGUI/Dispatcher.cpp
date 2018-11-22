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
notifierEventHandler Dispatcher::onNotify;

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
        while(!tmp.empty()){
            tmp.pop();
        }
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
    }
    for (int i = 0; i < tmp; i++) {
        std::queue<Command> c = myPopQueue();
        if (pid != 0) {
            pid = fork();
        }

        if (pid == 0) {
            std::cout << "Kitchen :" << getpid() << " Is cooking." << std::endl;
            Kitchen::setOnNotify(onNotify);
            Kitchen::Initialize((long) basetime, c, nbCookers);
            Kitchen::initializeProcessIds(getppid(), getpid());
            Kitchen::run();
            break;
        }
        wait(NULL);
        c.pop();
    }
}

void Dispatcher::setOnNotify(notifierEventHandler notif) {
    onNotify = notif;
}
