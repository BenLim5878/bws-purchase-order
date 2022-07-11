#include "DataAccess.h"

DataAccess* DataAccess::getInstance()
{
	if (instance == 0) {
		instance = new DataAccess();
	}
	return instance;
}

DataAccess::DataAccess() {
	this->productRepository = new ProductRepository("Product.txt");
	this->purchaseOrderRepository = new PurchaseOrderRepository("PurchaseOrder.txt");
	this->userRepository = new UserRepository("User.txt");
}