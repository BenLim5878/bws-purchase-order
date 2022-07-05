#pragma once

template <class T> class Node{
public:
	T data;
	Node<T>* next;
};


template <class T> class LinkedList
{
private:
	Node<T>* head = nullptr;
public:
	int length;
public:
	void push(T newData);
	T* get(int i);
	bool contain(T* data);
	int find(T* node);
public:
	LinkedList(T initData);
	~LinkedList();
};

template<class T>
void LinkedList<T>::push(T newData)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = newData;
	Node<T>* currentNode = this->head;
	while (currentNode->next != nullptr) {
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	this->length++;
}

template<class T>
T* LinkedList<T>::get(int i)
{
	if (i >= this->length) return nullptr;
	int target = i;
	int curr = 0;
	Node<T>* currentNode = this->head;
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
bool LinkedList<T>::contain(T* data)
{
	Node<T>* currentNode = this->head;
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

template<class T>
int LinkedList<T>::find(T* node)
{
	int mid = (this->length / 2) - 1;
	Node* currentNode = this->get(mid);
	//binarySearch(mid,currentNode, node);
	return false;
}


template<class T>
LinkedList<T>::LinkedList(T initData) {
	Node<T>* initNode = new Node<T>();
	initNode->data = initData;
	this->head = initNode;
	this->length = 1;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	delete this->head;
}


