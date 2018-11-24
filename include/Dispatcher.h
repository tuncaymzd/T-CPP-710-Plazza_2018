/*
** EPITECH PROJECT, 2018
** Dispatcher.h
** File description:
** this is static class used for recover every configuration flag and initialize the kitchen pool
*/

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

    //! Initialize recover every configuration flag
    /*!
      \param numberOfKitchens, is int and he represent numbers of kitchens
      \param numberOfCookers, is int and he represent numbers of cookers per kitchens
      \param time, represent base time (ms)
      \param pizzaCommands, represent queue of commands
      \return void
    */
    static void initialize(int numberOfKitchens, int numberOfCookers, int time, std::queue<Command> pizzaCommands);

    //! myPop return first command of queue and removes it from the queue
    /*!
      \return first command of queue
    */
    static Command myPop();

    //! myPopQueue return first queue of commands on one kitchens and remove it
    /*!
      \return first queue of commands on one kitchens
    */
    static std::queue<Command> myPopQueue();

    //! this function distributes orders fairly to each kitchen
    /*!
      \param void
      \return void
    */
    static void splitTheCommands();

    //! this function create and initialize kitchen pool
    /*!
      \param void
      \return void
    */
    static void createKitchens();

    //! this function initialize notification of programm
    /*!
      \param notif represent notification
      \return void
    */
    static void setOnNotify(notifierEventHandler notif);

    //! Action performed when this process is killed
    static void onKill(int sig);

    static notifierEventHandler onNotify;
    static int nbKitchens;
    static int nbCookers;
    static int basetime;
    static std::queue<Command> theCommands;
    static std::queue<std::queue<Command>> theCommandsSplit;
};


#endif //PLAZZA_DISPATCHER_H