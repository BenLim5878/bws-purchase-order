#include "LoginView.h"
#include <Windows.h>
#include <iostream>
#include "Header.h"
#include "Time.h"
#include "Auth.h"
#include "Menu.h"

using namespace std;

void View::LoginView::show()
{
    AuthInputForm form;
    int failureAttempt = 0;

    while (failureAttempt < 5) {
        system("CLS");
        ViewHeader::Header head;
        head.display();
        displayTime::Time dtime;
        dtime.show();

        std::cout << "\n=================== LOGIN MENU ===================" << endl;
        if (failureAttempt > 0) {
            std::cout << "Incorrect credentials. Please retype your credentials!: \n" << endl;
        }
        else {
            std::cout << "Please enter your credentials: \n" << endl;
        }
        std::cout << "Email Address: ";
        std::cin >> form.emailAddress;
        std::cout << "Password: ";
        std::cin >> form.password;
        std::cout << "" << endl;
        std::cout << "============================================" << endl;

        Auth auth;
        AuthResult result = auth.authenticateUser(form);
        if (result.isSuccessful) {
            Menu menu;
            menu.show();
            return;
        }
        else {
            failureAttempt++;
        }
    }
    if (failureAttempt >= 5) {
        system("CLS");
        exit(0);
    }

}