#pragma once
#include "Command.hpp"
#include "Enums.hpp"

class CommandPlace : public Command
{
public:
    CommandPlace();
    CommandPlace(int xCoordinate, int yCoordinate, CardinalDirections direction);
    ~CommandPlace();
    int getXCoordinate()
    {
        return xCoordinate;
    };

    int getYCooridnate()
    {
        return yCoordinate;
    };

    CardinalDirections getCardinalDirections()
    {
        return cardinalDirection;
    };
private:
    int xCoordinate;
    int yCoordinate;
    CardinalDirections cardinalDirection;
};