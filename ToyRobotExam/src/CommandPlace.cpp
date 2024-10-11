#include "CommandPlace.hpp"

CommandPlace::CommandPlace()
{}

CommandPlace::CommandPlace(int xCoordinate, int yCoordinate, CardinalDirections direction)
                            :xCoordinate(xCoordinate),
                             yCoordinate(yCoordinate),
                             cardinalDirection(direction)
{

};

CommandPlace::~CommandPlace()
{

};