#define NOMINMAX
#include "Helper.h"
#include <ctime>
#include <iostream>
#include <limits>

tm stringToTime(std::string timeString) {
	tm tm;
	std::string year = timeString.substr(0, 4);
	std::string month = timeString.substr(5, 2);
	std::string day = timeString.substr(8, 2);
	std::string hour = timeString.substr(11, 2);
	std::string minute = timeString.substr(14, 2);
	std::string second = timeString.substr(17, 2);

	tm.tm_year = std::stoi(year) - 1900;
	tm.tm_mon = std::stoi(month) - 1;
	tm.tm_mday = std::stoi(day);
	tm.tm_hour = std::stoi(hour);
	tm.tm_min = std::stoi(minute);
	tm.tm_sec = std::stoi(second);

	return tm;
}

int getCurrentYear()
{
	time_t currentTime= std::time(0);
	tm now;
	localtime_s(&now,&currentTime);
	return now.tm_year + 1900;
}

void cleanBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int promptNumericInput() {
	int option;
	std::cin >> option;
	std::cin.ignore();
	if (std::cin.fail()) {
		cleanBuffer();
		return -1;
	}
	else {
		return option;
	}
}