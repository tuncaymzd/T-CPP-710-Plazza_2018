/*
** EPITECH PROJECT, 2018
** BasePizza.h
** File description:
** this class represent the Pizza
*/

#ifndef PLAZZA_BASEPIZZA_H
#define PLAZZA_BASEPIZZA_H

#include <string>
#include "string.h"
using std::string;

class BasePizza {

    string size;
    long cookingTime;
    string name;

public:
    //! Contructor of Pizza
    /*!
      \param size, represent the size of pizza (M, L, XL)
      \param cooking time, represent the cooking time of pizza
      \param t, represent the base time
      \param name, represent the name of pizza
      \return void
    */
    BasePizza(string size, long cookingTime, float t, string name) : size(size), name(name),
        cookingTime(static_cast<long>(cookingTime * t)){};

    //! get size of pizza
    /*!
      \param void
      \return string, represent size of pizza
    */
    virtual const string &getSize() const {
        return size;
    }

    //! get cooking time
    /*!
      \param void
      \return long, represent cooking time of pizza
    */
    virtual long getCookingTime() const {
        return cookingTime;
    }

    //! get name of pizza
    /*!
      \param void
      \return string, represent name of pizza
    */
    virtual const string &getName() const {
        return name;
    }
};


#endif //PLAZZA_BASEPIZZA_H
