// ToyRobotExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <memory>
#include <exception>
#include "Utils.hpp"
#include "Command.hpp"
#include "CommandPlace.hpp"
#include "Enums.hpp"
#include "Robot.hpp"

#define PARAMETER_TOKEN_DELIMETER  ','
#define COMMAND_PARAMTOKENS_DELIMETER ' '
#define MAP_LENGTH 5
#define MAP_WIDTH 5

int main()
{
    initializeFactories();

    Robot rob({MAP_LENGTH,MAP_WIDTH});
    while (true)
    {
        std::cout << "Toy Robot Command Interface\n" << std::endl;
        std::string currentCommand{};
        while (std::getline(std::cin, currentCommand,'\n'))
        {
            Command* t = nullptr;
            std::stringstream commandTokenizer(currentCommand);
            std::string commandStr {};
            std::getline(commandTokenizer, commandStr, COMMAND_PARAMTOKENS_DELIMETER);

            try
            {
                Commands command = stringToCommandEnumMapping.at(commandStr);
                t = commandToFactoryMapping[command]->createCommandFromString(currentCommand);

                rob.doCommand(t);
            }
            catch(...)
            {
                std::cout << "INVALID COMMAND" << std::endl;
                continue;
            }
        }
    }
}