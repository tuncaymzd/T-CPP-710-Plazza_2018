//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_AMERICAN_H
#define PLAZZA_AMERICAN_H


#include "BasePizza.h"

class American : BasePizza{

public:
    American(string size, long time) : BasePizza(size, time, 2.0, "American"){}
};


#endif //PLAZZA_AMERICAN_H
