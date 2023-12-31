//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the functions within the MacroCommand class
#include "MacroCommand.h"


using namespace std;

//Constructs a MacroCommand given a pointer to an AbstractFileSystem
MacroCommand::MacroCommand(AbstractFileSystem* afs_ptr_in) {
	afs_ptr = afs_ptr_in;
}


//Takes a pointer to an AbstractCommand and pushes it to the end of member variable commands vector
void MacroCommand::addCommand(AbstractCommand* ab_cmd_ptr) {
	commands.push_back(ab_cmd_ptr);
}

//takes a pointer to an AbstractParsingStrategy and sets the parsing strategy of the Macrocommand to it
void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_ptr_in) {
	aps_ptr = aps_ptr_in;
}

//Take output from parsing strategy and individually execute each command
int MacroCommand::execute(string s) {
	vector<string> inputs = aps_ptr->parse(s);
	//Iterate through all commands that the MacroCommand is comprised of 
	for (int i = 0; i < commands.size(); i++) {
		AbstractCommand* cmd = commands[i];
		cout << "Inputs[i]: " << inputs[i] << endl;
		if (cmd->execute(inputs[i]) != 0) {
			cout << "Failed on iteration " << i << endl; 
			return failedCommand;
		}
	}
	//If we've made it to this point, execution was successful because each individuual command executed successfully
	return successful;

}

//Displays helpful information about MacroCommand to the user
void MacroCommand::displayInfo() {
	cout << "A macroCommand is a combination of two commands. Refer to ReadMe.txt for more information on how to invoke each individual command" << endl;
}
