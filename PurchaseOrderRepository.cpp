#include "PurchaseOrderRepository.h"
#include <ctime>
#include "Helper.h"

//OrderID, (0)
//DateTimeCreated, (1)
//Product ID, (2)
//Prdouct Quantity, (3)
//TotalPrice, (4)
//PaymentID, (5)
//OrderStatus(6)

void PurchaseOrderRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		PurchaseOrder temp;
		// Purchase Order ID
		temp.setPOID(std::stoi(record.at(0)));
		// Purchase Order Time Created
		tm currTime = stringToTime(record.at(1));
		temp.timeCreated = currTime;
		// Purchase Order Product ID
		
		// Create Priority Class
		PriorityClass<PurchaseOrder> priorityClass;
		priorityClass.content = temp;
		priorityClass.priority = 10;

		// Push Priority Class to Priority Queue
		PriorityClass<PurchaseOrder>* res =  this->purchaseOrder->enqueue(priorityClass);
	}
}

PurchaseOrderRepository::PurchaseOrderRepository(std::string fileLocation):purchaseOrder(new PririorityQueue<PurchaseOrder>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

PurchaseOrderRepository::~PurchaseOrderRepository()
{
	delete this->purchaseOrder;
	delete this->dataReader;
}
