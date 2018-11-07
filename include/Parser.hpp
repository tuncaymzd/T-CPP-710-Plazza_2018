/*
** EPITECH PROJECT, 2018
** Parser.hpp
** File description:
** Parser for the orders
*/

#ifndef PLAZZA_PARSER_HPP
#define PLAZZA_PARSER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include "../Error.cpp"

class Parser {
public:
    std::ifstream files;

    Parser();
    ~Parser();

    /*!
      \brief Separate a string in substring using c
      \param str a string to split il element separate by c
      \param c a char, the value of the delimiter
      \return string vector, the vector with all the substring of str
    */
    std::vector<std::string> explode(std::string str, char c);

    /*!
       \brief Passe a string in lower case
       \param str the element that need to be passed in lower case
       \return string, the str in lower case
    */
    std::string toLowerCase(std::string str);

    /*!
      \brief Compare a string with the string of a vector and return the value if match
      \param str a string to be compare with the elements of v_str
      \param v_str a string vector of allowed instructions or type
      \return string, the value when there is a match
    */
    std::string compare(std::string str, std::vector<std::string>v_str);

    /*!
      \brief Check is the value in parameter is a valid int
      \param str, the string to checked
      \return int, the string casted
    */
    int isValidInt(std::string str);

    /*!
      \brief Check if all the element of the order are valid and return a tuple with the elements
      \param line, a string with the order
      \return tuple(string, string, int), with the name, the size and the quantity of pizza needed
      \sa compare() explode() isValidInt()
    */
    std::tuple<std::string, std::string, int> parse(std::string line);

private:
    std::vector<std::string> pizza; /*!< List of the allowed pizza name  */
    std::vector<std::string> size; /*!< List of the allowed pizza size*/
};


#endif //PLAZZA_PARSER_HPP
