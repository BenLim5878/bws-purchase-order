#pragma once
#include "LinkedList.h"

template <class T> class Stack
{
public:
	int length = 0;
public:
	void push(T data);
	bool isEmpty();
	T pop();
	T* peek();
	T* top(int i);
	T* get(int i);
	void update(int topIndex, T data);
	void update(T* tarrData, T data);
private:
	SinglyNode<T>* getNode(int i);
private:
	SinglyNode<T>* root;
};

template <class T>
void Stack<T>::push(T data) {
	SinglyNode<T>* node = new SinglyNode<T>();
	node->data = data;
	node->next = root;
	this->root = node;
	this->length++;
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
	delete temp;
	this->length--;
	return popped;
}

template <class T>
T* Stack<T>::peek() {
	T* temp = &(this->root->data);
	return temp;
}

template<class T>
T* Stack<T>::top(int i)
{
	if (i <= 0) return nullptr;
	if (i > this->length) return nullptr;
	int target = i;
	int curr = 1;
	SinglyNode<T>* currentNode = this->root;
	while (curr <= this->length) {
		if (curr == target) {
			return &currentNode->data;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return nullptr;
}

template<typename T>
T* Stack<T>::get(int i)
{
	if (i >= this->length) return nullptr;
	int target = i;
	int curr = 0;
	SinglyNode<T>* currentNode = this->root;
	while (curr < this->length) {
		if (curr == target) {
			return &currentNode->data;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return nullptr;
}

template<class T>
void Stack<T>::update(int topIndex, T data)
{
	SinglyNode<T>* tarrData = getNode(topIndex);
	if (!tarrData) return;
	tarrData->data = data;
}

template<class T>
inline void Stack<T>::update(T* tarrData, T data)
{
	// If nullptr, then return
	if (!tarrData) return;

	SinglyNode<T>* currNode = this->root;
	if (currNode) {
		while (&currNode->data != tarrData) {
			currNode = currNode->next;
			if (!currNode)return;
		}
		currNode->data = data;
	}
}

template<class T>
SinglyNode<T>* Stack<T>::getNode(int i)
{
	if (i <= 0) return nullptr;
	if (i > this->length) return nullptr;
	int target = i;
	int curr = 1;
	SinglyNode<T>* currentNode = this->root;
	while (curr <= this->length) {
		if (curr == target) {
			return currentNode;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return nullptr;
}

