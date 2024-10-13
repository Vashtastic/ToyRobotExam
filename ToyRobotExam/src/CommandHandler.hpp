#pragma once
#include <string>
#include <unordered_map>
#include "Command.hpp"
#include "CommandFactory.hpp"

class CommandHandler
{
public:
    CommandHandler();
    ~CommandHandler();
    void storeCommandToken(std::string& currentCommand);
    Command* createCommand(void);
    std::string& getCurrentCommand();
private:
    std::unordered_map<Commands, std::unique_ptr<CommandFactory>> commandToFactoryMapping;
    std::string storedCommand;
    std::string input;
};