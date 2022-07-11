// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Tree.h"
#include "ProductRepository.h"
#include "DataAccess.h"
#include "Menu.h"

using namespace std;

DataAccess* DataAccess::instance = 0;

int main()
{
	ProductRepository* repos = new ProductRepository("Product.txt");
	Product* sample =  repos->getProduct(0, 0);
	repos->deleteProduct(sample);
	int total = repos->getTotalItem();
	Product* haha = repos->getProduct(0,0);


	cout << "fasdf";
	View::Menu menu;
	menu.show();

}


// Add & Complete payment repos
// Add & Complete vendor repos
// Complete po repos
// Add & Complete delivery repos