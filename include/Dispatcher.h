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
public:
    static void initialize(int numberOfKitchens, int numberOfCookers, int time, std::queue<Command> pizzaCommands);
    static Command myPop();
    static std::queue<Command> myPopQueue();
    static void splitTheCommands();
    static void createKitchens();

    static int nbKitchens;
    static int nbCookers;
    static int basetime;
    static std::queue<Command> theCommands;
    static std::queue<std::queue<Command>> theCommandsSplit;
};


#endif //PLAZZA_DISPATCHER_H