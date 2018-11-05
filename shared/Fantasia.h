//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_FANTASIA_H
#define PLAZZA_FANTASIA_H


#include "includes/BasePizza.h"

class Fantasia : BasePizza {

public:
    Fantasia(string size, long time) : BasePizza(size, time, 4.0){}
};


#endif //PLAZZA_FANTASIA_H
