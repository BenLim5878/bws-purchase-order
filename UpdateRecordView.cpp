#include <iostream>
#include "PurchaseOrderTable.h"
#include "PurchaseOrderRepository.h"
#include "UpdateRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "Payment.h"
#include "Helper.h"
#include "UpdatePurchaseOrderView.h"
#include "UpdateProductView.h"
#include "PurchaseOrderView.h"

using namespace std;

void View::UpdateRecordView::show(bool isValidInput)
{
	system("CLS");
	cin.clear();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();
	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
	poTable.show();

	if (isValidInput) {
		std::cout << "" << endl;
		std::cout << "B-Back" << endl;
		std::cout << "Press Any Letter or Number to Proceed to Update Purchase Record" << endl;
		std::cout << "Enter:";
		string back;
		cin >> back;
		if (back == "B") {
			std::cout << "Are you sure you want to exit? (Y/N): ";
			string decision;
			std::cin >> decision;
			if (decision == "Y") {
				PurchaseOrderView view;
				view.show();
				return;
			}
			else {
				show();
			}
		}
	}

	cout << endl << endl;
	cout << "=======================================================================" << endl;
	std::cout << "Please select which data you want to update: " << endl;
	std::cout << "1-Product (Name, Price, Qty)" << endl;
	std::cout << "2-Purchase Order (Status)" << endl << endl;
	if (isValidInput) {
		std::cout << "Please Select >> ";
	}
	else {
		cout << "Invalid Input. Please try again >> ";
	}

	int selection = promptNumericInput();
	if (selection < 1 || selection > 2) {
		show(false);
		return;
	}

	switch (selection) {
	case 1:
		UpdateProductView view;
		view.show();
		break;
	case 2:
		cout << endl<< "Please enter the Order ID >> ";
		int oid = promptNumericInput();
		if (oid < 0) {
			show(false);
			return;
		}
		UpdatePurchaseOrderView orderView;
		orderView.show(oid);
		break;

	}
}
