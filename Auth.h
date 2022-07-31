#pragma once
#include "User.h"
#include <ctime>
#include <string>
#include "UserRepository.h"

struct AuthResult {
	bool isSuccessful;
	User* authenticatedUser;
	time_t timeAuthenticated = time(0);
};

struct AuthInputForm {
	std::string emailAddress;
	std::string password;
};

class Auth
{
public:
	AuthResult authenticateUser(AuthInputForm form);
private: 
	UserRepository* repository;
public:
	Auth();
	~Auth();
};

