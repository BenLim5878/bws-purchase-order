#pragma once
#include "PriorityClass.h"
#include "LinkedList.h"

template <class T>class PririorityQueue
{
private:
	DoublyNode<PriorityClass<T>>* head;
public:
	int search(int l, int r, PriorityClass<T>* x);
	DoublyNode<PriorityClass<T>>* peek();
	PriorityClass<T>* enqueue(PriorityClass<T> newData);
	void dequeue(PriorityClass<T>* data);
	bool isEmpty();
	PriorityClass<T>* get(int i);
	DoublyNode<PriorityClass<T>>* getNode(PriorityClass<T>* data);
	PriorityClass<T>* update(PriorityClass<T>* tarrData, PriorityClass<T> data);
	PriorityClass<T>* update(int i, PriorityClass<T> data);
public:
	int length;
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
int PririorityQueue<T>::search(int l, int r, PriorityClass<T>* x)
{
	if (l > r) {
		return -1;
	}
	int mid = (l + r) / 2;
	if (get(mid)->priority == x->priority) {
		return mid;
	}
	else if (x->priority < get(mid)->priority) {
		search(l, mid - 1, x);
	}
	else {
		search(mid + 1, r, x);
	}
}

template <class T>
PriorityClass<T>* PririorityQueue<T>::enqueue(PriorityClass<T> newData)
{
	DoublyNode<PriorityClass<T>>* newNode = new DoublyNode<PriorityClass<T>>();
	newNode->data = newData;
	this->length++;
	if (this->head) {
		newNode->next = this->head;
		this->head = newNode;
	}
	else {
		this->head = newNode;
		return &(newNode->data);
	}

	for (int i = 0; i < this->length; i++) {
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
	DoublyNode<PriorityClass<T>>* tarrNode =  getNode(data);
	if (tarrNode) {
		DoublyNode<PriorityClass<T>>* prevNode = nullptr;
		DoublyNode<PriorityClass<T>>* nextNode = nullptr;
		// Get left and right nodes
		if (tarrNode->prev) {
			prevNode = tarrNode->prev;
		}
		if (tarrNode->next) {
			nextNode = tarrNode->next;
		}

		if (tarrNode->prev && tarrNode->next) {
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}
		else if (!tarrNode->prev && tarrNode->next) {
			this->head = nextNode;
			nextNode->prev = nullptr;
		}
		else {
			prevNode->next = nullptr;
		}
		this->length--;
		free(tarrNode);
	}
}

template <class T>
bool PririorityQueue<T>::isEmpty()
{
	if (this->length == 0) {
		return true;
	}
	return false;
}

template <class T>
PriorityClass<T>* PririorityQueue<T>::get(int i)
{
	int curr = 0;
	DoublyNode<PriorityClass<T>>* currNode = this->head;
	for (int j = 0; j < this->length; j++) {
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
DoublyNode<PriorityClass<T>>* PririorityQueue<T>::getNode(PriorityClass<T>* data)
{
	int curr = 0;
	DoublyNode<PriorityClass<T>>* currNode = this->head;
	for (int j = 0; j < this->length; j++) {
		if (&(currNode->data) == data) {
			return currNode;
		}
		else {
			currNode = currNode->next;
			curr++;
		}
	}
	return nullptr;
}

template<class T>
PriorityClass<T>* PririorityQueue<T>::update(PriorityClass<T>* tarrData, PriorityClass<T> data)
{
	dequeue(tarrData);
	return enqueue(data);
}

template<class T>
PriorityClass<T>* PririorityQueue<T>::update(int i, PriorityClass<T> data)
{
	PriorityClass<T>* tarrData = get(i);
	if (tarrData) {
		return update(tarrData, data);
	}
	return nullptr;
}


template <class T>
PririorityQueue<T>::PririorityQueue() :length(0)
{
}

template <class T>
PririorityQueue<T>::~PririorityQueue()
{
	if (this->head) {
		delete this->head;
	}
}


