#pragma once
#include "ProductRepository.h"
#include "PurchaseOrderRepository.h"
#include "UserRepository.h"

class DataAccess {
public:
	ProductRepository* productRepository;
	PurchaseOrderRepository* purchaseOrderRepository;
	UserRepository* userRepository;
public:
	static DataAccess* getInstance();
private:
	DataAccess();
	static DataAccess* instance;
};