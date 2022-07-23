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
	View::LoginView view;
	view.show();
	
	// Set window size
	HWND console = GetConsoleWindow();
	RECT r;
	r.left = 156;
	r.bottom = 156+40;
	r.right = 156 + 160;
	r.top = 156;


	return 0;
}

