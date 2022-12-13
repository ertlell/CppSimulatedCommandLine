#include "../SharedCode/DisplayCommand.h"

using namespace std;


DisplayCommand::DisplayCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
	bdv_ptr = new BasicDisplayVisitor();
}


int DisplayCommand::execute(string s) {

	if (s.substr(s.length() - 2) == "-d") { //Unformatted

		string fileName = s.substr(0, s.length() - 3);

		AbstractFile * currentFile = afs_ptr->openFile(fileName);
		if (currentFile == nullptr) {
			return fileNotOpen;
		}
		vector<char> contents = currentFile->read();
		for (char c : contents) {
			cout << c;
		}
		cout << endl;
		return successful;

	}
	else if (afs_ptr->openFile(s) != nullptr) { //Formatted
		AbstractFile* currentFile = afs_ptr->openFile(s);
		if (currentFile == nullptr) {
			return fileNotOpen;
		}
		currentFile->accept(bdv_ptr);
		return successful;
	}
	else {
		return failedCommand;
	}
}

void DisplayCommand::displayInfo() {
	cout << "ds <filename> will open a file and display its contents. ds <filename> -d will display unformatted data" << endl;
}