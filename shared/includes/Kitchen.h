//
// Created by damien on 11/11/18.
//

#ifndef PLAZZA_KITCHEN_H
#define PLAZZA_KITCHEN_H

#include <condition_variable>
#include <mutex>
#include "ICook.h"
#include "Delegates.h"
#include "Command.h"
#include <queue>
#include <thread>

class Kitchen {
    static bool cooking;
    static int myProcessesID;
    static int parentProcessesID;
    static long time;
    static notifierEventHandler onNotify;
    static std::queue<ICook*> cookQueue;
    static std::vector<std::thread*> threadPool;
    static std::mutex cookerMutex;

public:
    static void killMe();
    static void hangMeUp();
    static void setOnNotify(notifierEventHandler notif);
    static void run();
    static void Initialize(long time, std::queue<Command> pizzaCommands, int cmdNum);
    static void setCookers(std::queue<ICook*> cookQ);
    static void threadTerminated(int thIndex);
    static void initializeProcessIds(int parentId, int myId);
    static void notifyFinished();
};

#endif //PLAZZA_KITCHEN_H
