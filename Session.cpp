#include "Session.h"

Session* Session::getInstance()
{
	if (instance == 0) {
		instance = new Session();
	}
	return instance;
}

void Session::setSession(AuthResult res)
{
	this->loggedUser = res.authenticatedUser;
	this->loggedStatus = static_cast<LoggedStatus>(res.isSuccessful);
	this->timeLogged = res.timeAuthenticated;
}

void Session::deleteSession()
{
	this->loggedUser = nullptr;
	this->loggedStatus = LoggedStatus::NotLogged;
	this->timeLogged = 0;
}

Session::Session() {
	this->loggedUser = nullptr;
	this->loggedStatus = LoggedStatus::NotLogged;
	this->timeLogged = 0;
}