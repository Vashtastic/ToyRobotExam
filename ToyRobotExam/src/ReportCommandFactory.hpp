#pragma once

#include "Command.hpp"
#include "CommandFactory.hpp"
#include "CommandReport.hpp"
#include <string>

class ReportCommandFactory : public CommandFactory
{
public:
    CommandReport* createCommandFromString(std::string& command)
    {
        CommandReport* ptr = new CommandReport;
        ptr->setName(command);
        return ptr;
    }
};
