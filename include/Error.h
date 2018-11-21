/*
** EPITECH PROJECT, 2018
** Error.h
** File description:
** exception class
*/

#include <iostream>
#include <exception>

#ifndef PLAZZA_ERROR_H
#define PLAZZA_ERROR_H


class Error: public std::exception {
public:

    //! this is error constructor
    /*!
      \param phrase, represent description of error
      \return void
    */
    Error(std::string const& phrase="") throw()
            :m_phrase(phrase){}

    virtual const char* what() const throw() {
        return m_phrase.c_str();
    }

    virtual ~Error() throw() {
    }

private:
    std::string m_phrase;
};

#endif //PLAZZA_ERROR_H
