#pragma once
#include "Vendor.h"
#include "PurchaseOrder.h"

enum DeliveryStatus {
	Shipping,
	Delivered
};

class Delivery
{
private:
	int deliveryID;
public:
	DeliveryStatus deliveryStatus;
	PurchaseOrder* purchaseOrder;
	Vendor* vendor;
	tm createdAt;
public:
	int getDeliveryID();
	void setDeliveryID(int deliveryID);
};

