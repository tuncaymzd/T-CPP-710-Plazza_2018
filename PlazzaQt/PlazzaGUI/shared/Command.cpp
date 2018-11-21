//
// Created by Tuncay Turkoglu on 05/11/2018.
//

#pragma once
#include "includes/Command.h"

Command::Command(std::string name, std::string size) {
    this->namePizza = name;
    this->size = size;
}

Command::~Command() {

}

const std::string &Command::getNamePizza() const {
    return namePizza;
}

const std::string &Command::getSize() const {
    return size;
}

