// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Tree.h"
#include "ProductRepository.h"
#include "Menu.h"
#include "Header.h"

using namespace std;

int main()
{

	ProductRepository* repos = new ProductRepository("Product.txt");
	Product* sample =  repos->getProduct(0, 0);
	repos->deleteProduct(sample);
	int total = repos->getTotalItem();
	Product* haha = repos->getProduct(0,0);


	delete repos;
	cout << "fasdf";

	View::Menu menu;
	menu.show();
}
