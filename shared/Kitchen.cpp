//
// Created by damien on 11/11/18.
//

#include "includes/Kitchen.h"
#include "includes/Cooker.h"
#include "includes/Fantasia.h"
#include "includes/Regina.h"
#include "includes/Margarita.h"
#include "includes/American.h"
#include <signal.h>

bool Kitchen::cooking;
int Kitchen::myProcessesID;
int Kitchen::parentProcessesID;
notifierEventHandler Kitchen::onNotify;
std::queue<ICook*> Kitchen::cookQueue;
std::vector<std::thread*> Kitchen::threadPool;
std::mutex Kitchen::cookerMutex;
long Kitchen::time;

void Kitchen::run() {
    ICook *currentCooker;
    std::thread *th;
    int size = cookQueue.size();

    for (int i = 0; i < size; ++i) {
        currentCooker = cookQueue.front();
        cookQueue.pop();
        th = new std::thread(&ICook::cook, currentCooker);
        threadPool.push_back(th);
        th->join();
        //std::this_thread::sleep_for (std::chrono::milliseconds(2000));
    }
    kill(parentProcessesID, SIGQUIT);
    std::this_thread::sleep_for (std::chrono::milliseconds(time*5));
    onNotify("\nEnding cooking after 5T time: \n");
    killMe();
}

void Kitchen::setOnNotify(notifierEventHandler notif) {
    onNotify = notif;
}

void Kitchen::hangMeUp() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is hanging up.");
}

void Kitchen::killMe() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is exiting.\n");
    exit(0);
}

void Kitchen::setCookers(std::queue<ICook *> cookQ) {
    cookQueue = cookQ;
}

bool Kitchen::threadTerminated(int thindex) {
    cookerMutex.lock();
    if(threadPool.empty()) {
        for (int i = 0; i < threadPool.size(); ++i) {
            threadPool[i]->join();
        }
        killMe();
    } else {
        cookerMutex.unlock();
        return true;
    }
    return false;
}

void Kitchen::notifyFinished() {

}

void Kitchen::killMe(int v)
{
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" was killed by : .\n"+std::to_string(v));
}

///Initialize appropriate variables for kitchen functioning
void Kitchen::Initialize(long t, std::queue<Command> pizzaCommands, int cmdNum) {
    Command pCommand;
    string pizzaName = "";
    time = t;

    signal(SIGQUIT, Kitchen::killMe);

    for(int i = 0; i < cmdNum; i++)
    {
        pCommand = pizzaCommands.front();
        pizzaName = pCommand.getNamePizza();
        if (pizzaName == "Fantasia") {
            cookQueue.push(new Cooker(*new Fantasia(pCommand.getSize(), time), i, onNotify));
        } else if (pizzaName == "Margarita") {
            cookQueue.push(new Cooker(*new Margarita(pCommand.getSize(), time), i, onNotify));
        } else if (pizzaName == "Regina") {
            cookQueue.push(new Cooker(*new Regina(pCommand.getSize(), time), i, onNotify));
        } else if (pizzaName == "American") {
            cookQueue.push(new Cooker(*new American(pCommand.getSize(), time), i, onNotify));
        }
        pizzaCommands.pop();
    }
}

void Kitchen::initializeProcessIds(int parentId, int myId) {
    parentProcessesID = parentId;
    myProcessesID = myId;
    myId;
}