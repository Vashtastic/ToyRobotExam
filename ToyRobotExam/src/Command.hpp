#pragma once
#include <iostream>
#include <vector>
class Command
{
public:
    Command() {};
    virtual ~Command()
    {}
    void setName(std::string name)
    {
        this->name = name;
    }
    std::string name;
};