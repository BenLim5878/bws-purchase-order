#pragma once
#include "LinkedList.h"

template <class T> class PriorityClass {
public:
	T content;
	long priority;
	DoublyNode<PriorityClass<T>>* referenceAddress;
};