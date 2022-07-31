#pragma once
#include <string>

enum UserRole
{
	Admin,
	SOE
};

class User
{
private:
	int userID;
	std::string pwd;
public:
	std::string name;
	UserRole role;
	std::string phoneNo;
	std::string nationalID;
	std::string houseAddress;
	std::string emailAddress;
public:
	int getUserID();
	void setUserID(int userID);
	std::string getPwd();
	void setPwd(std::string password);
	static std::string userRoleToString(UserRole role);
};

