//
// Created by damien on 08/11/18.
//

#ifndef PLAZZA_TIMERCOMPLETEDLISTENER_H
#define PLAZZA_TIMERCOMPLETEDLISTENER_H


#include "Enums.h"
#include "ITimerCompletedListener.h"

class TimerCompletedListener : ITimerCompletedListener
{

public:
    /// Fires each time a timer is completed
    /// \param unique A unique identifier for the entity ended
    /// \param cause The cause of the sudden completion of this timer
    virtual void timerCompleted(string unique, CompletionCause cause);
};
#endif //PLAZZA_TIMERCOMPLETEDLISTENER_H
