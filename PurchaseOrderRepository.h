#pragma once
#include "IRepository.h"
#include <string>
#include "TextDataReader.h"
#include "PriorityQueue.h"
#include "PurchaseOrder.h"
#include <memory>

enum PurchaseOrderArrangement {
	Ascending,
	Decending
};

enum PurchaseOrderPriority {
	TotalPrice,
	Latest,
	TotalItem,
	ID,
	Status,
	PayMethod
};

enum ReportPeriod {
	Daily,
	Monthly,
	Annually
};


class PurchaseOrderRepository:public IRepository
{
private:
	virtual void loadData();
private:
	LinkedList<ProductOrderDescription>* processProductOrderString(std::string products, std::string quantity);
private:
	std::string fileLocation;
	TextDataReader* dataReader;
	PurchaseOrderPriority sortCriteria;
	PurchaseOrderArrangement arrangement;
public:
	PririorityQueue<PurchaseOrder>* purchaseOrder;
public:
	PurchaseOrder* getPurchaseOrder(int purchaseOrderID);
	void addPurchaseOrder(PurchaseOrder purchaseOrder);
	void deletePurchaseOrder(int purchaseOrderID);
	void sort(PurchaseOrderPriority criteria, PurchaseOrderArrangement arrangement);
	std::unique_ptr<PririorityQueue<PurchaseOrder>> getPurchaseOrderByPeriod(ReportPeriod reportPeriod);
	void updatePurchaseOrder(PurchaseOrder* purchaseOrder);
private:
	int getNewPurchaseOrderID();
	long calculatePriority(PurchaseOrder purchaseOrder);
public:
	PurchaseOrderRepository(std::string fileLocation);
	~PurchaseOrderRepository();
};

