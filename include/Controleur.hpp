/*
** EPITECH PROJECT, 2018
** Controleur.hpp
** File description:
** this is controleur
*/

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

    //! Constructor
    /*!
      \param argc represent number of argument
      \param argv is array of string and he contain usefull element
    */
    Controleur(int argc, char* argv[]);

    //! Constructor
    /*!
      \param argc represent number of argument
      \param argv is array of string and he contain usefull element
      \param notif notify step of program
    */
    Controleur(int argc, char* argv[], notifierEventHandler notif);
    ~Controleur();

    //! read file and create the file of commands
    /*!
      \param file represent name of file, this file contains one command per line
      \return void
    */
    void readFile(std::string file);

    //! add command in file of commands
    /*!
      \param c represent command to add
      \return void
    */
    void addCommand(Command c);

    //! delete the first command
    /*!
      \param void
      \return void
    */
    void deleteCommand();

    //! verify if file of commands is empty
    /*!
      \param void
      \return true if file of commands is empty, else return false
    */
    bool theCommandsIsEmpty();

    //! get the file of commands
    /*!
      \param void
      \return queue<Command>, represent file of commands
    */
    const std::queue<Command> &getTheCommands() const;

    //! get base time initialized in configuration
    /*!
      \param void
      \return int, represent base time (ms)
    */
    int getBaseTime() const;

    //! get numbers of kitchens initialized in configuration
    /*!
      \param void
      \return int, represent numbers of kitchens
    */
    int getNumbersOfKitchens() const;

    //! get numbers of cooker in one kitchen
    /*!
      \param void
      \return int, represent numbers of cooker in one kitchen
    */
    int getNumbersOfCooker() const;

    //! modify the base Time
    /*!
      \param int, baseTime represent a new base time (ms)
      \return void
    */
    void setBaseTime(int baseTime);

    //! modify the numbers of kitchens
    /*!
      \param int, numbersOfKitchens represent a new numbers of kitchens
      \return void
    */
    void setNumbersOfKitchens(int numbersOfKitchens);

    //! modify the number of cooker in one kitchen
    /*!
      \param int, numbersOfCooker represent a new number of cooker per kitchen
      \return void
    */
    void setNumbersOfCooker(int numbersOfCooker);

    //! return first command of file of commands
    /*!
      \param void
      \return Command, represent first command of file
    */
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