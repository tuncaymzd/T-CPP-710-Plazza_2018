//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_REGINA_H
#define PLAZZA_REGINA_H

#include <string>
#include "BasePizza.h"

using std::string;

class Regina : public BasePizza {

public:
    Regina(string size, long time) : BasePizza(size, time, 1, "Regina"){}
};


#endif //PLAZZA_REGINA_H
