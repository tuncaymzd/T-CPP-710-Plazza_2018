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
    //static int baseTime;
    //static int numbersOfKitchens;
    //static int numbersOfCooker;

    Controleur();
    ~Controleur();

    void readFile(std::string file);

    void addCommand(Command c);

    void deleteCommand();

    bool theCommandsIsEmpty();


private:
    std::queue<Command> theCommands;
    std::fstream file;
    ParserConfig *parserConf;
    Parser *pars;
};


#endif //PLAZZA_CONTROLEUR_HPP