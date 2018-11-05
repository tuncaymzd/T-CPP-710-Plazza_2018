//
// Created by Tuncay Turkoglu on 05/11/2018.
//

#ifndef PLAZZA_COMMAND_H
#define PLAZZA_COMMAND_H

#include <iostream>

class Command {
public:
    Command(std::string name, std::string size);
    ~Command();

private:
    std::string namePizza; /*!< represent name of p izza*/
    std::string size; /*!< represent size of pizza  */
};
#endif //PLAZZA_COMMAND_H
