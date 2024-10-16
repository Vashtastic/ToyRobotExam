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
#include "CommandHandler.hpp"

#define MAP_LENGTH 5
#define MAP_WIDTH 5


int main()
{
    Robot rob({MAP_LENGTH,MAP_WIDTH});
    while (true)
    {
        std::cout << "Toy Robot Command Interface\n" << std::endl;
        std::string currentCommand{};
        CommandHandler commandReader{};
        while (std::getline(std::cin, currentCommand,'\n'))
        {
            Command* t = nullptr;
            commandReader.storeCommandToken(currentCommand);
            try
            {
                t = commandReader.createCommand();
                rob.doCommand(t);
            }
            catch(...)
            {
                std::cout << "INVALID COMMAND" << std::endl;
            }

        }
    }
}