#pragma once

#include "CommandFactory.hpp"
#include "CommandPlace.hpp"

class PlaceCommandFactory : public CommandFactory
{
public:
    ~PlaceCommandFactory();
    CommandPlace* createCommandFromString(std::string& command);
private:
    inline CommandPlace* createCommand(int xCoord, int yCoord, CardinalDirections direction);
};