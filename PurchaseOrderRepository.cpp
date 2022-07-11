#include "PurchaseOrderRepository.h"
#include <ctime>
#include "Helper.h"
#include <sstream>
#include <ios>
#include "DataAccess.h"


//OrderID, (0)
//DateTimeCreated, (1)
//Product ID, (2)
//Prdouct Quantity, (3)
//TotalPrice, (4)
//PaymentID, (5)
//OrderStatus(6)

LinkedList<ProductOrderDescription>* PurchaseOrderRepository::processProductOrderString(std::string products, std::string quantity) {
	std::stringstream productStream(products);
	std::stringstream quantityStream(quantity);
	std::vector<Product*> productContext;
	std::vector<int> quantityContext;
	std::string segment;
	LinkedList<ProductOrderDescription>* temp = new LinkedList<ProductOrderDescription>();

	ProductRepository* repos = new ProductRepository("Product.txt");
	while (std::getline(productStream, segment, ',')) {
		Product* product = repos->getProduct(std::stoi(segment));
		productContext.push_back(product);
	}
	while (std::getline(quantityStream, segment, ',')) {
		int quantity = std::stoi(segment);
		quantityContext.push_back(quantity);
	}
	for (int i = 0; i < productContext.size(); i++) {
		ProductOrderDescription t;
		t.product = productContext.at(i);
		t.quantity = quantityContext.at(i);
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
		//adsfsdf
		// Purchase Order Status
		temp.orderStatus = static_cast<OrderStatus>(std::stoi(record.at(5)));


		// Create Priority Class
		PriorityClass<PurchaseOrder> priorityClass;
		priorityClass.content = temp;
		// Calculate Priority
		priorityClass.priority = temp.totalPrice;

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
