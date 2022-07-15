#pragma once
#include "User.h"
#include "Auth.h"

enum LoggedStatus {
	NotLogged,
	Logged
};

class Session
{
public:
	User* loggedUser;
private:
	LoggedStatus loggedStatus;
	time_t timeLogged;
public:
	static Session* getInstance();
public:
	void setSession(AuthResult res);
	void deleteSession();
private:
	Session();
	static Session* instance;
};

