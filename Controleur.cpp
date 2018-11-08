//
// Created by Tuncay Turkoglu on 06/11/2018.
//

#include "include/Controleur.hpp"

Controleur::Controleur(int argc, char* argv[]) {
    this->parserConf = new ParserConfig();
    this->pars = new Parser();
    this->parserConf->initParser(argc, argv);
    this->baseTime = this->parserConf->getBaseTime();
    this->numbersOfKitchens = this->parserConf->getNumbersOfKitchens();
    this->numbersOfCooker = this->parserConf->getNumbersOfCookers();
}

void Controleur::addCommand(Command c) {
    this->theCommands.emplace(c);
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
    std::fstream infile;
    std::string line;
    std::tuple<std::string, std::string, int> cmd;
    std::string pizzaName;
    std::string size;
    int nb = 0;
    int i = 0;

    infile.open(file);
    if (!infile.is_open()) {
        throw Error("This file can not be opened");
    }
    while (getline(infile, line)) {
        cmd = this->pars->parse(line);
        pizzaName = std::get<0>(cmd);
        std::cout << pizzaName;
        size = std::get<1>(cmd);
        std::cout << size;
        nb = std::get<2>(cmd);
        std::cout << nb;
        std::cout << "\n";
        while (i < nb) {
            this->addCommand(*new Command(pizzaName, size));
            i++;
        }
        i = 0;
    }
    std::cout << this->theCommands.size();
    infile.close();
}

Controleur::~Controleur() {

}