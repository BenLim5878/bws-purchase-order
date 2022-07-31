#pragma once
#include <iostream>
#include <Windows.h>
#include <windows.graphics.h>

using namespace std;

namespace ViewHeader {
	class Header {
	public:
		void display() {
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 9); 
			std::cout << "" <<endl;
			std::cout << " *     *       **                          *          ****   *         *  ***   *** " << endl;
			std::cout << " *     *       **                          *          *   *   *       *  *      *** " << endl;
			std::cout << " *  *  * ****  **  **** **** ***** ****  ***** ****   * ****   *  *  *    ***   ***" << endl;
			std::cout << "  * * *  ***   **  *    *  * * * * ***     *   *  *   *   *     * * *        *  ***" << endl;
			std::cout << "   * *   ****  *** **** **** * * * ****    *   ****    ****     *   *    ***     @ " << endl;


			SetConsoleTextAttribute(h, 7);
			
		}
	};
}
