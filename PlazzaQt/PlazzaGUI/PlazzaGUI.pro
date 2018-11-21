#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T12:30:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlazzaGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Error.cpp \
    Dispatcher.cpp \
    Controleur.cpp \
    Parser.cpp \
    ParserConfig.cpp \
    shared/American.cpp \
    shared/Command.cpp \
    shared/Cooker.cpp \
    shared/Fantasia.cpp \
    shared/Kitchen.cpp \
    shared/Margarita.cpp \
    shared/Regina.cpp \
    shared/Timer.cpp \
    shared/TimerCompletedListener.cpp \

HEADERS += \
        mainwindow.h \
    include/Controleur.hpp \
    include/Dispatcher.h \
    include/Error.h \
    include/Parser.hpp \
    include/ParserConfig.h \
    mainwindow.h \
    include/Controleur.hpp \
    include/Dispatcher.h \
    include/Error.h \
    include/Parser.hpp \
    include/ParserConfig.h \
    shared/includes/American.h \
    shared/includes/BasePizza.h \
    shared/includes/Command.h \
    shared/includes/Cooker.h \
    shared/includes/Delegates.h \
    shared/includes/Enums.h \
    shared/includes/Fantasia.h \
    shared/includes/ICook.h \
    shared/includes/ITimerCompletedListener.h \
    shared/includes/Kitchen.h \
    shared/includes/Margarita.h \
    shared/includes/Regina.h \
    shared/includes/Timer.h \
    shared/includes/TimerCompletedListener.h \
    mainwindow.h \
    include/Controleur.hpp \
    include/Dispatcher.h \
    include/Error.h \
    include/Parser.hpp \
    include/ParserConfig.h \
    shared/includes/American.h \
    shared/includes/BasePizza.h \
    shared/includes/Command.h \
    shared/includes/Cooker.h \
    shared/includes/Delegates.h \
    shared/includes/Enums.h \
    shared/includes/Fantasia.h \
    shared/includes/ICook.h \
    shared/includes/ITimerCompletedListener.h \
    shared/includes/Kitchen.h \
    shared/includes/Margarita.h \
    shared/includes/Regina.h \
    shared/includes/Timer.h \
    shared/includes/TimerCompletedListener.h \
    mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
