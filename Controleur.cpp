//
// Created by Tuncay Turkoglu on 06/11/2018.
//

#include "include/Controleur.hpp"

Controleur::Controleur() {
    this->parserConf = new ParserConfig();
    this->pars = new Parser();
}

void Controleur::addCommand(Command c) {
    this->theCommands.push(c);
}

bool Controleur::theCommandsIsEmpty() {
    return this->theCommands.empty();
}

void Controleur::deleteCommand() {
    if (this->theCommandsIsEmpty()) {
        throw Error("The commands pile is empty");
    }
    this->theCommands.pop();
}

void Controleur::readFile(std::string file) {
    std::string line;
    std::tuple<std::string, std::string, int> cmd;
    std::string pizzaName;
    std::string size;
    int nb = 0;
    int i = 0;

    this->file.open(file);
    if (!this->file.is_open()) {
        throw Error("This file can not be opened");
    }
    while (this->file.getline(file, line)) {
        cmd = this->pars.parse(line);
        pizzaName = std::get<0>(cmd);
        size = std::get<1>(cmd);
        nb = std::get<2>(cmd);
        while (i < nb) {
            this->addCommand(new Command(pizzaName, size));
            i++;
        }
        i = 0;
    }

    this->file.close();
}