/*
** EPITECH PROJECT, 2018
** ICook.h
** File description:
** this class represent interface for cooker
*/

#pragma once
#ifndef PLAZZA_ICOOK_H
#define PLAZZA_ICOOK_H


class ICook
{
public:

    //! Cook is cooking processus
    /*!
      \param void
      \return void
    */
    virtual void cook() = 0;

    //! finish is processus with the cooking is finish
    /*!
      \param void
      \return void
    */
    virtual void finish() = 0;
};

#endif //PLAZZA_ICOOK_H
