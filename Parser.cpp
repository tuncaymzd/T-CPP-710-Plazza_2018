/*
** EPITECH PROJECT, 2018
** Parser.cpp
** File description:
** Parser for simple AMV instructions
*/

#include "include/Parser.hpp"

Parser::Parser()
{
    this->pizza = {"Margarita", "Regina", "American", "Fantasia"};
    this->size = {"M", "L", "XL"};
}

std::vector<std::string> Parser::explode(std::string str, char c)
{
    std::string buffer = "";
    std::vector<std::string> instruction_container;
    int i = 0;

    while(str[i]) {
        if (str[i] != c) {
            buffer += str[i];
        } else {
            instruction_container.push_back(buffer);
            buffer = "";
            while (str[i] == c) {
                i++;
            }
            i--;
        }
        i++;
    }
    if (buffer != "") {
        instruction_container.push_back(buffer);
    }
    if (!instruction_container.empty()) {
        return (instruction_container);
    } else {
        throw Error("Not a valid order");
    }
}

std::string Parser::toLowerCase(std::string str)
{
    for (int i = 0; i < str.size(); i++) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}

std::string Parser::compare(std::string str, std::vector<std::string> stock)
{
    int i = 0;
    str = toLowerCase(str);
    while (i < stock.size()) {
        if (str.compare(toLowerCase(stock[i])) == 0) {
            return (stock[i]);
        }
        i++;
    }
    throw Error("Your order is not in our menu");
}

int Parser::isValidInt(std::string pizzaQty)
{
    int res = std::stoi(pizzaQty);
    if (res < 50 && res > 0) {
        return res;
    } else {
        throw Error ("Not a valid int");
    }
}

std::tuple<std::string, std::string, int> Parser::parse(std::string line)
{
    std::string pizzaName;
    std::string pizzaSize = "M";
    int pizzaQty = 1;
    std::vector<std::string> stock = explode(line, ' ');
    int size = stock.size();

    if (size > 3 || size < 1) {
        throw Error("Not a valid order");
    } else if (size == 1) {
        pizzaName = compare(stock[0], this->pizza);
        return std::make_tuple(pizzaName, pizzaSize, pizzaQty);
    } else if (size == 2) {
        pizzaName = compare(stock[0], this->pizza);
        try {
            isValidInt(stock[1]);
        } catch (const std::exception& e) {
            pizzaSize = compare(stock[1], this->size);
        }
        return std::make_tuple(pizzaName, pizzaSize, pizzaQty);
    } else {
        pizzaName = compare(stock[0], this->pizza);
        pizzaSize = compare(stock[1], this->size);
        pizzaQty = isValidInt(stock[2]);
        return std::make_tuple(pizzaName, pizzaSize, pizzaQty);
    }
}