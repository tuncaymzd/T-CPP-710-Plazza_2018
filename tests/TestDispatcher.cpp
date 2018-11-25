#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Parser.cpp"
#include "../ParserConfig.cpp"
#include "../Controleur.cpp"
#include "../shared/Command.cpp"
#include "../shared/Kitchen.cpp"
#include "../shared/Cooker.cpp"
#include "../Dispatcher.cpp"

TEST_CASE( "init dispatcher", "[Dispatcher::Dispatcher]" ) {
    int argc = 8;
    char* argv[argc];
    argv[0] = "./a.out";
    argv[1] = "/Users/Tuncay/Desktop/propre_origin_master/T-CPP-710-Plazza_2018/commandes.txt";
    argv[2] = "-t";
    argv[3] = "100";
    argv[4] = "-k";
    argv[5] = "3";
    argv[6] = "--cooker";
    argv[7] = "2";

    Controleur *control = new Controleur(argc, argv);
    int numbersOfCookers = control->getNumbersOfCooker();
    int numbersOfKitchens = control->getNumbersOfKitchens();
    int baseTime = control->getBaseTime();
    std::queue<Command> listOfCommands;
    try {
        control->readFile(argv[1]);
        listOfCommands = control->getTheCommands();
        Dispatcher::initialize(numbersOfKitchens, numbersOfCookers, baseTime, listOfCommands);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    REQUIRE(Dispatcher::nbKitchens == 3);
    REQUIRE(Dispatcher::nbCookers == 2);
    REQUIRE(Dispatcher::basetime == 100);
    REQUIRE(Dispatcher::myPop().getNamePizza() == "Margarita");
    REQUIRE(Dispatcher::myPop().getNamePizza() == "Margarita");
    REQUIRE(Dispatcher::myPop().getNamePizza() == "Margarita");
    REQUIRE(Dispatcher::myPop().getNamePizza() == "Margarita");
    REQUIRE(Dispatcher::myPop().getNamePizza() == "Regina");
};

TEST_CASE("split the command","[Dispatcher::splitTheCommands]") {
    int argc = 8;
    char* argv[argc];
    argv[0] = "./a.out";
    argv[1] = "/Users/Tuncay/Desktop/propre_origin_master/T-CPP-710-Plazza_2018/commandes.txt";
    argv[2] = "-t";
    argv[3] = "100";
    argv[4] = "-k";
    argv[5] = "3";
    argv[6] = "--cooker";
    argv[7] = "2";

    Controleur *control = new Controleur(argc, argv);
    int numbersOfCookers = control->getNumbersOfCooker();
    int numbersOfKitchens = control->getNumbersOfKitchens();
    int baseTime = control->getBaseTime();
    std::queue<Command> listOfCommands;
    try {
        control->readFile(argv[1]);
        listOfCommands = control->getTheCommands();
        Dispatcher::initialize(numbersOfKitchens, numbersOfCookers, baseTime, listOfCommands);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    REQUIRE( Dispatcher::theCommandsSplit.size() == 0);
    Dispatcher::splitTheCommands();
    REQUIRE( Dispatcher::theCommandsSplit.size() == 3);
}