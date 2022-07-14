#include "Auth.h"
#include <string.h>
#include "Session.h"

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
        std::string x = form.password;
        std::string y = user->getPwd();
        if (form.emailAddress == user->emailAddress && form.password == user->getPwd()) {
            res.authenticatedUser = user;
            res.isSuccessful = true;
            Session::getInstance()->setSession(res);
            return res;
        }
    }
    res.isSuccessful = false;
    Session::getInstance()->setSession(res);
    return res;
}

Auth::Auth(): repository(new UserRepository("User.txt"))
{
}

Auth::~Auth()
{
    delete repository;
}
