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
	cout << "0-Back" << endl;
	cout << "Please Enter the Order ID: " << endl;
	int option;
	cin >> option;
	system("CLS");
}
