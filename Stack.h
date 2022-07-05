#pragma once
#include "LinkedList.h"

template <class T> class Stack
{
public:
	void push(T data);
	bool isEmpty();
	T pop();
	T* peek();
private:
	SinglyNode<T>* root;
};

template <class T>
void Stack<T>::push(T data) {
	SinglyNode<T>* node = new SinglyNode<T>();
	node->data = data;
	node->next = root;
	this->root = node;
}

template <class T>
bool Stack<T>::isEmpty() {
	return !root;
}

template <class T>
T Stack<T>::pop() {
	SinglyNode<T>* temp = this->root;
	this->root = temp->next;
	T popped = temp->data;
	free(temp);
	return popped;
}

template <class T>
T* Stack<T>::peek() {
	T* temp = &(this->root->data);
	return temp;
}

