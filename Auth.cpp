#include "Auth.h"
#include <string.h>

char* toChar(std::string text) {
    char* cstr = new char[text.length() + 1];
    strcpy_s(cstr,text.size()+1, text.c_str());
    return cstr;
}

AuthResult Auth::authenticateUser(AuthInputForm form)
{
    std::hash<std::string> hash;
    AuthResult res;
    for (int i = 0; i < this->repository->users->length; i++) {
        User* user = this->repository->users->get(i);
        unsigned long tarr = hash(form.password);
        if (form.emailAddress == user->emailAddress && tarr == std::stoul(toChar(user->getPwd()))) {
            res.authenticatedUser = *user;
            res.isSuccessful = true;
            return res;
        }
    }
    res.isSuccessful = false;
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
