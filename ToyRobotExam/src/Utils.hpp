#pragma once

#include "Enums.hpp"
#include <string>
#include <unordered_map>
#include "CommandFactory.hpp"
#include "PlaceCommandFactory.hpp"
#include "MoveCommandFactory.hpp"
#include "LeftCommandFactory.hpp"
#include "RigthCommandFactory.hpp"
#include "ReportCommandFactory.hpp"

static std::unordered_map<std::string, Commands> stringToCommandEnumMapping =
{
    {"PLACE", Commands::PLACE},
    {"MOVE", Commands::MOVE},
    {"LEFT", Commands::LEFT},
    {"RIGHT", Commands::RIGHT},
    {"REPORT", Commands::REPORT}
};


static std::unordered_map<std::string, CardinalDirections> stringToCardinalDirectionMapping =
{
    {"NORTH", CardinalDirections::NORTH},
    {"SOUTH", CardinalDirections::SOUTH},
    {"EAST", CardinalDirections::EAST},
    {"WEST", CardinalDirections::WEST}
};

static std::unordered_map<CardinalDirections, std::string> cardinalDirectionToStringMapping =
{
    {CardinalDirections::NORTH, "NORTH"},
    {CardinalDirections::SOUTH, "SOUTH"},
    {CardinalDirections::EAST, "EAST"},
    {CardinalDirections::WEST, "WEST"}
};

struct Map
{
    int width;
    int length;
};

struct RobotPosition
{
    int xCoordinate;
    int yCoordinate;
    CardinalDirections direction;
};

static CardinalDirections arr[4] = {CardinalDirections::NORTH,CardinalDirections::WEST,CardinalDirections::SOUTH,CardinalDirections::EAST};