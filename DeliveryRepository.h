#pragma once
#include "Delivery.h"
#include "IRepository.h"
#include "LinkedList.h"
#include "TextDataReader.h"
#include "Stack.h"
#include <string>

class DeliveryRepository:public IRepository
{
private:
	virtual void loadData();
private:
	std::string fileLocation;
	TextDataReader* dataReader;
public:
	Stack<Delivery>* deliveries;
public:
	Delivery* getDelivery(int deliveryID);
	void addDelivery(Delivery delivery);
	Delivery deleteLatestDelivery();
private:
	int getNewDeliveryID();
public:
	DeliveryRepository(std::string fileLocation);
	~DeliveryRepository();
};

