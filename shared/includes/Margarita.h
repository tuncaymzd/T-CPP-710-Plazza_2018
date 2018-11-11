//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_MARGARITA_H
#define PLAZZA_MARGARITA_H

#include "BasePizza.h"
using std::string;

class Margarita : BasePizza
{
public:
    Margarita(string size, long time) : BasePizza(size, time, 1.5, "Margarita"){}
};


#endif //PLAZZA_MARGARITA_H
