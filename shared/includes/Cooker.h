//
// Created by damien on 10/11/18.
//

#ifndef PLAZZA_COOK_H
#define PLAZZA_COOK_H


#include <condition_variable>
#include "ICook.h"
#include "Delegates.h"
#include "BasePizza.h"

class Cooker : public ICook{

    std::condition_variable cv;
    std::mutex mutx;
    std::unique_lock<std::mutex> uniqueLock;
    bool cooking;
    bool canCook;
    notifierEventHandler onNotify;
    BasePizza pizza;
    int threadIndex;

public:
    Cooker(BasePizza pizza, int thi, notifierEventHandler onNotif) : onNotify(onNotif) , pizza(pizza), threadIndex(thi){};
    void cook();
    void finish();
    void setPizza(BasePizza pizza){
        this->pizza = pizza;
        canCook = true;
    }
    void getConditionVariable(std::condition_variable *&cv);
};

#endif //PLAZZA_COOK_H
