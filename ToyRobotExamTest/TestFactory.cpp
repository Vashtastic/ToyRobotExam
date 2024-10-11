#include "pch.h"
#include "Robot.hpp"
#include "Utils.hpp"
#include "Command.hpp"
#include "CommandPlace.hpp"
#include "Enums.hpp"
#include "CommandMove.hpp"
#include "CommandFactory.hpp"
#include "PlaceCommandFactory.hpp"
#include "MoveCommandFactory.hpp"
#include "LeftCommandFactory.hpp"
#include "RigthCommandFactory.hpp"
#include "ReportCommandFactory.hpp"
#include <string>
#include <vector>

TEST(TestFactory, createCommandObjects)
{
	std::vector<std::string> commands{"PLACE 0,0,NORTH", "MOVE", "LEFT", "RIGHT", "REPORT"};
	PlaceCommandFactory placeCommandfactory;
	MoveCommandFactory  moveCommandFactory;
	LeftCommandFactory leftCommandFactory;
	RightCommandFactory rightCommandFactory;
	ReportCommandFactory reportCommandFactory;

	std::unique_ptr<CommandPlace> placePtr(placeCommandfactory.createCommandFromString(commands[0]));
	std::unique_ptr<CommandMove> movPtr(moveCommandFactory.createCommandFromString(commands[1]));

	std::unique_ptr<CommandLeft> leftPtr(leftCommandFactory.createCommandFromString(commands[2]));
	std::unique_ptr<CommandRight> rightPtr(rightCommandFactory.createCommandFromString(commands[3]));
	std::unique_ptr<CommandReport> reportPtr(reportCommandFactory.createCommandFromString(commands[4]));

	EXPECT_EQ(placePtr->getCardinalDirections(), CardinalDirections::NORTH);
	EXPECT_STREQ(movPtr->name.c_str(), "MOVE");
	EXPECT_STREQ(leftPtr->name.c_str(), "LEFT");
	EXPECT_STREQ(rightPtr->name.c_str(), "RIGHT");
	EXPECT_STREQ(reportPtr->name.c_str(), "REPORT");
}