#pragma once
#include <string>
#include <ctime>
#include "Product.h"
#include "LinkedList.h"
#include "Payment.h"
#include "ProductOrderDescription.h"

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
	tm timeCreated;
	double totalPrice;
	OrderStatus orderStatus;
	LinkedList<ProductOrderDescription>* orderedProducts = nullptr;
	Payment* paymentRecord;
public:
	int getPOID();
	void setPOID(int id);
public:
	PurchaseOrder();
	~PurchaseOrder();
};

