//
// Created by Tuncay Turkoglu on 06/11/2018.
//

#ifndef PLAZZA_CONTROLEUR_HPP
#define PLAZZA_CONTROLEUR_HPP

#include <iostream>
#include <fstream>
#include <queue>
#include <tuple>
#include "Error.h"
#include "ParserConfig.h"
#include "Parser.hpp"
#include "../shared/includes/Command.h"

class Controleur {
public:

    Controleur(int argc, char* argv[]);
    ~Controleur();

    void readFile(std::string file);

    void addCommand(Command c);

    void deleteCommand();

    bool theCommandsIsEmpty();


private:
    std::queue<Command> theCommands;
    ParserConfig *parserConf;
    Parser *pars;
    int baseTime = 0;
    int numbersOfKitchens = 0;
    int numbersOfCooker = 0;
};


#endif //PLAZZA_CONTROLEUR_HPP