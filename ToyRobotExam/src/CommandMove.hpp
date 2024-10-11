#pragma once

#include "Command.hpp"
#include "CommandFactory.hpp"
#include <string>

class CommandMove : public Command
{
public:
    CommandMove(){};
    ~CommandMove(){};
};