#include <iostream>
#include "PurchaseOrderTable.h"
#include "SortRecordView.h"

using namespace std;

void View::SortRecordView::show()
{
	system("CLS");
	cin.ignore();

	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable;
	poTable.show();

	cout << "" << endl;
	cout << "0-Back" << endl;
	cout << "Please select how to want to sort the Order Record:" << endl;
	cout << "1-Ascending" << endl;
	cout << "2-Descending" << endl;
	int option;
	cin >> option;
	system("CLS");
}
