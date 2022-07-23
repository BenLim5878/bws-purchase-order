#include <iostream>
#include "PurchaseOrderTable.h"
#include "SortRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "PurchaseOrderView.h"

using namespace std;

void View::SortRecordView::show()
{
	system("CLS");
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();

    PurchaseOrderPriority priority = PurchaseOrderPriority::ID;
    PurchaseOrderArrangement arrangement = PurchaseOrderArrangement::Ascending;


    cout
        << "================================================"
        << endl
        << "Please select criteria you wish to sort: "
        << endl << endl
        << "1- ID (Default)" << endl
        << "2- Latest" << endl
        << "3- Payment Method" << endl
        << "4- Status" << endl
        << "5- Total Item" << endl
        << "6- Total Price" << endl << endl
        << "Select Option >> ";
    string input;
    cin >> input;
    if (input.length() == 1) {
        priority = static_cast<PurchaseOrderPriority>(stoi(input) - 1);
    }

    cout
        << endl
        << "================================================"
        << endl
        << "Please select order you wish to view: "
        << endl << endl
        << "1- Ascending (Default)" << endl
        << "2- Descending" << endl << endl
        << "Select Option >> ";
    string input2;
    cin >> input2;
    string selection2;
    if (input2.length() == 1) {
        arrangement = static_cast<PurchaseOrderArrangement>(stoi(input2) - 1);
    }
    DataAccess::getInstance()->purchaseOrderRepository->sort(priority, arrangement);
    PurchaseOrderView view;
    view.show();
    return;
}
