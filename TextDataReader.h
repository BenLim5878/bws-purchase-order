#pragma once
#include <string>
#include <list>
#include <vector>

class TextDataReader
{
public:
	std::string textfilePath;
	void readFile();
	std::list<std::string> *context;
public:
	std::vector<std::string> splitDelimeter(std::string record);
public:
	TextDataReader(std::string textfilePath);
	~TextDataReader();
};

