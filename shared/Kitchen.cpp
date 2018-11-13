//
// Created by damien on 11/11/18.
//

#include "includes/Kitchen.h"

bool Kitchen::cooking;
int Kitchen::myProcessesID;
int Kitchen::parentProcessesID;
notifierEventHandler Kitchen::onNotify;
std::queue<ICook*> Kitchen::cookQueue;
std::vector<std::thread*> Kitchen::threadPool;

///Execute the cooking process
void Kitchen::run() {
}

void Kitchen::setOnNotify(notifierEventHandler notif) {
    onNotify = notif;
}


void Kitchen::hangMeUp() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is hanging up.");
}

void Kitchen::killMe() {
    onNotify("Kitchen : "+std::to_string(myProcessesID)+" is exiting.");
    exit(0);
}

void Kitchen::setCooker(std::queue<ICook *> cookQ) {
    cookQueue = cookQ;
}
