#include "User.h"


int User::getUserID() {
	return this->userID;
}

void User::setUserID(int userID) {
	this->userID = userID;
}

std::string User::getPwd() {
	return this->pwd;
}

void User::setPwd(std::string pwd) {
	this->pwd = pwd;
}

std::string User::userRoleToString(UserRole role)
{
	switch (role) {
	case UserRole::Admin:
		return "Admin";
	case UserRole::SOE:
		return "Sales Order Executive";
	default:
		return "Admin";
	}
}
