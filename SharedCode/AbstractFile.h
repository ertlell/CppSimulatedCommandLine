#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// This file contains the AbstractFile class definition to be used by different file types.
// It also contains relevant enum return values utilized throughout the program
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <iostream>
#include<string>
#include <map>
#include <set>

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual std::vector<char> read()=0;
	virtual int write(std::vector<char> writeIn)=0;
	virtual int append(std::vector<char> toAdd)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor* afv) = 0;
	virtual AbstractFile* clone(std::string newName) = 0;
};


enum errors {successful, incorrectImageFileInput, appendNotAvailable, sizeMismatch, 
	/*4*/ duplicateFile, nullFile, duplicateFileName, invalidFileName, invalidExtension,
	/*9*/ fileNotOpen, fileDoesNotExist, fileAlreadyOpen, incorrectPassword, cannotAddCommand, userQuit,
	/*15*/ commandDoesNotExist, cannotCreateFile, fileNameTooLong, failedCommand };