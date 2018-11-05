//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_BASEPIZZA_H
#define PLAZZA_BASEPIZZA_H

#include <string>
#include "string.h"
using std::string;

class BasePizza {

    string size;
    long cookingTime;

public:
    BasePizza(string size, long cookingTime, float t) : size(size),
        cookingTime(static_cast<long>(cookingTime * t)){};
};


#endif //PLAZZA_BASEPIZZA_H
