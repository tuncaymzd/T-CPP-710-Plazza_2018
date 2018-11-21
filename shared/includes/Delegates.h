/*
** EPITECH PROJECT, 2018
** Delegates.h
** File description:
** this class is used for call different event
*/

#include <string>
#include <functional>

#ifndef PLAZZA_DELEGATES_H
#define PLAZZA_DELEGATES_H

using std::string;

//! this function is called if the timer is completed
/*!
  \param void
  \return std::function<void(int, string)> and represent a pointer of function
*/
typedef std::function<void(int, string)> timerCompletedEventHandler;

//! this function is called for notify different step
/*!
  \param void
  \return std::function<void(string)> and represent a pointer of function
*/
typedef std::function<void(string)> notifierEventHandler;

#endif //PLAZZA_DELEGATES_H