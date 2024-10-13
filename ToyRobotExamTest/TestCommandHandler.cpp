#include "pch.h"
#include "CommandHandler.hpp"
#include "CommandPlace.hpp"
#include <memory>
#include "Command.hpp"
#include <stdexcept>

class TestCommandHandler : public ::testing::Test
{
protected:
	TestCommandHandler() {};
	~TestCommandHandler() {};
	CommandHandler commandHandler;
};

TEST_F(TestCommandHandler, TestInvalidCommand)
{
	std::string command = "AWEF";
	commandHandler.storeCommandToken(command);
	try
	{
		std::unique_ptr<Command> ptr(commandHandler.createCommand());
	}
	catch (std::exception& exc)
	{
		EXPECT_STREQ(exc.what(), "Command was not created");
	}
}

TEST_F(TestCommandHandler, TestPlaceCommandCreationOk)
{
	std::string command = "PLACE 0,0,NORTH";
	commandHandler.storeCommandToken(command);
	EXPECT_STRCASEEQ(commandHandler.getCurrentCommand().c_str(), "PLACE");
	std::unique_ptr<Command> ptr(commandHandler.createCommand());
	EXPECT_STRCASEEQ(ptr->name.c_str(), "PLACE");
}

TEST_F(TestCommandHandler, TestPlaceCommandCreationNok)
{
	std::string command = "PLACE";
	std::vector<std::string> commands = { "PLACE", "PLACE 1", "PLACE 1,2", "PLACE 1,2,3", "PLACE 1,2,3,NORTH" };

	for(auto& command : commands)
	{
		commandHandler.storeCommandToken(command);
		EXPECT_STRCASEEQ(commandHandler.getCurrentCommand().c_str(), "PLACE");
		try
		{
			std::unique_ptr<Command> ptr(commandHandler.createCommand());
		}
		catch (std::exception& exc)
		{
			EXPECT_STREQ(exc.what(), "Command was not created");
		}
	}
}

TEST_F(TestCommandHandler, TestMoveCommandCreationOk)
{
	std::string command = "MOVE";
	commandHandler.storeCommandToken(command);
	EXPECT_STRCASEEQ(commandHandler.getCurrentCommand().c_str(), "MOVE");
	std::unique_ptr<Command> ptr(commandHandler.createCommand());
	EXPECT_STRCASEEQ(ptr->name.c_str(), "MOVE");
}

TEST_F(TestCommandHandler, TestLeftCommandCreationOk)
{
	std::string command = "LEFT";
	commandHandler.storeCommandToken(command);
	EXPECT_STRCASEEQ(commandHandler.getCurrentCommand().c_str(), "LEFT");
	std::unique_ptr<Command> ptr(commandHandler.createCommand());
	EXPECT_STRCASEEQ(ptr->name.c_str(), "LEFT");
}
TEST_F(TestCommandHandler, TestReportCommandCreationOk)
{
	std::string command = "REPORT";
	commandHandler.storeCommandToken(command);
	EXPECT_STRCASEEQ(commandHandler.getCurrentCommand().c_str(), "REPORT");
	std::unique_ptr<Command> ptr(commandHandler.createCommand());
	EXPECT_STRCASEEQ(ptr->name.c_str(), "REPORT");
}