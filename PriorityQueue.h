#pragma once
#include "PriorityClass.h"
#include "LinkedList.h"

template <class T>class PririorityQueue
{
private:
	DoublyNode<PriorityClass<T>>* head;
public:
	DoublyNode<PriorityClass<T>>* peek();
	void enqueue(PriorityClass<T> newData);
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
void PririorityQueue<T>::enqueue(PriorityClass<T> newData)
{
	DoublyNode<PriorityClass<T>>* newNode = new DoublyNode<PriorityClass<T>>();
	newNode->data = newData;
	newNode->data.referenceAddress = newNode;
	if (isEmpty()) {
		this->head = newNode;
		this->len++;
		return;
	}
	newNode->next = this->head;
	this->head = newNode;
	for (int i = 0; i < this->len; i++) {
		if (!newNode->next) return;
		if (newNode->data.priority < newNode->next->data.priority) {
			swap(newNode, newNode->next);
			if (i == 0) {
				this->head = newNode->prev;
			}
		}
		else {
			this->len++;
			return;
		}
	}

}

template <class T>
void PririorityQueue<T>::dequeue(PriorityClass<T>* data)
{

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


