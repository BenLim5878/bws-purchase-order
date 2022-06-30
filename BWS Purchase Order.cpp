// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Helper.h"
#include "UserRepository.h"

int main()
{
    hidecursor();
    UserRepository repository("User.txt");
    for (User user : repository.users) {
        std::cout << user.name << std::endl;
    }
}
