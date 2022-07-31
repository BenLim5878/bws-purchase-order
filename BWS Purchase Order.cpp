// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "DataAccess.h"
#include "Session.h"
#include "LoginView.h"
#include <windows.h>

using namespace std;

DataAccess* DataAccess::instance = 0;
Session* Session::instance = 0;

int main()
{
    // Set window size
    HANDLE hOut;
    SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
    //set x and y to whatever ye' want
    int x = 160;
    int y = 40;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DisplayArea.Right = x;
    DisplayArea.Bottom = y;

    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

	View::LoginView view;
	view.show();



	return 0;
}

