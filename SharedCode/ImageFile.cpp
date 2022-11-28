// definition of ImageFile class here

#include "ImageFile.h"

using namespace std;

ImageFile::ImageFile(string inName) {
	name = inName;
	size = 0;
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> inputs) {
	size = inputs[inputs.size() - 1] - '0';
	inputs.pop_back();

	if ((size * size) != inputs.size()) {
		return sizeMismatch;
	}
	if (size < 0 || size > 9) {
		return incorrectImageFileInput;
	}
	for (char x : inputs) {
		if (x != ' ' && x != 'X') {
			contents.clear();
			size = 0;
			return incorrectImageFileInput;
		}
		contents.push_back(x);
	}
	return success;
}

int ImageFile::append(vector<char> toAppend) {
	return appendNotAvailable;
}

void ImageFile::read() {
	for (int i = size-1; i >= 0; i--) {
		for( int j = 0; j < size; j++) {
			cout << contents[getIndexFromCoords(j, i)];
		}
		cout << endl;
	}
}



int ImageFile::getIndexFromCoords(int x, int y) {
	return y * size + x;
}