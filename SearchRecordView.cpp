#include <iostream>
#include "PurchaseOrderTable.h"
#include "SearchRecordView.h"
#include "Header.h"
#include "Time.h"

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

	cout << "" << endl;
	cout << "0-Back" << endl;
	cout << "Please Enter the Order ID that you want to search: " << endl;
	int option;
	cin >> option;
	system("CLS");
}
