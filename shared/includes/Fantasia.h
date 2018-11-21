/*
** EPITECH PROJECT, 2018
** American.h
** File description:
** this class represent the Fantasia Pizza
*/

#ifndef PLAZZA_FANTASIA_H
#define PLAZZA_FANTASIA_H


#include "BasePizza.h"

class Fantasia : public BasePizza {

public:
    //! Contructor of Fantasia Pizza
    /*!
      \param size, represent the size of pizza (M, L, XL)
      \param time, represent the cooking time of pizza
      \return void
    */
    Fantasia(string size, long time) : BasePizza(size, time, 4.0, "Fantasia"){}
};

#endif //PLAZZA_FANTASIA_H
