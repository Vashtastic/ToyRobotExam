#include "PlaceCommandFactory.hpp"
#include <vector>
#include <string>
#include <sstream>
#include "Utils.hpp"
#include "CommandPlace.hpp"

#define PARAMETER_TOKEN_DELIMETER  ','
#define COMMAND_PARAMTOKENS_DELIMETER ' '

PlaceCommandFactory::~PlaceCommandFactory()
{

};

CommandPlace* PlaceCommandFactory::createCommandFromString(std::string& command)
{
    constexpr auto parameterTokenOffset = 1;

    std::stringstream commandTokenizer(command);
    std::vector<std::string> commandTokens{};
    std::vector<std::string> parameterTokens{};

    std::string temp;
    while(std::getline(commandTokenizer, temp, COMMAND_PARAMTOKENS_DELIMETER))
    {
        commandTokens.push_back(temp);
    }

    //parse tokens
    if(commandTokens.size() > 1)
    {
        std::stringstream parameterTokenizer(commandTokens[parameterTokenOffset]);
        while(std::getline(parameterTokenizer, temp, PARAMETER_TOKEN_DELIMETER))
        {
            parameterTokens.push_back(temp);
        }
    }
    CommandPlace* ptr = nullptr;
    try
    {
        ptr = createCommand(std::stoi(parameterTokens.at(0)), std::stoi(parameterTokens.at(1)),
                            stringToCardinalDirectionMapping.at(parameterTokens.at(2)));
        ptr->setName(command);
    }catch(const std::exception& exc)
    {
        throw exc;
    }

    return ptr;
}

inline CommandPlace* PlaceCommandFactory::createCommand(int xCoord, int yCoord, CardinalDirections direction)
{
    CommandPlace* ptr = new CommandPlace(xCoord, yCoord, direction);
    return ptr;
}