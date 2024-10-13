#include "CommandReader.hpp"
#include "Command.hpp"
#include <exception>
#include <sstream>
#include "Utils.hpp"

#define PARAMETER_TOKEN_DELIMETER  ','
#define COMMAND_PARAMTOKENS_DELIMETER ' '

CommandReader::CommandReader()
{}

CommandReader::~CommandReader()
{}

void CommandReader::parseCommandFromStandardOutput(std::string& currentCommand)
{
    std::stringstream commandTokenizer(currentCommand);
    std::string commandStr {};
    std::getline(commandTokenizer, commandStr, COMMAND_PARAMTOKENS_DELIMETER);
    currentCommand = commandStr;
}

Command* CommandReader::createCommand()
{
    Command* t = nullptr;
    try
    {
        Commands command = stringToCommandEnumMapping.at(currentCommand);
        t = commandToFactoryMapping[command]->createCommandFromString(currentCommand);
    }
    catch(std::exception& exc)
    {
        return nullptr;
    }

    return t;
}