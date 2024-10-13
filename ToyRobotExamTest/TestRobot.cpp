#include "pch.h"
#include "Robot.hpp"
#include "Utils.hpp"
#include "Command.hpp"
#include "CommandPlace.hpp"
#include "Enums.hpp"
#include "CommandMove.hpp"

static const Map map{ 5,5 };

class TestRobotFixture : public ::testing::Test
{
protected:
	TestRobotFixture(): myRobot(map){

	}

	void doPlaceCommand(RobotPosition position)
	{
		Command* ptr = new CommandPlace(position.xCoordinate, position.yCoordinate, position.direction);
		ptr->setName("PLACE");
		myRobot.doCommand(ptr);
	}
	Robot myRobot;
};

TEST_F(TestRobotFixture, TestRobotInit)
{
	constexpr int EXPECTED_LENGTH= 5;
	constexpr int EXPECTED_WIDTH = 5;
	constexpr int EXPECTED_X_COORD = 0;
	constexpr int EXPECTED_Y_COORD = 0;

	RobotPosition currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, CardinalDirections::NOT_ON_BOARD);
}

TEST_F(TestRobotFixture, TestPlaceCommand)
{
	constexpr int EXPECTED_X_COORD = 0;
	constexpr int EXPECTED_Y_COORD = 0;
	RobotPosition position{ 0, 0, CardinalDirections::NORTH };
	doPlaceCommand(position);
	RobotPosition currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, CardinalDirections::NORTH);
}

TEST_F(TestRobotFixture, TestPlaceCommandOutOfBounds)
{
	constexpr int EXPECTED_X_COORD = 0;
	constexpr int EXPECTED_Y_COORD = 0;
	constexpr CardinalDirections EXPECTED_DIRECTION = CardinalDirections::NOT_ON_BOARD;

	RobotPosition position{ 0, 5, CardinalDirections::NORTH };
	doPlaceCommand(position);
	RobotPosition currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, EXPECTED_DIRECTION);

	RobotPosition position2{ -1, 4, CardinalDirections::NORTH };
	doPlaceCommand(position2);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, EXPECTED_DIRECTION);

	RobotPosition position3{ 5, 0, CardinalDirections::NORTH };
	doPlaceCommand(position3);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, EXPECTED_DIRECTION);

	RobotPosition position4{ 0, -1, CardinalDirections::NORTH };
	doPlaceCommand(position4);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction, EXPECTED_DIRECTION);
}

TEST_F(TestRobotFixture, TestLeftCommand)
{
	RobotPosition position{ 0, 0, CardinalDirections::NORTH };
	doPlaceCommand(position);
	RobotPosition currentPosition = myRobot.getRobotPosition();

	EXPECT_EQ(currentPosition.direction, CardinalDirections::NORTH);

	Command* leftCom = new CommandLeft();
	leftCom->setName("LEFT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::WEST);

	leftCom = new CommandLeft();
	leftCom->setName("LEFT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::SOUTH);

	leftCom = new CommandLeft();
	leftCom->setName("LEFT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::EAST);

	leftCom = new CommandLeft();
	leftCom->setName("LEFT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::NORTH);
}

TEST_F(TestRobotFixture, TestRightCommand)
{
	RobotPosition position{ 0, 0, CardinalDirections::NORTH };
	doPlaceCommand(position);
	RobotPosition currentPosition = myRobot.getRobotPosition();

	EXPECT_EQ(currentPosition.direction, CardinalDirections::NORTH);

	Command* leftCom = new CommandLeft();
	leftCom->setName("RIGHT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::EAST);

	leftCom = new CommandLeft();
	leftCom->setName("RIGHT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::SOUTH);

	leftCom = new CommandLeft();
	leftCom->setName("RIGHT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::WEST);

	leftCom = new CommandLeft();
	leftCom->setName("RIGHT");
	myRobot.doCommand(leftCom);
	EXPECT_EQ(myRobot.getRobotPosition().direction, CardinalDirections::NORTH);
}

TEST_F(TestRobotFixture, TestMoveCommand)
{
	constexpr int EXPECTED_X_COORD = 1;
	constexpr int EXPECTED_Y_COORD = 2;

	RobotPosition position{ 1, 2, CardinalDirections::NORTH };
	doPlaceCommand(position);
	RobotPosition currentPosition = myRobot.getRobotPosition();

	Command* mvCom = new CommandMove();
	mvCom->setName("MOVE");
	myRobot.doCommand(mvCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(myRobot.getRobotPosition().yCoordinate, EXPECTED_Y_COORD + 1);

	mvCom = new CommandMove();
	mvCom->setName("MOVE");
	position.direction = CardinalDirections::SOUTH;

	doPlaceCommand(position);
	myRobot.doCommand(mvCom);
	EXPECT_EQ(myRobot.getRobotPosition().yCoordinate, EXPECTED_Y_COORD - 1);

	mvCom = new CommandMove();
	mvCom->setName("MOVE");
	position.direction = CardinalDirections::EAST;

	doPlaceCommand(position);
	myRobot.doCommand(mvCom);
	EXPECT_EQ(myRobot.getRobotPosition().xCoordinate, EXPECTED_X_COORD + 1);

	mvCom = new CommandMove();
	mvCom->setName("MOVE");
	position.direction = CardinalDirections::WEST;

	doPlaceCommand(position);
	myRobot.doCommand(mvCom);
	EXPECT_EQ(myRobot.getRobotPosition().xCoordinate, EXPECTED_X_COORD - 1);
}

TEST_F(TestRobotFixture, TestMoveCommandOutofBounds)
{
	const std::vector<RobotPosition> EXPECTED_POSITIONS =
	{
		{ 0, 0, CardinalDirections::WEST },
		{ 0, 4, CardinalDirections::NORTH },
		{ 0, 0, CardinalDirections::SOUTH },
		{ 4, 0, CardinalDirections::EAST }
	};

	for (auto& position : EXPECTED_POSITIONS)
	{
		doPlaceCommand(position);
		RobotPosition currentPosition = myRobot.getRobotPosition();

		Command* mvCom = new CommandMove();
		mvCom->setName("MOVE");
		myRobot.doCommand(mvCom);
		currentPosition = myRobot.getRobotPosition();
		EXPECT_EQ(myRobot.getRobotPosition().xCoordinate, position.xCoordinate);
		EXPECT_EQ(myRobot.getRobotPosition().yCoordinate, position.yCoordinate);
		EXPECT_EQ(myRobot.getRobotPosition().direction, position.direction);
	}
}

TEST_F(TestRobotFixture, TestOtherCommandWithoutFirstValidPlaceCommand)
{
	Command* mvCom = new CommandMove();
	mvCom->setName("MOVE");

	Command* leftCom = new CommandLeft();
	leftCom->setName("LEFT");

	Command* rightCom = new CommandRight();
	rightCom->setName("RIGHT");

	Command* reportCom = new CommandReport();
	reportCom->setName("REPORT");

	Command* placeCom = new CommandPlace(1, 2, CardinalDirections::NORTH);
	placeCom->setName("PLACE");

	constexpr int EXPECTED_X_COORD = 0;
	constexpr int EXPECTED_Y_COORD = 0;
	constexpr CardinalDirections EXPECTED_DIRECTION = CardinalDirections::NOT_ON_BOARD;

	myRobot.doCommand(mvCom);
	RobotPosition currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction,   EXPECTED_DIRECTION);

	myRobot.doCommand(leftCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction,   EXPECTED_DIRECTION);

	myRobot.doCommand(rightCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction,   EXPECTED_DIRECTION);

	myRobot.doCommand(reportCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD);
	EXPECT_EQ(currentPosition.direction,   EXPECTED_DIRECTION);

	constexpr int EXPECTED_X_COORD_OK = 1;
	constexpr int EXPECTED_Y_COORD_OK = 2;
	constexpr CardinalDirections EXPECTED_DIRECTION_OK = CardinalDirections::NORTH;

	myRobot.doCommand(placeCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD_OK);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD_OK);
	EXPECT_EQ(currentPosition.direction,   EXPECTED_DIRECTION_OK);

	mvCom = new CommandMove();
	mvCom->setName("MOVE");

	myRobot.doCommand(mvCom);
	currentPosition = myRobot.getRobotPosition();
	EXPECT_EQ(currentPosition.xCoordinate, EXPECTED_X_COORD_OK);
	EXPECT_EQ(currentPosition.yCoordinate, EXPECTED_Y_COORD_OK + 1);
	EXPECT_EQ(currentPosition.direction, EXPECTED_DIRECTION_OK);
}