#pragma once
#include "PriorityClass.h"
#include "LinkedList.h"

template <class T>class PririorityQueue
{
private:
	DoublyNode<PriorityClass<T>>* head;
public:
	DoublyNode<PriorityClass<T>>* peek();
	PriorityClass<T>* enqueue(PriorityClass<T> newData);
	void dequeue(PriorityClass<T>* data);
	bool isEmpty();
	PriorityClass<T>* get(int i);
	DoublyNode<PriorityClass<T>>* getNode(PriorityClass<T> data);
public:
	int len;
public:
	PririorityQueue();
	~PririorityQueue();
};

template <class T>
void swap(DoublyNode<PriorityClass<T>>* leftNode, DoublyNode<PriorityClass<T>>* rightNode) {
	DoublyNode<PriorityClass<T>>* X = leftNode->prev, * Y = rightNode->next;
	leftNode->prev = rightNode;
	leftNode->next = Y;
	rightNode->prev = X;
	rightNode->next = leftNode;
	if (X) {
		X->next = rightNode;
	}
	if (Y) {
		Y->prev = leftNode;
	}
}

template <class T>
PriorityClass<T>* PririorityQueue<T>::enqueue(PriorityClass<T> newData)
{
	DoublyNode<PriorityClass<T>>* newNode = new DoublyNode<PriorityClass<T>>();
	newNode->data = newData;
	newNode->data.referenceAddress = newNode;
	this->head = newNode;
	this->len++;
	// If the list is empty then point the head to the new node
	if (isEmpty()) {
		return &(newNode->data);
	}
	else {
		newNode->next = this->head;
	}
	newNode->next = this->head;

	for (int i = 0; i < this->len; i++) {
		// The node is placed at last
		if (!newNode->next) {
			return &(newNode->data);
		}
		// Sort the node
		if (newNode->data.priority < newNode->next->data.priority) {
			swap(newNode, newNode->next);
			if (i == 0) {
				this->head = newNode->prev;
			}
		}
		else {
			return &(newNode->data);
		}
	}
}

template <class T>
void PririorityQueue<T>::dequeue(PriorityClass<T>* data)
{
	DoublyNode<PriorityClass<T>>* tarrNode =  getNode(*data);
	if (tarrNode) {
		DoublyNode<PriorityClass<T>>* prevNode = nullptr;
		DoublyNode<PriorityClass<T>>* nextNode = nullptr;
		// Get left and right nodes
		if (tarrNode->prev) {
			prevNode = tarrNode->prev;
		}
		if (tarrNode->next) {
			nextNode = tarrNode->prev;
		}

		if (tarrNode->prev && tarrNode->next) {
			prevNode->next = nextNode;
			nextNode->next = prevNode;
		}
		if (tarrNode->next) {
			nextNode = tarrNode->prev;
		}


		free(tarrNode);
	}
}

template <class T>
bool PririorityQueue<T>::isEmpty()
{
	if (this->len == 0) {
		return true;
	}
	return false;
}

template <class T>
PriorityClass<T>* PririorityQueue<T>::get(int i)
{
	int curr = 0;
	DoublyNode<PriorityClass<T>>* currNode = this->head;
	for (int j = 0; j < this->len; j++) {
		if (i == curr) {
			return &currNode->data;
		}
		else {
			currNode = currNode->next;
			curr++;
		}
	}
	return nullptr;
}


template <class T>
DoublyNode<PriorityClass<T>>* PririorityQueue<T>::getNode(PriorityClass<T> data)
{
	int curr = 0;
	DoublyNode<PriorityClass<T>>* currNode = this->head;
	for (int j = 0; j < this->len; j++) {
		if (currNode->data.referenceAddress == data.referenceAddress) {
			return currNode;
		}
		else {
			currNode = currNode->next;
			curr++;
		}
	}
	return nullptr;
}


template <class T>
PririorityQueue<T>::PririorityQueue() :len(0)
{
}

template <class T>
PririorityQueue<T>::~PririorityQueue()
{
}


