//
// Created by damien on 08/11/18.
//

#include <string>
#include <functional>

#ifndef PLAZZA_DELEGATES_H
#define PLAZZA_DELEGATES_H

#endif //PLAZZA_DELEGATES_H

using std::string;

typedef std::function<void(int, string)> timerCompletedEventHandler;
typedef std::function<void(string)> notifierEventHandler;