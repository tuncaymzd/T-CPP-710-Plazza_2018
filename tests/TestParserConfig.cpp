s#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../ParserConfig.cpp"

TEST_CASE( "isOption true", "[ParserConfig::isOption]" ) {
    ParserConfig *pars = new ParserConfig();
    REQUIRE( pars->isOption("-t") == 1 );
    REQUIRE( pars->isOption("--time") == 1);
    REQUIRE( pars->isOption("-c") == 1);
    REQUIRE( pars->isOption("--cooker") == 1);
    REQUIRE( pars->isOption("-k") == 1);
    REQUIRE( pars->isOption("--kitchen") == 1);
    REQUIRE( pars->isOption("-time") == 0);
    REQUIRE( pars->isOption("") == 0);
}

TEST_CASE( "verify_getOptions", "[ParserConfig::getOptions()]" ) {
    ParserConfig *pars = new ParserConfig();
    std::vector<std::string> res;
    res.push_back("-t");
    res.push_back("--time");
    res.push_back("-k");
    res.push_back("--kitchen");
    res.push_back("-c");
    res.push_back("--cooker");
    REQUIRE( pars->getOptions() == res);
}

TEST_CASE( "verify_indexOptions", "[ParserConfig::indexOptions]" ) {
    ParserConfig *pars = new ParserConfig();
    REQUIRE( pars->indexOptions("-t") == 0);
    REQUIRE( pars->indexOptions("-c") == 4);
    REQUIRE_THROWS(pars->indexOptions("-cki"));
}

TEST_CASE( "verify_removeOptions", "[ParserConfig::removeOptions]" ) {
    ParserConfig *pars = new ParserConfig();
    std::vector<std::string> res;
    res.push_back("-t");
    res.push_back("--time");
    res.push_back("-k");
    res.push_back("--kitchen");
    res.push_back("-c");
    pars->removeOptions("--cooker");
    REQUIRE(pars->getOptions() == res);
}