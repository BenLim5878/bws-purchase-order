#include "UpdatePurchaseOrderView.h"
#include <iostream>
#include "PurchaseOrderTable.h"
#include "PurchaseOrderRepository.h"
#include "UpdateRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "Helper.h"


using namespace std;

void View::UpdatePurchaseOrderView::show(int poID,bool isInputValid, bool isCompleted)
{
	system("CLS");
	cin.clear();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();

	// Show the Purchase Order Table
	auto po = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(poID);
	if (!po) {
		UpdateRecordView view;
		view.show();
		return;
	}
	PriorityClass<PurchaseOrder> poClass;
	poClass.content = *po;
	poClass.priority = 1;
	PririorityQueue<PurchaseOrder> queue;
	queue.enqueue(poClass);
	ViewComponent::PurchaseOrderTable poTable(&queue);
	poTable.show();

	if (isCompleted) {
		cout << "" << endl;
		cout << "Status Update Successfully!" << endl;
	}

	if (isInputValid) {
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
				UpdateRecordView view;
				view.show();
				return;
			}
			else {
				show(poID);
			}
		}
	}
	cout <<endl << "Current Purchase Order Status: " << PurchaseOrder::orderStatusToString(po->orderStatus) << endl << endl;
	cout << "=======================================================================" << endl;
	cout << "Please select either of the following options: " << endl;
	std::cout << "1-Sent" << endl;
	std::cout << "2-Processing" << endl;
	std::cout << "3-Delivering" << endl;
	std::cout << "4-Complete" << endl<< endl;
	if (isInputValid) {
		cout << "Selection >> ";
	}
	else {
		cout << "Invalid Input. Please try again >> ";

	}

	int selection = promptNumericInput();
	if (selection < 1 || selection > 4) {
		show(poID, false);
		return;
	}
	po->orderStatus = static_cast<OrderStatus>(selection - 1);
	show(poID, true, true);
	return;
}
