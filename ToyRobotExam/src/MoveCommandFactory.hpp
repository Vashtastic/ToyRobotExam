#pragma once

#include "Command.hpp"
#include "CommandFactory.hpp"
#include "CommandMove.hpp"
#include <string>

class MoveCommandFactory : public CommandFactory
{
public:
    CommandMove* createCommandFromString(std::string& command)
    {
        CommandMove* ptr = new CommandMove;
        ptr->setName(command);
        return ptr;
    }
};
