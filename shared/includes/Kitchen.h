//
// Created by damien on 11/11/18.
//

#ifndef PLAZZA_KITCHEN_H
#define PLAZZA_KITCHEN_H

#include <condition_variable>
#include <mutex>
#include "ICook.h"

class Kitchen {

    std::unique_lock<std::mutex> uniqueLock;
    std::condition_variable threadCv;
    std::mutex mutX;
    bool canStart;
    bool cooking;
    ICook* cook;

public:
    Kitchen();
    void run();
    void stop();
    void setCooker(ICook* cook);
    void getCondition(std::condition_variable* &cv);
};

#endif //PLAZZA_KITCHEN_H
