#include "PurchaseOrderRepository.h"
#include <ctime>
#include "Helper.h"
#include <sstream>
#include <ios>
#include "DataAccess.h"
#include "PaymentRepository.h"
#include "VendorRepository.h"
#include <algorithm>

//OrderID, (0)
//DateTimeCreated, (1)
//Product ID, (2)
//Prdouct Quantity, (3)
//TotalPrice, (4)
//PaymentID, (5)
//OrderStatus (6)
//Vendor (7)

LinkedList<ProductOrderDescription>* PurchaseOrderRepository::processProductOrderString(std::string products, std::string quantity) {
	std::stringstream productStream(products);
	std::stringstream quantityStream(quantity);
	std::string segment1, segment2;
	LinkedList<ProductOrderDescription>* temp = new LinkedList<ProductOrderDescription>();

	ProductRepository* repos = new ProductRepository("Product.txt");
	while (std::getline(productStream, segment1, ',') && std::getline(quantityStream, segment2, ',')) {
		Product* product = repos->getProduct(std::stoi(segment1));
		int quantity = std::stoi(segment2);
		ProductOrderDescription t;
		t.product = product;
		t.quantity = quantity;
		temp->push(t);
	}
	delete repos;
	return temp;
}

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
		// Purchase Order Description
		LinkedList<ProductOrderDescription>* productOrderDescription = processProductOrderString(record.at(2), record.at(3));
		temp.orderedProducts = productOrderDescription;
		// Purchase Order Total Price
		temp.totalPrice = std::stoll(record.at(4));
		// Purchase Order Payment ID
		PaymentRepository paymentRepos("Payment.txt");
		temp.paymentRecord= *paymentRepos.getPayment(std::stoi(record.at(5)));
		// Purchase Order Status
		temp.orderStatus = static_cast<OrderStatus>(std::stoi(record.at(6)));
		// Purchase Order Vendor
		VendorRepository vendorRepos("Vendor.txt");
		temp.vendor = vendorRepos.getVendor(std::stoi(record.at(7)));

		// Create Priority Class
		PriorityClass<PurchaseOrder> priorityClass;
		priorityClass.content = temp;
		// Calculate Priority
		priorityClass.priority = calculatePriority(temp);

		// Push Priority Class to Priority Queue
		this->purchaseOrder->enqueue(priorityClass);
	}
}

PurchaseOrder* PurchaseOrderRepository::getPurchaseOrder(int purchaseOrderID)
{
	PriorityClass<PurchaseOrder>* t = nullptr;
	for (int i = 0; i < this->purchaseOrder->length; i++) {
		t = this->purchaseOrder->get(i);
		if (t->content.getPOID() == purchaseOrderID) {
			return &t->content;
		}
	}
	return nullptr;
}

void PurchaseOrderRepository::addPurchaseOrder(PurchaseOrder purchaseOrder)
{
	PriorityClass<PurchaseOrder> temp;
	temp.priority = calculatePriority(purchaseOrder);
	if (!purchaseOrder.getPOID()) {
		purchaseOrder.setPOID(getNewPurchaseOrderID());
	}
	temp.content = purchaseOrder;
	this->purchaseOrder->enqueue(temp);
}



void PurchaseOrderRepository::deletePurchaseOrder(int purchaseOrderID)
{
	PriorityClass<PurchaseOrder>* tClass = nullptr;
	PurchaseOrder tContent;
	for (int i = 0; i < this->purchaseOrder->length; i++) {
		PriorityClass<PurchaseOrder>* t = this->purchaseOrder->get(i);
		if (t->content.getPOID() == purchaseOrderID) {
			this->purchaseOrder->dequeue(t);
			return;
		}
	}
}

void PurchaseOrderRepository::sort(PurchaseOrderPriority criteria, PurchaseOrderArrangement arrangement)
{
	this->sortCriteria = criteria;
	this->arrangement = arrangement;
	PririorityQueue<PurchaseOrder>* temp = new PririorityQueue<PurchaseOrder>();
	for (int i = 0; i < this->purchaseOrder->length;i++) {
		PriorityClass<PurchaseOrder>* tPriorityClass = this->purchaseOrder->get(i);
		tPriorityClass->priority = calculatePriority(tPriorityClass->content);
		temp->enqueue(*tPriorityClass);
	}
	delete this->purchaseOrder;
	this->purchaseOrder = temp;
}

void PurchaseOrderRepository::updatePurchaseOrder(PurchaseOrder* purchaseOrder)
{
	PurchaseOrder* temp = new PurchaseOrder(*purchaseOrder);
	deletePurchaseOrder(purchaseOrder->getPOID());
	addPurchaseOrder(*temp);
}

int PurchaseOrderRepository::getNewPurchaseOrderID()
{
	if (this->purchaseOrder->length == 0) {
		return 0;
	}
	std::vector<int> ids;
	for (int i = 0; i < this->purchaseOrder->length; i++) {
		ids.push_back(this->purchaseOrder->get(i)->content.getPOID());
	}
	int max = *std::max_element(ids.begin(), ids.end());
	return  max + 1;
}

long PurchaseOrderRepository::calculatePriority(PurchaseOrder purchaseOrder)
{
	switch (this->sortCriteria)
	{
	case PurchaseOrderPriority::TotalPrice:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return purchaseOrder.totalPrice;
		}
		else {
			return -purchaseOrder.totalPrice + std::numeric_limits<int>::max();
		}
		break;
	}
	case PurchaseOrderPriority::TotalItem:
	{
		int totalItem = 0;
		for (int i = 0; i < purchaseOrder.orderedProducts->length;i++) {
			ProductOrderDescription* orderDesc = purchaseOrder.orderedProducts->get(i);
			totalItem += orderDesc->quantity;
		}
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return totalItem;
		}
		else {
			return -totalItem + std::numeric_limits<int>::max();
		}
		break;
	}
	case PurchaseOrderPriority::Latest:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return mktime(&purchaseOrder.timeCreated);
		}
		else {
			return -mktime(&purchaseOrder.timeCreated);

			break;
		}
	}
	case PurchaseOrderPriority::ID:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return std::numeric_limits<int>::max() - 1 - purchaseOrder.getPOID();
		}
		else {
			return purchaseOrder.getPOID();
			break;
		}
	}
	case PurchaseOrderPriority::Status:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return purchaseOrder.orderStatus;
		}
		else {
			return std::numeric_limits<int>::max() - 1 - purchaseOrder.orderStatus;
			break;
		}
	}
	case PurchaseOrderPriority::PayMethod:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return purchaseOrder.paymentRecord.paymentMethod;
		}
		else {
			return std::numeric_limits<int>::max() - 1 - purchaseOrder.paymentRecord.paymentMethod;
			break;
		}
	}
	default:
	{
		if (this->arrangement == PurchaseOrderArrangement::Ascending) {
			return purchaseOrder.totalPrice;
		}
		else {
			return -purchaseOrder.totalPrice;
		}
		break;
	}
	}
}

PurchaseOrderRepository::PurchaseOrderRepository(std::string fileLocation):purchaseOrder(new PririorityQueue<PurchaseOrder>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
	this->sortCriteria = PurchaseOrderPriority::TotalPrice;
	this->arrangement = PurchaseOrderArrangement::Ascending;
}

PurchaseOrderRepository::~PurchaseOrderRepository()
{
	delete this->purchaseOrder;
	delete this->dataReader;
}
