//
// Created by damien on 08/11/18.
//

#include "includes/Timer.h"

#include <chrono>
#include <thread>
#include <thread>

/// Restarts the timer when required
void Timer::restartTimer()
{
    endTimer = true;
    std::this_thread::sleep_for (std::chrono::milliseconds(1));
    startTimer();
}

///Starts running the timer
void Timer::startTimer()
{
    auto milisecondsDuration = std::chrono::milliseconds(duration);
    timerThread = std::thread([=]()
                              {
                                  while(!endTimer)
                                  {
                                      std::this_thread::sleep_for (std::chrono::milliseconds(milisecondsDuration));
                                      completedListener.timerCompleted(entityId, cause);
                                  }
                              });
}

///Stops the timer
void Timer::stopTimer() {
    endTimer = true;
    timerThread.join();
}

