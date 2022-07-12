#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

namespace displayTime {
	class Time {
	public:
		void show() {
            std::cout << "" << endl;
            std::cout << "The current date is: ";
            system("date/t");
            std::cout << "The current time is: ";
            system("time/t");
            std::cout << endl;
		}
	};
}




