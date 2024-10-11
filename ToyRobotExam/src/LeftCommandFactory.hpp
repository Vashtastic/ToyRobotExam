#pragma once

#include "Command.hpp"
#include "CommandFactory.hpp"
#include "CommandLeft.hpp"
#include <string>

class LeftCommandFactory : public CommandFactory
{
public:
    CommandLeft* createCommandFromString(std::string& command)
    {
        CommandLeft* ptr = new CommandLeft;
        ptr->setName(command);
        return ptr;
    }
};
