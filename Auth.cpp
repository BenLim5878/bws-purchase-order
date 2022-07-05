#include "Auth.h"
#include <string.h>

char* toChar(std::string text) {
    char* cstr = new char[text.length() + 1];
    strcpy_s(cstr,text.size()+1, text.c_str());
    return cstr;
}

std::unique_ptr<AuthResult> Auth::authenticateUser(AuthInputForm form)
{
    std::hash<std::string> hash;
    std::unique_ptr<AuthResult> res(new AuthResult());
    for (User user : repository->users) {
        unsigned long tarr = hash(form.password);
        if (form.emailAddress == user.emailAddress && tarr == std::stoul(toChar(user.getPwd()))) {
            res->authenticatedUser = user;
            res->isSuccessful = true;
            return res;
        }
    }
    res->isSuccessful = false;
    return res;
}

unsigned long Auth::pwdEncrypt(std::string pwd)
{
    std::hash<std::string> hash;
    return hash(pwd);
}

Auth::Auth(): repository(new UserRepository("User.txt"))
{
}

Auth::~Auth()
{
    delete repository;
}
