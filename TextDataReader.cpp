#include "TextDataReader.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>

// Referenced file read function from https://www.tutorialspoint.com/how-to-read-a-text-file-with-cplusplus
void TextDataReader::readFile()
{
    std::string tline;
	std::list<std::string>* context = new std::list<std::string>();
	std::fstream newFile;
	newFile.open(this->textfilePath, std::ios::in);
	while (std::getline(newFile, tline)) {
		context->push_back(tline);
	}
	newFile.close();
	this->context = context;
}

// Referenced split delimiters function from https://www.javatpoint.com/how-to-split-strings-in-cpp#:~:text=i%20%3A%207%20function.-,Use%20std%3A%3Agetline()%20function%20to%20split%20string,the%20header%20file.
std::vector<std::string> TextDataReader::splitDelimeter(std::string record)
{
	std::stringstream trecord(record);
	std::vector<std::string> recordContext;
	std::string	segment;
	while (std::getline(trecord, segment, ';')) {
		recordContext.push_back(segment);
	}
	return recordContext;
}

TextDataReader::TextDataReader(std::string textfilePath)
{
	this->textfilePath = textfilePath;
}

TextDataReader::~TextDataReader()
{
	delete this->context;
}
