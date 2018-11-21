/*
** EPITECH PROJECT, 2018
** American.h
** File description:
** this class represent the American Pizza
*/

#ifndef PLAZZA_AMERICAN_H
#define PLAZZA_AMERICAN_H


#include "BasePizza.h"

class American : public BasePizza{

public:

    //! Contructor of American Pizza
    /*!
      \param size, represent the size of pizza (M, L, XL)
      \param time, represent the cooking time of pizza
      \return void
    */
    American(string size, long time) : BasePizza(size, time, 2.0, "American"){}
};


#endif //PLAZZA_AMERICAN_H
