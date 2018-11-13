//
// Created by damien on 11/11/18.
//

#ifndef PLAZZA_KITCHEN_H
#define PLAZZA_KITCHEN_H

#include <condition_variable>
#include <mutex>
#include "ICook.h"
#include "Delegates.h"
#include <queue>
#include <thread>

class Kitchen {

    static bool cooking;
    static int myProcessesID;
    static int parentProcessesID;
    static notifierEventHandler onNotify;
    static std::queue<ICook*> cookQueue;
    static std::vector<std::thread*> threadPool;

public:
    static void killMe();
    static void hangMeUp();
    static void setOnNotify(notifierEventHandler notif);
    static void run();
    static void setCooker(std::queue<ICook*> cookQ);
};

#endif //PLAZZA_KITCHEN_H
