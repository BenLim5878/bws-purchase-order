#pragma once
#include <stddef.h>
#include <cstddef>

template <typename T> class SinglyNode{
public:
	T data;
	SinglyNode<T>* next;
public:
	SinglyNode<T>() {};
	~SinglyNode<T>() {
	}
};

template <typename T> class DoublyNode {
public:
	T data;
	DoublyNode<T>* next;
	DoublyNode<T>* prev;
public:
	DoublyNode<T>() {};
	~DoublyNode<T>() {
	}
};

template <typename T> class LinkedList
{
private:
	SinglyNode<T>* head = nullptr;
private:
	int search(T* x);
	SinglyNode<T>* getNode(int i);
public:
	int length = 0;
public:
	void push(T newData);
	T* get(int i);
	bool contain(T* data);
	int find(T* data);
	T remove(T* data);
	T remove(int i);
	void update(T* currData, T tarrData);
	void update(int i, T tarrData);
public:
	LinkedList();
	LinkedList(T* dataList);
	~LinkedList();
};

template<typename T>
int LinkedList<T>::search(T* x)
{
	SinglyNode<T>* currNode = this->head;
	int curr = 0;
	if (currNode) {
		while (curr < this->length) {
			if (x == &currNode->data) {
				return curr;
			}
			currNode = currNode->next;
			curr++;
		}
	}
	return -1;
}

template<typename T>
SinglyNode<T>* LinkedList<T>::getNode(int i)
{
	if (i >= this->length) return nullptr;
	int target = i;
	int curr = 0;
	SinglyNode<T>* currentNode = this->head;
	while (curr < this->length) {
		if (curr == target) {
			return currentNode;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return nullptr;
}

template<typename T>
void LinkedList<T>::push(T newData)
{
	SinglyNode<T>* newNode = new SinglyNode<T>();
	newNode->data = newData;
	SinglyNode<T>* currentNode = this->head;
	if (!currentNode) {
		this->head = newNode;
	}
	else {
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	this->length++;
}

template<typename T>
T* LinkedList<T>::get(int i)
{
	if (i >= this->length) return nullptr;
	int target = i;
	int curr = 0;
	SinglyNode<T>* currentNode = this->head;
	while (curr < this->length) {
		if (curr == target) {
			return &currentNode->data;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return nullptr;
}


template<typename T>
bool LinkedList<T>::contain(T* data)
{
	SinglyNode<T>* currentNode = this->head;
	int curr = 0;
	while (curr < this->length) {
		if (currentNode->data == data) {
			return true;
		}
		currentNode = currentNode->next;
		curr++;
	}
	return false;
}

template<typename T>
int LinkedList<T>::find(T* data)
{
	int index = search(data);
	return index;
}

template<typename T>
T LinkedList<T>::remove(T* data)
{
	SinglyNode<T>* curr = this->head, *tarr = nullptr;
	int tarrIndex = 0;

	if (&this->head->data == data) {
		tarr = this->head;
		this->head = this->head->next;
		this->length--;
	}
	else {
		// Find previous index of delete node
		for (int i = 0; i < this->length; i++) {
			if (curr->next) {
				if (&curr->next->data == data) {
					tarr = getNode(i + 1);
					tarrIndex = i;
					break;
				}
				curr = curr->next;
			}
			else {
				if (&curr->data == data) {
					tarr = getNode(i);
					tarrIndex = i - 1;
					break;
				}
				else {
					return tarr->data;
				}
			}
		}
		// Get node by previous index
		if (this->length > 0) {
			SinglyNode<T>* prevNode = getNode(tarrIndex);
			if (prevNode->next) {
				if (prevNode->next->next) {
					prevNode->next = prevNode->next->next;
				}
				else {
					prevNode->next = nullptr;
				}
			}
			else {
				prevNode->next = nullptr;
			}
			this->length--;
		}
	}
	T temp = tarr->data;
	delete tarr;
	return temp;
}

template<typename T>
inline T LinkedList<T>::remove(int i)
{
	T tarrContent;
	SinglyNode<T>* tarrNode = getNode(i);

	if (this->length == 0 || !tarrNode){
		T t = 0;
		return t;
	}
	tarrContent = tarrNode->data;
	if (i == 0) {
		if (this->head->next) {
			this->head = this->head->next;
		}
		else {
			this->head = nullptr;
		}
	}
	else {
		SinglyNode<T>* prevNode = getNode(i - 1);
		prevNode->next = nullptr;
		if (tarrNode->next) {
			prevNode->next = tarrNode->next;
		}
		this->length--;
	}

	delete tarrNode;
	return tarrContent;
}

template<typename T>
void LinkedList<T>::update(T* currData, T tarrData)
{
	int tarrIndex= find(currData);
	if (tarrIndex == -1) return;
	SinglyNode<T>* tarrNode = getNode(tarrIndex);
	tarrNode->data = tarrData;
}

template<typename T>
inline void LinkedList<T>::update(int i, T tarrData)
{
	SinglyNode<T>* tarrNode = getNode(i);
	if (!tarrNode) return;
	tarrNode->data = tarrData;
}


template<typename T>
LinkedList<T>::LinkedList() {


}

template<typename T>
inline LinkedList<T>::LinkedList(T* dataList)
{
	int len = sizeof(dataList) / sizeof(dataList[0]);
	for (int i = 0; i < len; i++) {
		push(dataList[i]);
	}
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	if (this->head) {
		delete this->head;
	}
}


