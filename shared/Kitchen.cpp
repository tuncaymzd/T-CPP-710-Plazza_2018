//
// Created by damien on 11/11/18.
//

#include "includes/Kitchen.h"
#include "includes/Cooker.h"
#include "includes/Fantasia.h"
#include "includes/Regina.h"
#include "includes/Margarita.h"
#include "includes/American.h"

bool Kitchen::cooking;
int Kitchen::myProcessesID;
int Kitchen::parentProcessesID;
notifierEventHandler Kitchen::onNotify;
std::queue<ICook*> Kitchen::cookQueue;
std::vector<std::thread*> Kitchen::threadPool;
std::mutex Kitchen::cookerMutex;
long Kitchen::time;

///Execute the cooking process
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
}

/// Set a notifier to Notify to the user of any info in this process
/// \param notif the notifier
void Kitchen::setOnNotify(notifierEventHandler notif) {
    onNotify = notif;
}

///Hang up this process when signal is called
void Kitchen::hangMeUp() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is hanging up.");
}

///Kill this process
void Kitchen::killMe() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is exiting.");
    exit(0);
}

void Kitchen::setCookers(std::queue<ICook *> cookQ) {
    cookQueue = cookQ;
}

///Called when a thread is terminated, and
/// If there is no more work, exit the process.
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

///Notify to parent process that this process has finished working.
void Kitchen::notifyFinished() {

}

///Initialize appropriate variables for kitchen functioning
void Kitchen::Initialize(long time, std::queue<Command> pizzaCommands, int cmdNum) {
    Command pCommand;
    string pizzaName = "";

    for(int i = 0; i < cmdNum; i++)
    {
        pCommand = pizzaCommands.front();
        pizzaName = pCommand.getNamePizza();
//        std::transform(pizzaName.begin(),
//                       pizzaName.end(), pizzaName.begin(), ::tolower);
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

/// Stating which Id belongs to this process and the parent's
/// \param parentId the parent's pid
/// \param myId this process' PID
void Kitchen::initializeProcessIds(int parentId, int myId) {
    parentProcessesID = parentId;
    myProcessesID = myId;
    myId;
}
