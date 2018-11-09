//
// Created by damien on 08/11/18.
//

#ifndef PLAZZA_TIMER_H
#define PLAZZA_TIMER_H


#include <thread>
#include "Enums.h"
#include "TimerCompletedListener.h"
#include "Delegates.h"

class Timer
{
    timerCompletedEventHandler timerCompletedEvent;
    TimerCompletedListener completedListener;
    long duration;
    bool endTimer;
    CompletionCause cause;
    string entityId;
    std::thread timerThread;

public:
    Timer(timerCompletedEventHandler completedEvent, long duration) :
            duration(duration), timerCompletedEvent(completedEvent){};
    Timer(TimerCompletedListener completedListener1, CompletionCause cause, string entityId)
            : completedListener(completedListener1), entityId(entityId), cause(cause){};
    Timer(CompletionCause cause, string entityId)
            : entityId(entityId), cause(cause){};
    void restartTimer();
    void stopTimer();
    void startTimer();
    void checkTimer();
    void speak()
    {
        timerCompletedEvent(1, " Hera");
    }

};


#endif //PLAZZA_TIMER_H
