#include <iostream>
#include "PurchaseOrderTable.h"
#include "UpdateRecordView.h"

using namespace std;

void View::UpdateRecordView::show()
{
	system("CLS");
	cin.ignore();

	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable;
	poTable.show();

	cout << "" << endl;
	cout << "0-Back" << endl;
	cout << "Please Enter the Order ID: " << endl;
	int option2;
	cin >> option2;
	system("CLS");
}
