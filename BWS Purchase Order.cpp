// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "DataAccess.h"
#include "ProductRepository.h"
#include "Helper.h"

using namespace std;

DataAccess* DataAccess::instance = 0;

int main()
{
	DataAccess::getInstance()->purchaseOrderRepository->sort(PurchaseOrderPriority::TotalItem, PurchaseOrderArrangement::Decending);
	PririorityQueue<PurchaseOrder>* t = DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder;
	cout << "fads";

}

// Complete po repos
// Calculate the amount of product in stock in product repos
// Add & Complete delivery repos