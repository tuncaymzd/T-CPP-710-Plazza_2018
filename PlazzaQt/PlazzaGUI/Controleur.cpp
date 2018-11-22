//
// Created by Tuncay Turkoglu on 06/11/2018.
//
#pragma once
#include "include/Controleur.hpp"

Controleur::Controleur()
{
    this->baseTime = 0;
    this->numbersOfKitchens = 0;
    this->numbersOfCooker = 0;
}

Controleur::Controleur(int argc, char* argv[]) {
    this->parserConf = new ParserConfig();
    //this->pars = new Parser();
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
        cmd = this->pars.parse(line);
        pizzaName = std::get<0>(cmd);
        size = std::get<1>(cmd);
        nb = std::get<2>(cmd);
        while (i < nb) {
            this->addCommand(*new Command(pizzaName, size));
            i++;
        }
        i = 0;
    }
    infile.close();
}

Controleur::~Controleur() {

}

Controleur::Controleur(int argc, char **argv, notifierEventHandler notif) {
    this->parserConf = new ParserConfig();
    //this->pars = new Parser();
    this->parserConf->initParser(argc, argv);
    this->baseTime = this->parserConf->getBaseTime();
    this->numbersOfKitchens = this->parserConf->getNumbersOfKitchens();
    this->numbersOfCooker = this->parserConf->getNumbersOfCookers();
    this->onNotify = notif;
}

const std::queue<Command> &Controleur::getTheCommands() const {
    return theCommands;
}

int Controleur::getBaseTime() const {
    return baseTime;
}

int Controleur::getNumbersOfKitchens() const {
    return numbersOfKitchens;
}

int Controleur::getNumbersOfCooker() const {
    return numbersOfCooker;
}

Command Controleur::getFirstCommand() const {
    return theCommands.front();
}

void Controleur::setBaseTime(int baseTime) {
    Controleur::baseTime = baseTime;
}

void Controleur::setNumbersOfKitchens(int numbersOfKitchens) {
    Controleur::numbersOfKitchens = numbersOfKitchens;
}

void Controleur::setNumbersOfCooker(int numbersOfCooker) {
    Controleur::numbersOfCooker = numbersOfCooker;
}
