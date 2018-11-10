//
// Created by damien on 05/11/18.
//

#ifndef PLAZZA_BASEPIZZA_H
#define PLAZZA_BASEPIZZA_H

#include <string>
#include "string.h"
using std::string;

class BasePizza {

    string size;
    long cookingTime;
    string name;

public:
    BasePizza(string size, long cookingTime, float t, string name) : size(size), name(name),
        cookingTime(static_cast<long>(cookingTime * t)){};

    /// Getter
    /// \return The size of the pizza
    virtual const string &getSize() const {
        return size;
    }

    /// Getter
    /// \return The Cooking Time for the pizza
    virtual long getCookingTime() const {
        return cookingTime;
    }

    /// Getter
    /// \return The name of the pizza
    virtual const string &getName() const {
        return name;
    }
};


#endif //PLAZZA_BASEPIZZA_H
