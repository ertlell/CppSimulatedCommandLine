#pragma once
#include <string>

class AbstractCommand {
public: 
	virtual int execute(std::string s) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};