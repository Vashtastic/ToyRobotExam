#pragma once

#include "Command.hpp"
#include "CommandFactory.hpp"
#include "CommandRight.hpp"
#include <string>

class RightCommandFactory : public CommandFactory
{
public:
    CommandRight* createCommandFromString(std::string& command)
    {
        CommandRight* ptr = new CommandRight;
        ptr->setName(command);
        return ptr;
    }
};
