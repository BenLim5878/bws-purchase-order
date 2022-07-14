#pragma once
#include <string>
#include <ctime>
#include "Product.h"
#include "LinkedList.h"
#include "Payment.h"
#include "ProductOrderDescription.h"
#include "Vendor.h"

enum OrderStatus {
	Sent,
	Processing,
	Delivering,
	Complete
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
	Payment paymentRecord;
	Vendor* vendor;
public:
	int getPOID();
	void setPOID(int id);
	static std::string orderStatusToString(OrderStatus orderStatus);
public:
	PurchaseOrder();
	~PurchaseOrder();
};

