#pragma once
#include "ProductRepository.h"
#include "PurchaseOrderRepository.h"
#include "UserRepository.h"
#include "PaymentRepository.h"
#include "VendorRepository.h"
#include "DeliveryRepository.h"

class DataAccess {
public:
	ProductRepository* productRepository;
	PurchaseOrderRepository* purchaseOrderRepository;
	UserRepository* userRepository;
	PaymentRepository* paymentRepository;
	VendorRepository* vendorRepository;
	DeliveryRepository* deliveryRepository;
public:
	static DataAccess* getInstance();
private:
	DataAccess();
	static DataAccess* instance;
};