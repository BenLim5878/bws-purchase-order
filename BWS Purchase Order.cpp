// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "PriorityQueue.h"
#include "User.h"

using namespace std;


int main()
{
	User user;
	user.emailAddress = "hfads";
	PriorityClass<User> userPriority;
	userPriority.content = user;
	userPriority.priority = 50;
	PririorityQueue<User>* list = new PririorityQueue<User>();
	list->enqueue(userPriority);
	//
	userPriority.priority = 100;
	list->enqueue(userPriority);
	//
	userPriority.priority = 75;
	list->enqueue(userPriority);


	userPriority.priority = 25;
	list->update(5, userPriority);

	cout << "fasd";

}
