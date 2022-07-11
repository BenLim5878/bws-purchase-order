// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "DataAccess.h"

using namespace std;

DataAccess* DataAccess::instance = 0;

int main()
{
	PririorityQueue<PurchaseOrder>* t = DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder;



	cout << "fasdf";
}


// Add & Complete payment repos
// Add & Complete vendor repos
// Complete po repos
// Add & Complete delivery repos