#pragma once
#include "IRepository.h"
#include <string>
#include "TextDataReader.h"
#include "PriorityQueue.h"
#include "PurchaseOrder.h"
#include "CategoryOrderDescription.h"
#include <memory>

enum PurchaseOrderArrangement {
	Ascending,
	Decending
};

enum PurchaseOrderPriority {
	ID,
	Latest,
	PayMethod,
	Status,
	TotalItem,
	TotalPrice
};

enum ReportPeriod {
	All,
	Daily,
	Monthly,
	Annually,
};

struct SummaryData {
public:
	float totalAmount = 0;
	int totalPOPlaced = 0;
	int totalIncomingStock = 0;
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
	void updatePurchaseOrder(PurchaseOrder* purchaseOrder);
public:
	static std::unique_ptr<SummaryData> showSummary(PririorityQueue<PurchaseOrder>* poData);
	static std::unique_ptr<PririorityQueue<PurchaseOrder>> getPurchaseOrderByPeriod(PririorityQueue<PurchaseOrder>* poData ,ReportPeriod reportPeriod);
private:
	int getNewPurchaseOrderID();
	long calculatePriority(PurchaseOrder purchaseOrder);
public:
	PurchaseOrderRepository(std::string fileLocation);
	~PurchaseOrderRepository();
};

