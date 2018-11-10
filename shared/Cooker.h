//
// Created by damien on 10/11/18.
//

#ifndef PLAZZA_COOK_H
#define PLAZZA_COOK_H


#include "includes/ICook.h"
#include "includes/Delegates.h"
#include "includes/BasePizza.h"

class Cooker : public ICook{

    notifierEventHandler onNotify;
    BasePizza pizza;

public:
    Cooker(BasePizza pizza) : pizza(pizza){};
    void cook();
    void finish();
};


#endif //PLAZZA_COOK_H
