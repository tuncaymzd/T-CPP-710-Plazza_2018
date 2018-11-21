/*
** EPITECH PROJECT, 2018
** Margarita.h
** File description:
** this class represent the American Pizza
*/

#ifndef PLAZZA_MARGARITA_H
#define PLAZZA_MARGARITA_H

#include "BasePizza.h"
using std::string;

class Margarita : public BasePizza
{
public:
    //! Contructor of Margarita Pizza
    /*!
      \param size, represent the size of pizza (M, L, XL)
      \param time, represent the cooking time of pizza
      \return void
    */
    Margarita(string size, long time) : BasePizza(size, time, 1.5, "Margarita"){}
};


#endif //PLAZZA_MARGARITA_H
