// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Helper.h"
#include "PriorityQueue.h"
#include "User.h"
#include "PriorityClass.h"

int main()
{
    PririorityQueue<User>* queue = new PririorityQueue<User>();
    User user1;
    user1.emailAddress= "mfasd";
    PriorityClass<User> priority;
    priority.priority = 324;
    priority.content = user1;
    queue->enqueue(priority);
    priority.priority = 54;
    queue->enqueue(priority);
    priority.priority = 67;
    queue->enqueue(priority);
    priority.priority = 107;
    queue->enqueue(priority);
    DoublyNode<PriorityClass<User>>* res = queue->getNode(priority);

    std::cout << typeid(User::emailAddress).name();
}
