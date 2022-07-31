#include "UpdateProductView.h"
#include <iostream>
#include "ProductTable.h"
#include "UpdateRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "Helper.h"

void productName(Product* product) {
	cout << endl;
	cout << "=======================================================================" << endl;
	cout << "Selected fields : Product Name" << endl;
	cout << "Current name: " << product->productName;
	cout << endl << "New name >> ";
	string ss;
	getline(cin, ss);
	product->productName = ss;
	View::UpdateProductView view;
	view.show(true, true);
	return;
}


void pricePerUnit(Product* product) {
	cout << endl;
	cout << "=======================================================================" << endl;
	cout << "Selected fields : Price Per Unit" << endl;
	cout << "Current value: " << product->productPricePerUnit;
	cout << endl << "New value >> ";
	int newVal = promptNumericInput();
	if (newVal < 0) {
		View::UpdateProductView view;
		view.show(false);
		return;
	}
	else {
		product->productPricePerUnit = newVal;
		View::UpdateProductView view;
		view.show(true, true);
	}
}

void quantityPerUnit(Product* product) {
	cout << endl;
	cout << "=======================================================================" << endl;
	cout << "Selected fields : Quantity Per Unit" << endl;
	cout << "Current value: " << product->productQuantityPerUnit;
	cout << endl << "New value >> ";
	int newVal = promptNumericInput();
	if (newVal < 0) {
		View::UpdateProductView view;
		view.show(false);
		return;
	}
	else {
		product->productQuantityPerUnit = newVal;
		View::UpdateProductView view;
		view.show(true, true);
	}
}

void View::UpdateProductView::show(bool isInputValid, bool isCompleted)
{
	system("CLS");
	cin.clear();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();


	ViewComponent::ProductTable productTable(DataAccess::getInstance()->productRepository);
	productTable.show();

	if (isCompleted) {
		cout << endl << endl << "Update successfully! Changes made were saved." << endl;
	}

	if (isInputValid) {
		std::cout << "" << endl;
		std::cout << "B-Back" << endl;
		std::cout << "Press Any Letter or Number to Proceed to Update Product" << endl;
		std::cout << "Enter:";
		string back;
		cin >> back;
		if (back == "B") {
			std::cout << "Are you sure you want to exit? (Y/N): ";
			string decision;
			std::cin >> decision;
			if (decision == "Y") {
				UpdateRecordView view;
				view.show();
				return;
			}
			else {
				show();
			}
		}
	}

	if (isInputValid) {
		cout <<endl << endl<< "Please enter the Product ID >> ";
	}
	else {
		cout << endl << endl<< "Invalid Input. Please try again >> ";
	}
	int pid = promptNumericInput();
	if (pid < 0) {
		show(false);
		return;
	}

	auto product = DataAccess::getInstance()->productRepository->getProduct(pid);

	if (!product) {
		show(false);
		return;
	}

	bool isUpdateProduct = true;

	do {
		cout << endl << endl;
		cout << "=====================================================================" << endl;
		cout << "Please select either of the following fields: " << endl;
		std::cout << "1-Product Name" << endl;
		std::cout << "2-Price Per Unit" << endl;
		std::cout << "3-Quantity Per Unit" << endl;
		cout << "4-Back" << endl;
		cout << endl << "Selection >> ";

		int selection = promptNumericInput();
		if (selection < 1 || selection > 4) {
			show(false);
			return;
		}
		switch (selection)
		{
		case 1:
			productName(product);
			break;
		case 2:
			pricePerUnit(product);
		case 3:
			quantityPerUnit(product);
			break;
		case 4:
			isUpdateProduct = false;
			show();
			break;
		}
	} while (isUpdateProduct);
	return;
}
