#pragma once
#include "User.h"
class SalesOrderExecutive: public User
{
private:
	int executivesID;
public:
	int getExecutiveID();
	void setExecutiveID(int executiveID);
};

