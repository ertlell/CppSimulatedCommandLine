//  Define the TextFile class here
#include "TextFile.h"
using namespace std;

TextFile::TextFile(string input_file) {
	file_name = input_file;
}

void TextFile::read() {
	for (char c : file_contents) {
		cout << c;
	}
}

unsigned int TextFile::getSize() {
	return file_contents.size();
}

string TextFile::getName() {
	return file_name;
}

int TextFile::write(vector<char> writeIn) {
	file_contents = writeIn;
	return 0;
}

int TextFile::append(std::vector<char> toAdd) {
	for (char c : toAdd) {
		file_contents.push_back(c);
	}
	return 0;
}

