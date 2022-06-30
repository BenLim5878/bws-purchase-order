#pragma once
#include "User.h"
#include <ctime>
#include <string>

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
	AuthResult* authenticateUser(AuthInputForm);
private:
	std::string pwdEncrypt(std::string pwd);
	std::string pwdDecrypt(std::string encryptedPwd);
};

