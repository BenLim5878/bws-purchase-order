#include <iostream>
#include "PurchaseOrderTable.h"
#include "SearchRecordView.h"
#include "Header.h"
#include "DataAccess.h"
#include "Time.h"
#include "poData.h"

using namespace std;

void View::SearchRecordView::show()
{
	system("CLS");
	cin.ignore();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();
	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable;
	poTable.show();
	poData::Data dTable;
	dTable.show();

	cout << "" << endl;
	cout << "0-Back" << endl;
	cout << "Please Enter the Order ID that you want to search: " << endl;
	int option;
	cin >> option;
	PurchaseOrder*	data =  DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(option);

	std::cout << " " << data->getPOID()<< " | " << data->orderedProducts << " | " << &data->timeCreated << " | " << data->totalPrice << " | " << &data->paymentRecord << " | " << data->vendor << " | " << data->orderStatusToString << endl;

}
