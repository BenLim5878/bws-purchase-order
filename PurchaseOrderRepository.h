#pragma once
#include "IRepository.h"
#include <string>
#include "TextDataReader.h"
#include "PriorityQueue.h"
#include "PurchaseOrder.h"

class PurchaseOrderRepository:public IRepository
{
private:
	virtual void loadData();
private:
	LinkedList<ProductOrderDescription>* processProductOrderString(std::string products, std::string quantity);
private:
	std::string fileLocation;
	TextDataReader* dataReader;
public:
	PririorityQueue<PurchaseOrder>* purchaseOrder;
public:
	PurchaseOrderRepository(std::string fileLocation);
	~PurchaseOrderRepository();
};

