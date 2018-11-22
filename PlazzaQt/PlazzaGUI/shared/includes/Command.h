//
// Created by Tuncay Turkoglu on 05/11/2018.
//

#ifndef PLAZZA_COMMAND_H
#define PLAZZA_COMMAND_H

#include <iostream>

class Command {
public:
    Command(){}
    Command(std::string name, std::string size);
    ~Command();

    const std::string &getNamePizza() const;
    const std::string &getSize() const;

private:
    std::string namePizza; /*!< represent name of p izza*/
    std::string size; /*!< represent size of pizza  */
};
#endif //PLAZZA_COMMAND_H