#include <iostream>
#include "PurchaseOrderTable.h"
#include "SortRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"

using namespace std;

void View::SortRecordView::show()
{
	system("CLS");
	cin.ignore();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();
	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
	poTable.show();
	std::cout << "" << endl;
	std::cout << "B-Back" << endl;
	std::cout << "Press Any Letter or Number to Proceed to Select Sorting Selection" << endl;
	std::cout << "Enter: " << endl;
	string back;
	cin >> back;
	if (back == "B") {
		std::cout << "Are you sure you want to exit? (Y/N): " << endl;
		string decision;;
		std::cin >> decision;
		if (decision == "Y") {
			return;
		}
	}

	auto sortpo = DataAccess::getInstance()->purchaseOrderRepository;
	auto data = sortpo->purchaseOrder;

	cout << "" << endl;
	cout << "Please select how to want to sort the Order Record:" << endl;
	cout << "1-Ascending" << endl;
	cout << "2-Descending" << endl;
	cout << "Enter: ";
	int option;
	cin >> option;
	switch (option) {
	case 1:
		sortpo->sort(PurchaseOrderPriority::ID, PurchaseOrderArrangement::Ascending);
		break;
	case 2: 
		sortpo->sort(PurchaseOrderPriority::ID, PurchaseOrderArrangement::Decending);
		break;
	}
}
