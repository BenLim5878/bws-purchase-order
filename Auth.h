#pragma once
#include "User.h"
#include <ctime>
#include <string>
#include "UserRepository.h"
#include <memory>

struct AuthResult {
	bool isSuccessful;
	User authenticatedUser;
	time_t timeAuthenticated = time(0);
};

struct AuthInputForm {
	std::string emailAddress;
	std::string password;
};

class Auth
{
public:
	std::unique_ptr<AuthResult> authenticateUser(AuthInputForm form);
private:
	unsigned long pwdEncrypt(std::string pwd);
private: 
	UserRepository* repository;
public:
	Auth();
	~Auth();
};

