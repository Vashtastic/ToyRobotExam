#pragma once

#include "Utils.hpp"
#include "Enums.hpp"
#include <memory>
#include "CommandPlace.hpp"

class Robot
{
public:
    Robot();
    Robot(Map map);
    ~Robot();
    void doCommand(Command* command);
    RobotPosition getRobotPosition()
    {
        return currentPosition;
    }

    Map getMap()
    {
        return map;
    }
private:
    RobotPosition currentPosition;
    Map map;
    bool isRobotOnTable;
    bool willRobotBeOutOfBounds(RobotPosition positionToGoTo);
    void doPlaceCommand(std::unique_ptr<CommandPlace>& sptr);
    void doMoveCommand();
    void turnRobotRight();
    void turnRobotLeft();
};