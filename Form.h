#pragma once
#include <string>

class Form
{
public:
	std::string header;
	std::string footer;
	std::string content;
private:
	std::string title;
public:
	void setTitle(std::string title);
	void show();
};

