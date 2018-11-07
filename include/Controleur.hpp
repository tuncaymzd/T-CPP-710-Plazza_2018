//
// Created by Tuncay Turkoglu on 06/11/2018.
//

#ifndef PLAZZA_CONTROLEUR_HPP
#define PLAZZA_CONTROLEUR_HPP

#include <queue>
#include <iostream>
#include "../shared/Command.cpp"
#include "../ParserConfig.cpp"
#include <fstream>
#include "../Error.cpp"
#include <tuple>
#include <get>

//inclure parser.cpp

class Controleur {
public:
    static int baseTime;
    static int numbersOfKitchens;
    static int numbersOfCooker;

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