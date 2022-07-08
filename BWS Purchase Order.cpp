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
	User user;
	user.emailAddress = "hfads";
	Stack<User> list;
	list.push(user);
	list.push(user);
	list.push(user);
	user.emailAddress = "fuck";
	list.update(0, user);
	cout << "fasd";

	SalesOrderExecutive* SOE = new SalesOrderExecutive;
	SOE->menu();
}
