// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "DataAccess.h"
#include "Session.h"
#include "LoginView.h"

using namespace std;

DataAccess* DataAccess::instance = 0;
Session* Session::instance = 0;

int main()
{
	View::LoginView view;
	view.show();
	


	return 0;
}

