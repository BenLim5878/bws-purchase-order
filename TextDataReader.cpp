#include "TextDataReader.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>

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
