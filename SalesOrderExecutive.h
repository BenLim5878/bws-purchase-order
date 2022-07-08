#pragma once
#include "User.h"
class SalesOrderExecutive : public User
{
private:
	int executiveID;
public:
	int getExecutiveID();
	void setExecutiveID(int executiveID);
	int menu();
};

