#pragma once
#include <string>
#include <ctime>
#include "Product.h"

enum OrderStatus {
	Sent,
	Processing,
	Delivering,
	Completed
};

class PurchaseOrder
{
private:
	int poID;
public:
	time_t timeCreated;
	double totalPrice;
	OrderStatus orderStatus;
	Product* orderedProducts;
public:
	int getPOID();
	void setPOID(int id);
public:
	PurchaseOrder();
	~PurchaseOrder();
};

