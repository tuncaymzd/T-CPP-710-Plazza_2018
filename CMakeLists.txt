cmake_minimum_required(VERSION 3.12)
project(Plazza)

set(CMAKE_CXX_STANDARD 17)

add_executable(Plazza main.cpp shared/includes/BasePizza.h shared/Margarita.cpp shared/includes/Margarita.h shared/Regina.cpp shared/includes/Regina.h shared/American.cpp shared/includes/American.h shared/Fantasia.cpp shared/includes/Fantasia.h)