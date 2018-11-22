/*
** EPITECH PROJECT, 2018
** kitchen.h
** File description:
** this is static class and represent kitchen
*/

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
    //! kill this process (kitchen)
    /*!
      \param void
      \return void
    */
    static void killMe();
    //! kill this process (kitchen)
    /*!
      \param void
      \return void
    */
    static void killMe(int v);

    //! Hang up this process when signal is called
    /*!
      \param void
      \return void
    */
    static void hangMeUp();

    //! Set a notifier to Notify to the user of any info in this process
    /*!
      \param notif, represent the notifier
      \return void
    */
    static void setOnNotify(notifierEventHandler notif);

    //! Execute the cooking process
    /*!
      \param void
      \return void
    */
    static void run();

    //!Initialize appropriate variables for kitchen functioning
    /*!
      \param long, represent time
      \param pizzaCommands represent queue of commands
      \param cmdNum represent num of cmd
      \return void
    */
    static void Initialize(long time, std::queue<Command> pizzaCommands, int cmdNum);

    //!set cookers in kitchens
    /*!
      \param cookQ, is queue of cookers
      \return void
    */
    static void setCookers(std::queue<ICook*> cookQ);

    //!Called when a thread is terminated, and if there is no more work, exit the process.
    /*!
      \param thIndex, represent thread index
      \return true if this thread is terminated else return false
    */
    static bool threadTerminated(int thIndex);

    //!Stating which Id belongs to this process and the parent's
    /*!
      \param parentId the parent's pid
      \param myId this process' PID
      \return void
    */
    static void initializeProcessIds(int parentId, int myId);

    //!Notify to parent process that this process has finished working.
    static void notifyFinished();
};

#endif //PLAZZA_KITCHEN_H
