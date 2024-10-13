#include "CommandHandler.hpp"
#include "CommandCreationException.hpp"
#include "Command.hpp"
#include "Utils.hpp"
#include <exception>
#include <sstream>

#define COMMAND_PARAMTOKENS_DELIMETER ' '
CommandHandler::CommandHandler()
{
    if(commandToFactoryMapping.size() == 0)
    {
        commandToFactoryMapping.insert({Commands::PLACE, std::make_unique<PlaceCommandFactory>()});
        commandToFactoryMapping.insert({Commands::MOVE, std::make_unique<MoveCommandFactory>()});
        commandToFactoryMapping.insert({Commands::LEFT, std::make_unique<LeftCommandFactory>()});
        commandToFactoryMapping.insert({Commands::RIGHT, std::make_unique<RightCommandFactory>()});
        commandToFactoryMapping.insert({Commands::REPORT, std::make_unique<ReportCommandFactory>()});
    }
}

CommandHandler::~CommandHandler()
{}

void CommandHandler::storeCommandToken(std::string& currentCommand)
{
    std::stringstream commandTokenizer(currentCommand);
    std::string commandStr {};
    std::getline(commandTokenizer, commandStr, COMMAND_PARAMTOKENS_DELIMETER);
    storedCommand = commandStr;
    input = currentCommand;
}

std::string& CommandHandler::getCurrentCommand()
{
    return storedCommand;
}

Command* CommandHandler::createCommand(void)
{
    Command* t = nullptr;
    try
    {
        Commands command = stringToCommandEnumMapping.at(storedCommand);
        t = (commandToFactoryMapping.at(command))->createCommandFromString(input);
    }
    catch(...)
    {
        throw CommandCreationException();
    }

    return t;
}