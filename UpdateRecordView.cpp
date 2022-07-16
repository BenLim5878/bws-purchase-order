#include <iostream>
#include "PurchaseOrderTable.h"
#include "UpdateRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"

using namespace std;

void View::UpdateRecordView::show()
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

	cout << "" << endl;
	cout << "B-Back" << endl;
	cout << "Please Enter the Order ID: " << endl;
	std::cout << "Enter: " << endl;
	char option;
	cin >> option;
	if (option == 'B') {
		std::cout << "Are you sure you want to exit? (Y/N): " << endl;
		string decision;;
		std::cin >> decision;
		if (decision == "Y") {
			return;
		}
	}

	
		PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(option);
		if (data->getPOID() == option) {
			std::cout << "Please enter the updated status:" << endl;
			std::cout << "Enter: " << endl;
			string ustatus;
			cin >> ustatus;
			//data->orderStatus == ustatus;
	
	


		system("CLS");
	}
}
