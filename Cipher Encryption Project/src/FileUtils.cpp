#include "FileUtils.h"

void FileUtils::writeToFile(std::string &fileloc, std::string *content)
{
	file.open(fileloc.c_str(), std::ios::out);
	file.write(content->c_str(), content->size());
	file.close();
}

std::string *FileUtils::readFromFile(std::string &fileloc)
{
	file.open(fileloc.c_str(), std::ios::in);
	if (!file)
	{
		return nullptr;
	}
	std::string *content = new std::string;
	file.seekg(0, std::ios::end);
	content->reserve(static_cast<const unsigned int>(file.tellg()));
	file.seekg(0, std::ios::beg);
	content->assign(std::istreambuf_iterator<char>(file),
					std::istreambuf_iterator<char>());
	file.close();
	return content;
}