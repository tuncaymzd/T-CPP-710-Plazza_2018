#include <iostream>
#include "include/Parser.hpp"

int main(int argc, char* argv[])
{
    Parser *pars = new Parser();
    std::cout << "\n";
    try {
        pars->parse("Margarita L 4");
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
