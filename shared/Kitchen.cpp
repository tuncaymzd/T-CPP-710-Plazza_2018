//
// Created by damien on 11/11/18.
//

#include "includes/Kitchen.h"

///Construct the kitchen
Kitchen::Kitchen() {
    cooking = true;
    canStart = false;
    uniqueLock = std::unique_lock<std::mutex>(mutX);
}

/// Add a new Cooker to this kitchen
/// And set the kitchen in a ready position
/// \param cook The cooking item
void Kitchen::setCooker(ICook *cook) {
    this->cook = cook;
    canStart = true;
}

/// Get the thread running condition to avoid deadlocks
/// \param cv outer condition variable passed by reference
void Kitchen::getCondition(std::condition_variable *&cv) {
    cv = &(this)->threadCv;
}

///Stop cooking the pizza
void Kitchen::stop() {
    cooking = false;
}

///Execute the cooking process
void Kitchen::run() {
    while(cooking) {
        if(canStart) {
            canStart = false;
            cook->cook();
            cook->finish();
        }
    }
}
