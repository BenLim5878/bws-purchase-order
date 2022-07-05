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
