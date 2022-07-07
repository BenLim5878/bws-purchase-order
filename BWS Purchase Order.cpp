// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Helper.h"
#include "PriorityQueue.h"
#include "User.h"
#include "PriorityClass.h"
#include "SalesOrderExecutive.h"


int main()
{

    PririorityQueue<User>* queue = new PririorityQueue<User>();
    User user1;
    user1.emailAddress= "mfasd";
    PriorityClass<User> priority;
    priority.content = user1;
    //
    priority.priority = 35432;
    queue->enqueue(priority);
    //
    priority.priority = 67;
    queue->enqueue(priority);
    //
    priority.priority = 107;
    queue->enqueue(priority);
    //
    PriorityClass<User> test;
    test.content = user1;
    test.priority = 78;
    PriorityClass<User>* sample =  queue->enqueue(test);
    queue->dequeue(sample);

    std::cout << typeid(User::emailAddress).name();

    SalesOrderExecutive* soe = new SalesOrderExecutive;
    soe->menu();
}
