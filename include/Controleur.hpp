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
#include "../shared/includes/Delegates.h"
#include <thread>
#include <mutex>

using std::string;


class Controleur {
public:

    Controleur(int argc, char* argv[]);
    Controleur(int argc, char* argv[], notifierEventHandler notif);
    ~Controleur();

    void readFile(std::string file);

    void addCommand(Command c);

    void deleteCommand();

    bool theCommandsIsEmpty();

    const std::queue<Command> &getTheCommands() const;

    int getBaseTime() const;

    int getNumbersOfKitchens() const;

    int getNumbersOfCooker() const;

    Command getFirstCommand() const;

private:
    std::queue<Command> theCommands;
    ParserConfig *parserConf;
    Parser *pars;
    int baseTime = 0;
    int numbersOfKitchens = 0;
    int numbersOfCooker = 0;
    notifierEventHandler onNotify;
};

#endif //PLAZZA_CONTROLEUR_HPP