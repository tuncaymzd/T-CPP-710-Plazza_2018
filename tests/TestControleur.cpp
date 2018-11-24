#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Parser.cpp"
#include "../ParserConfig.cpp"
#include "../Controleur.cpp"
#include "../shared/Command.cpp"

TEST_CASE( "init controleur", "[Controleur::Controleur]" ) {
    int argc = 8;
    char* argv[argc];
    argv[0] = "./a.out";
    argv[1] = "test.txt";
    argv[2] = "-t";
    argv[3] = "100";
    argv[4] = "-k";
    argv[5] = "3";
    argv[6] = "--cooker";
    argv[7] = "2";

    Controleur *control = new Controleur(argc, argv);
    REQUIRE( control->getBaseTime() == 100);
    REQUIRE( control->getNumbersOfCooker() == 2);
    REQUIRE( control->getNumbersOfKitchens() == 3);
};

TEST_CASE( "readfile controleur", "[Controleur::readFile]" ) {
    int argc = 2;
    char* argv[argc];
    argv[0] = "./a.out";
    argv[1] = "/Users/Tuncay/Desktop/propre_origin_master/T-CPP-710-Plazza_2018/commandes.txt";

    Controleur *control = new Controleur(argc, argv);
    REQUIRE( control->getTheCommands().empty() == true);
    control->readFile(argv[1]);
    REQUIRE( control->getTheCommands().empty() == false);
    REQUIRE( control->getFirstCommand().getNamePizza() == "Margarita");
    REQUIRE( control->getFirstCommand().getSize() == "M");
};