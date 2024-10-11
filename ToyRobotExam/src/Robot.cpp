#include "Robot.hpp"

Robot::Robot() {};

Robot::Robot(Map map)
{
    this->map = map;
    currentPosition.xCoordinate = 0;
    currentPosition.yCoordinate = 0;
    currentPosition.direction = CardinalDirections::NOT_ON_BOARD;
};

Robot::~Robot() {};

void Robot::doCommand(Command* command)
{
    Commands com = stringToCommandEnumMapping[command->name];
    if(currentPosition.direction != CardinalDirections::NOT_ON_BOARD)
    {
        switch(com)
        {
            case Commands::PLACE:
            {
                std::unique_ptr<CommandPlace> sptr((CommandPlace*)command);
                doPlaceCommand(sptr);
            }
            break;
            case Commands::MOVE:
            {
                std::unique_ptr<CommandMove> sptr((CommandMove*)command);
                doMoveCommand();
            }
            break;
            case Commands::LEFT:
            {
                std::unique_ptr<CommandLeft> sptr((CommandLeft*)command);
                turnRobotLeft();
            }
            break;
            case Commands::RIGHT:
            {
                std::unique_ptr<CommandRight> sptr((CommandRight*)command);
                turnRobotRight();
            }
            break;
            case Commands::REPORT:
            {
                std::unique_ptr<CommandReport> sptr((CommandReport*)command);
                std::cout << "Output: " << currentPosition.xCoordinate << "," <<
                    currentPosition.yCoordinate << "," << cardinalDirectionToStringMapping.at(currentPosition.direction) << std::endl;
            }
            break;
            default:
            {
                std::cout << "COMMAND NOT SUPPORTED" << std::endl;
            }
            break;
        }
    }
    else
    {
        if(com == Commands::PLACE)
        {
            std::unique_ptr<CommandPlace> sptr((CommandPlace*)command);
            doPlaceCommand(sptr);
        }
        else
        {
            std::cout << "INPUT PROPER PLACE COMMAND FIRST" << std::endl;
            delete command;
        }
    }
}

bool Robot::willRobotBeOutOfBounds(RobotPosition positionToGoTo)
    {
        if(positionToGoTo.yCoordinate > map.length - 1 || positionToGoTo.xCoordinate > map.width - 1
           || positionToGoTo.yCoordinate < 0 || positionToGoTo.xCoordinate < 0)
        {
            std::cout << "INVALID COMMAND ROBOT WILL BE OUT OF BOUNDS" << std::endl;
            return true;
        }
        return false;
    }

void Robot::doPlaceCommand(std::unique_ptr<CommandPlace>& sptr)
{
    if(!willRobotBeOutOfBounds({sptr->getXCoordinate(),sptr->getYCooridnate(),sptr->getCardinalDirections()}))
    {
        currentPosition.xCoordinate = sptr->getXCoordinate();
        currentPosition.yCoordinate = sptr->getYCooridnate();
        currentPosition.direction = sptr->getCardinalDirections();
    }
}

void Robot::doMoveCommand()
{
    switch(currentPosition.direction)
    {
        case CardinalDirections::NORTH:
        {
            RobotPosition newPosition = currentPosition;
            ++(newPosition.yCoordinate);
            if(!willRobotBeOutOfBounds(newPosition))
            {
                currentPosition = newPosition;
            }
        }
        break;
        case CardinalDirections::SOUTH:
        {
            RobotPosition newPosition = currentPosition;
            --(newPosition.yCoordinate);
            if(!willRobotBeOutOfBounds(newPosition))
            {
                currentPosition = newPosition;
            }
        }
        break;
        case CardinalDirections::EAST:
        {
            RobotPosition newPosition = currentPosition;
            ++(newPosition.xCoordinate);
            if(!willRobotBeOutOfBounds(newPosition))
            {
                currentPosition = newPosition;
            }
        }
        break;
        case CardinalDirections::WEST:
        {
            RobotPosition newPosition = currentPosition;
            --(newPosition.xCoordinate);
            if(!willRobotBeOutOfBounds(newPosition))
            {
                currentPosition = newPosition;
            }
        }
        break;
        default:
        {

        }
        break;
    };
}

void Robot::turnRobotRight()
{
    switch(currentPosition.direction)
    {
        case CardinalDirections::NORTH:
        {
            currentPosition.direction = CardinalDirections::EAST;
        }
        break;
        case CardinalDirections::EAST:
        {
            currentPosition.direction = CardinalDirections::SOUTH;
        }
        break;
        case CardinalDirections::SOUTH:
        {
            currentPosition.direction = CardinalDirections::WEST;
        }
        break;
        case CardinalDirections::WEST:
        {
            currentPosition.direction = CardinalDirections::NORTH;
        }
        break;
        default:
        {

        }
        break;
    };
}

void Robot::turnRobotLeft()
{
    switch(currentPosition.direction)
    {
        case CardinalDirections::NORTH:
        {
            currentPosition.direction = CardinalDirections::WEST;
        }
        break;
        case CardinalDirections::WEST:
        {
            currentPosition.direction = CardinalDirections::SOUTH;
        }
        break;
        case CardinalDirections::SOUTH:
        {
            currentPosition.direction = CardinalDirections::EAST;
        }
        break;
        case CardinalDirections::EAST:
        {
            currentPosition.direction = CardinalDirections::NORTH;
        }
        break;
        default:
        {

        }
        break;
    };
}