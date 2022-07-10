#include "Helper.h"
#include <Windows.h>

void hidecursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

tm stringToTime(std::string timeString) {
	tm tm;
	std::string year = timeString.substr(0, 4);
	std::string month = timeString.substr(5, 2);
	std::string day = timeString.substr(8, 2);
	std::string hour = timeString.substr(11, 2);
	std::string minute = timeString.substr(14, 2);
	std::string second = timeString.substr(17, 2);

	tm.tm_year = std::stoi(year);
	tm.tm_mon = std::stoi(month) - 1;
	tm.tm_mday = std::stoi(day);
	tm.tm_hour = std::stoi(hour);
	tm.tm_min = std::stoi(minute);
	tm.tm_sec = std::stoi(second);

	return tm;
}