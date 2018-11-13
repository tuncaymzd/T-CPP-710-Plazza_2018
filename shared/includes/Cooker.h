//
// Created by damien on 10/11/18.
//

#ifndef PLAZZA_COOK_H
#define PLAZZA_COOK_H


#include "ICook.h"
#include "Delegates.h"
#include "BasePizza.h"

class Cooker : public ICook{

    notifierEventHandler onNotify;
    BasePizza pizza;

public:
    Cooker(BasePizza pizza) : pizza(pizza){};
    void cook();
    void finish();
};

#endif //PLAZZA_COOK_H
