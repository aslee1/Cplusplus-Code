//============================================================================
// Name        : Proj4_Test.cpp
// Author      : Amanda Lee
// Version     :
// Copyright   : much copyright. wow
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "..\Include\FileReader.h"	//relative path, from PWD, go up one, then down into Include to find FileReader.h
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
#include "..\Include\StringParserClass.h"

void outputvectorrow(std::string i){
	std::cout<<i<<std::endl;
}
void foreach(std::vector<std::string> myVector){
	std::for_each(myVector.begin(), myVector.end(), outputvectorrow);
}

bool writeVectortoFile(const std::string &OUTPUTFILENAME, std::vector<std::string> myVector){
	std::fstream outfile; 
	outfile.open(OUTPUTFILENAME,std::ios_base::out);
	if(!outfile.is_open()){
		return false;
	}
	std::vector<std::string>::iterator it;
	for (it = myVector.begin(); it != myVector.end(); ++it){
		outfile<<(*it) << " "<<std::endl;
	}
	outfile.close();
	return true;
}

int main(){
	//Open file, if not there ask for a different file or exit
	std::string 		myFileName 				= TEST_FILE_NAME;
	std::fstream 			myfile(myFileName);

	//open file
	while (!myfile.is_open()){
		std::cout << "Please enter a filename or an X to eXit" << std::endl; //
		std::cin.clear();
		getline(std::cin, myFileName,'\n');		//getline from standard input
											//gets the full line including spaces up until a \n encountered
		if (myFileName.compare(EXITCHAR) == 0)
			return USER_CHOSE_TO_EXIT;
	}
	std::string contents;
	KP_FileReaderClass::FileReader reader;
	reader.getFileContents(myFileName, contents); 
	//got file data, this is a step
	//whose sole purpose is to provide a way to pass
	//in a non const pointer to getDataBetweenTags(..) without casting
	/*vector<char> myLine;
	std::copy(filecontents.begin(), filecontents.end(), back_inserter(myLine));*/
	std::string::pointer contentspoint=0;
	//char contentsCharArray[]=contents;
	contentspoint=&contents[0];

	//Creates an instance of the stringparser
	std::vector<std::string> myVector;
	KP_StringParserClass::StringParserClass stringParser;

	//set tags
	stringParser.setTags(START_TAG,END_TAG);

	//get the data between the tags
	stringParser.getDataBetweenTags(contentspoint, myVector);

	//output the vector
	writeVectortoFile(OUTPUTFILENAME,myVector);
		std::vector<std::string>::iterator it;
	for (it = myVector.begin(); it != myVector.end(); ++it){
		std::cout<<(*it) << " "<<std::endl;
	}
	
}



