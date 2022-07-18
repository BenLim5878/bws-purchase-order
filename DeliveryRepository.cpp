#include "DeliveryRepository.h"
#include "PurchaseOrderRepository.h"
#include "VendorRepository.h"
#include "Helper.h"
#include <vector>
#include <algorithm>

//DeliveryID, (0)
//Delivery Status, (1)
//Purchase Order ID, (2)
//Vendor ID, (3)
//Created At, (4)

void DeliveryRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		Delivery temp;
		// Delivery ID
		temp.setDeliveryID(std::stoi(record.at(0)));
		// Delivery Status
		temp.deliveryStatus = static_cast<DeliveryStatus>(std::stoi(record.at(1)));
		// Delivery Purchase Order
		PurchaseOrderRepository poRepos("PurchaseOrder.txt");
		temp.purchaseOrder = *poRepos.getPurchaseOrder(std::stoi(record.at(2)));
		// Delivery Vendor
		VendorRepository vendorRepos("Vendor.txt");
		temp.vendor = vendorRepos.getVendor(std::stoi(record.at(3)));
		// Delivery Created At
		temp.createdAt = stringToTime(record.at(4));

		this->deliveries->push(temp);
	}
}

Delivery* DeliveryRepository::getDelivery(int deliveryID)
{
	Delivery* t = nullptr;
	for (int i = 0; i < this->deliveries->length; i++) {
		t = this->deliveries->top(i + 1);
		if (t->getDeliveryID() == deliveryID) {
			return t;
		}
	}
	return nullptr;
}

void DeliveryRepository::addDelivery(Delivery delivery)
{
	delivery.setDeliveryID(getNewDeliveryID());
	this->deliveries->push(delivery);
}

Delivery DeliveryRepository::deleteLatestDelivery()
{
	return this->deliveries->pop();
}

int DeliveryRepository::getNewDeliveryID()
{
	if (this->deliveries->length == 0) {
		return 0;
	}
	std::vector<int> ids;
	for (int i = 0; i < this->deliveries->length; i++) {
		ids.push_back(this->deliveries->top(i + 1)->getDeliveryID());
	}
	int max = *std::max_element(ids.begin(), ids.end());
	return  max + 1;
}

DeliveryRepository::DeliveryRepository(std::string fileLocation) :deliveries(new Stack<Delivery>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

DeliveryRepository::~DeliveryRepository()
{
	delete this->dataReader;
	delete this->deliveries;
}
