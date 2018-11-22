cmake_minimum_required(VERSION 3.12)
project(Plazza)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Plazza
        main.cpp
        include/ParserConfig.h
        include/Parser.hpp
        include/Error.h
        ParserConfig.cpp
        Parser.cpp
        Error.cpp
        shared/includes/Command.h
        shared/Command.cpp
        include/Controleur.hpp
        Controleur.cpp
        shared/includes/BasePizza.h
        shared/Margarita.cpp
        shared/includes/Margarita.h
        shared/Regina.cpp
        shared/includes/Regina.h
        shared/American.cpp
        shared/includes/American.h
        shared/Fantasia.cpp
        shared/includes/Fantasia.h
        shared/Timer.cpp
        shared/includes/Timer.h
        shared/includes/ITimerCompletedListener.h
        shared/includes/Enums.h
        shared/TimerCompletedListener.cpp
        shared/includes/TimerCompletedListener.h
        shared/includes/Delegates.h
        shared/includes/ICook.h
        shared/Cooker.cpp
        shared/includes/Kitchen.h
        shared/Kitchen.cpp
        shared/includes/Cooker.h
        Dispatcher.cpp
        include/Dispatcher.h)