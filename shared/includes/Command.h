/*
** EPITECH PROJECT, 2018
** Command.h
** File description:
** this class represent the command
*/

#ifndef PLAZZA_COMMAND_H
#define PLAZZA_COMMAND_H

#include <iostream>

class Command {
public:

    Command(){}

    //! Contructor of Command
    /*!
      \param name, represent name of pizza
      \param size, represent the size of pizza (M, L, XL)
      \return void
    */
    Command(std::string name, std::string size);

    ~Command();

    //! get name of pizza
    /*!
      \param void
      \return string, represent name of pizza
    */
    const std::string &getNamePizza() const;

    //! get size of pizza
    /*!
      \param void
      \return string, represent the size of pizza
    */
    const std::string &getSize() const;

private:
    std::string namePizza; /*!< represent name of pizza*/
    std::string size; /*!< represent size of pizza  */
};
#endif //PLAZZA_COMMAND_H
