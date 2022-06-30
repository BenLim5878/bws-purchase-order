#pragma once
#include <string>
#include "User.h"

class Administrator : public User
{
private:
	int adminID;
public:
	int getAdminID();
	void setAdminID(int adminID);
};

