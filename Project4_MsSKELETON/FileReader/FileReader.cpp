#include <iostream>
#include <fstream>
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;
FileReader::FileReader(){
}
FileReader::~FileReader(){
}
int FileReader::getFileContents(const std::string filename, std::string &contents){
	ios_base::openmode mode=ios_base::in;
	fstream myfile;
	std::string line;
	//Open file
	myfile.open(filename.c_str(), mode);
	if(myfile.is_open()){
		//copy file contents to a string
		while(getline(myfile, line)){
			contents+=line; 
		}
	}
	else{
		return COULD_NOT_OPEN_FILE;
	}
	//close file
	myfile.close(); 
	if(myfile.is_open()){
		return COULD_NOT_CLOSE_FILE;
	}
	return SUCCEEDED;
}
int FileReader::ReadTheWholeFile(const std::string &filename){
	std::string filecontents;
	FileReader::getFileContents(filename, filecontents);
	return 0;
}