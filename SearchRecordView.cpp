#include <iostream>
#include "PurchaseOrderTable.h"
#include "SearchRecordView.h"
#include "Header.h"
#include "DataAccess.h"
#include "Time.h"
#include "PurchaseOrder.h"
#include "PurchaseOrderRepository.h"
#include "PurchaseOrderTable.h"
#include "PriorityQueue.h"
#include "PurchaseOrderView.h"
#include "Helper.h"

using namespace std;

void View::SearchRecordView::show(bool isInputValid)
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
    std::cout << "" << endl;
	std::cout << "B-Back" << endl;
	std::cout << "Press Any Letter or Number to Proceed to Search for Purchase Order Record" << endl;
    std::cout << "Enter: " << endl;
    string back;
    cin >> back;
    cin.ignore();
    if (back == "B") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
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
    int input;
    cin.clear();
    while (true) {
        std::cout << "Please enter the Order ID that you want to search:" << endl;
        std::cout << "Order ID:" << endl;
        
        cin >> input;
        cin.ignore();
        if (cin.fail()) {
            cleanBuffer();
            show(false);
            break;
        }
        else {
            break;
        }
   }


    PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(input);
    PririorityQueue<PurchaseOrder> queue;
    if (data) {
        PriorityClass<PurchaseOrder> priorityClass;
        priorityClass.content = *data;
        priorityClass.priority = 1;
        queue.enqueue(priorityClass);
        ViewComponent::PurchaseOrderTable orderTable(&queue);
        orderTable.show();
    }
    else {
        ViewComponent::PurchaseOrderTable orderTable(&queue);
        orderTable.show();


    }
    system("pause");
    show();

    }

