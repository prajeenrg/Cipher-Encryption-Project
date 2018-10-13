#pragma once
#include <string>
#include <fstream>

class FileUtils
{
	std::fstream file;

  public:
	void writeToFile(std::string &, std::string *);
	std::string *readFromFile(std::string &);
};