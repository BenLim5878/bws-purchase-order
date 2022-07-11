// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Tree.h"
#include "ProductRepository.h"
#include "Menu.h"
#include "DataAccess.h"
#include "ProductRepository.h"
#include "Helper.h"

using namespace std;

DataAccess* DataAccess::instance = 0;

int main()
{
	ProductRepository* repos = new ProductRepository("Product.txt");
	Product* sample =  repos->getProduct(0, 0);
	repos->deleteProduct(sample);
	int total = repos->getTotalItem();
	Product* haha = repos->getProduct(0,0);

	DataAccess::getInstance()->purchaseOrderRepository->sort(PurchaseOrderPriority::TotalItem, PurchaseOrderArrangement::Decending);
	PririorityQueue<PurchaseOrder>* t = DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder;
	cout << "fads";

}

// Complete po repos
// Calculate the amount of product in stock in product repos
// Add & Complete delivery repos