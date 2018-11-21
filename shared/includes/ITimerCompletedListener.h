/*
** EPITECH PROJECT, 2018
** ITimerCompletedListener.h
** File description:
** this class is interface and he represent timer
*/

#ifndef PLAZZA_ITIMERCOMPLETEDLISTENER_H
#define PLAZZA_ITIMERCOMPLETEDLISTENER_H

#include <string>
#include "Enums.h"

using std::string;

//! Listens to a timer which ended
class ITimerCompletedListener
{
public:
    //! Fires each time a timer is completed
    /*!
      \param unique A unique identifier for the entity ended
      \param cause The cause of the sudden completion of this timer
      \return void
    */
    virtual void timerCompleted(string unique, CompletionCause cause) = 0;
};

#endif //PLAZZA_ITIMERCOMPLETEDLISTENER_H