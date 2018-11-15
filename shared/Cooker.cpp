//
// Created by damien on 10/11/18.
//

#include <chrono>
#include <thread>
#include "includes/Cooker.h"
#include "includes/Kitchen.h"

void Cooker::cook() {
    onNotify("Pizza: " + pizza.getName() + " " + " " + pizza.getSize() +
    " has started cooking and will last " + std::to_string(pizza.getCookingTime()) + " Miliseconds.\n");
    std::this_thread::sleep_for (std::chrono::milliseconds(pizza.getCookingTime()));
    finish();
}

void Cooker::finish() {
    onNotify("Pizza: " + pizza.getName() + " " + " " + pizza.getSize() +
             " has finished Cooking!\n");
    Kitchen::threadTerminated(threadIndex);
}
