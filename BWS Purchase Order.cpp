// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Auth.h"
#include <memory>
#include "SalesOrderExecutive.h"
using namespace std;


int main()
{
	Auth auth;
	string emailAddress;
	string password;
	cout << "Please enter your email address:" << endl;
	cin >> emailAddress;
	cout << "Please enter your password:" << endl;
	cin >> password;
	AuthInputForm form;
	form.emailAddress = emailAddress;
	form.password = password;
	std::unique_ptr<AuthResult> result = auth.authenticateUser(form);

	cout << result->isSuccessful;

	SalesOrderExecutive* SOE = new SalesOrderExecutive;
	SOE->menu();

}
