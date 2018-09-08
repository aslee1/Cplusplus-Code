#pragma once
#include <string>

namespace KP_FileReaderClass{
	class FileReader
	{
	public:
		FileReader();
		virtual ~FileReader();

		//Returns file contents
		int getFileContents(const std::string filename, std::string &contents);
	private:
		//Reads the whole file at once
		int ReadTheWholeFile(const std::string &filename);
		std::string		filecontents;
	};
}

