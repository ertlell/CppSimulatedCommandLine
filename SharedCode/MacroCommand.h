//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This file contains the declaration of the MacroCommand class

#pragma once

#include<vector>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"


class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* aps_ptr;
	AbstractFileSystem* afs_ptr;
public:
	MacroCommand(AbstractFileSystem* afs_ptr_in);
	~MacroCommand() = default;
	void displayInfo() override;
	int execute(std::string s) override;
	void addCommand(AbstractCommand* ab_cmd_ptr);
	void setParseStrategy(AbstractParsingStrategy* aps_ptr_in);
};

