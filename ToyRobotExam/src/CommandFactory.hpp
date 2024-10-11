#pragma once

#include <string>
#include "Command.hpp"
#include "Enums.hpp"

class CommandFactory
{
public:
    CommandFactory() {};
    virtual ~CommandFactory() {};

    //TODO maybe use unique ptrs for this
    virtual Command* createCommandFromString(std::string&) = 0;
};
