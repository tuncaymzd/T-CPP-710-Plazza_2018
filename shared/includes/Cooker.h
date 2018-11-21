/*
** EPITECH PROJECT, 2018
** Cooker.h
** File description:
** this class represent a cooker
*/

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

    //! Contructor of Cooker
    /*!
      \param pizza, represent one pizza
      \param thi, represent thread index
      \param onNotif, represent notification
      \return void
    */
    Cooker(BasePizza pizza, int thi, notifierEventHandler onNotif) : onNotify(onNotif) , pizza(pizza), threadIndex(thi){};

    //! Cook is cooking processus
    /*!
      \param void
      \return void
    */
    void cook();

    //! finish is processus with the cooking is finish
    /*!
      \param void
      \return void
    */
    void finish();

    //! set pizza
    /*!
      \param pizza, is pizza to set
      \return void
    */
    void setPizza(BasePizza pizza){
        this->pizza = pizza;
        canCook = true;
    }

    //! this fonction return a condition variable
    /*!
      \param cv, represent condition variable and it use to make a thread wait
      \return void
    */
    void getConditionVariable(std::condition_variable *&cv);
};

#endif //PLAZZA_COOK_H
