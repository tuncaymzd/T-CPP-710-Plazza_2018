//
// Created by damien on 11/11/18.
//

#pragma once
#ifndef PLAZZA_DISPATCHER_H
#define PLAZZA_DISPATCHER_H

#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>

#include "../shared/includes/ICook.h"
#include "../shared/includes/Kitchen.h"
#include "../shared/includes/Command.h"

class Dispatcher {
    static std::vector<std::thread*> threadPool;
    static std::vector<Kitchen*> kitchenPool;
    static std::queue<ICook*> cookQueue;
    static std::mutex cookMutex;
    static std::mutex kitchenMutex;

public:
    static void initialize(int numberOfKitchens, long time, std::queue<Command> pizzaCommands);
    static bool startCookingProcess();
    static bool stop();
    static void addKitchen(Kitchen* kitchen);
};

#endif //PLAZZA_DISPATCHER_H