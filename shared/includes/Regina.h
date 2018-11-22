/*
** EPITECH PROJECT, 2018
** Regina.h
** File description:
** this class represent the American Pizza
*/

#ifndef PLAZZA_REGINA_H
#define PLAZZA_REGINA_H

#include <string>
#include "BasePizza.h"

using std::string;

class Regina : public BasePizza {

public:
    //! Contructor of Regina Pizza
    /*!
      \param size, represent the size of pizza (M, L, XL)
      \param time, represent the cooking time of pizza
      \return void
    */
    Regina(string size, long time) : BasePizza(size, time, 1, "Regina"){}
};


#endif //PLAZZA_REGINA_H
