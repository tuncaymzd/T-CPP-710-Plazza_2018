#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Parser.hpp"

TEST_CASE( "verify_isValidInt", "[Parser:isValidInt]" ) {
    Parser *pars = new Parser();
    REQUIRE( pars->isValidInt("5") == 5);
    REQUIRE_THROWS(pars->isValidInt("245"));
    REQUIRE_THROWS(pars->isValidInt("-245"));
    REQUIRE_THROWS(pars->isValidInt("125.5"));
    REQUIRE_THROWS_AS(pars->isValidInt(""), std::invalid_argument);
    REQUIRE_THROWS(pars->isValidInt("coucou"));
    REQUIRE_THROWS(pars->isValidInt("123coucou"));
}


TEST_CASE( "verify_toLowerCase", "[Parser::toLowerCase]" ) {
    Parser *pars = new Parser();
    REQUIRE(pars->toLowerCase("BOB") == "bob");
    REQUIRE(pars->toLowerCase("Lap1") == "lap1");
    REQUIRE(pars->toLowerCase("") == "");
    REQUIRE(pars->toLowerCase("abab") == "abab");
    REQUIRE(pars->toLowerCase("1212") == "1212");
    REQUIRE(pars->toLowerCase("é&''") == "é&''");
}

TEST_CASE( "verify_compare", "[Parser::compare]" ) {
    Parser *pars = new Parser();
    std::vector<std::string> tmp;
    tmp.push_back("Margarita");
    tmp.push_back("Regina");
    tmp.push_back("American");
    tmp.push_back("Fantasia");
    REQUIRE(pars->compare("MARGARITA", tmp) == "Margarita");
    REQUIRE(pars->compare("margarita", tmp) == "Margarita");
    REQUIRE_THROWS(pars->compare("abab", tmp));
    REQUIRE_THROWS(pars->compare("", tmp));
}

TEST_CASE( "verify_explode", "[Parser::explode]" ) {
    Parser *pars = new Parser();
    std::vector<std::string> tmp;
    tmp.push_back("Margarita");
    tmp.push_back("XL");
    tmp.push_back("1");
    REQUIRE(pars->explode("Margarita XL 1", ' ') == tmp);
    std::vector<std::string> tmp2;
    tmp2.push_back("MARGARITAxl1");
    REQUIRE(pars->explode("MARGARITAxl1", ' ') == tmp2);
    REQUIRE_THROWS(pars->explode("", ' '));
    std::vector<std::string> tmp3;
    tmp3.push_back("MARGARITA");
    tmp3.push_back("xl1");
    REQUIRE(pars->explode("MARGARITA  xl1", ' ') == tmp3);
}

TEST_CASE( "verify_parse", "[Parser::parse]" ) {
    Parser *pars = new Parser();
    auto tmp = std::make_tuple("Margarita", "M", 1);
    REQUIRE(pars->parse("Margarita") == tmp);
    REQUIRE(pars->parse("Margarita M") == tmp);
    REQUIRE(pars->parse("Margarita 1") == tmp);
    REQUIRE_THROWS(pars->parse("Margaritamfmf"));
}

