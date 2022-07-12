// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Tree.h"
#include "ProductRepository.h"
#include "Menu.h"
#include "DataAccess.h"
#include "ProductRepository.h"
#include "Session.h"
#include "Auth.h"

using namespace std;

DataAccess* DataAccess::instance = 0;
Session* Session::instance = 0;

int main()
{
	AuthInputForm form;
	form.emailAddress = "limzhengwei1002@gmail.com";
	form.password = "abc12345";

	Auth auth;
	auth.authenticateUser(form);
	Session* session = Session::getInstance();
	Session::getInstance()->deleteSession();
	auth.authenticateUser(form);

	return 0;
}