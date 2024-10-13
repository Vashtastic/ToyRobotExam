#pragma once

#include <exception>
#include <iostream>
#include <string>

class CommandCreationException : public std::exception {
private:
    std::string message;

public:
    CommandCreationException()
        : message("Command was not created")
    {
    }

    const char* what() const throw()
    {
        return message.c_str();
    }
};