#include <iostream>
#include "PurchaseOrderTable.h"
#include "SearchRecordView.h"
#include "Header.h"
#include "DataAccess.h"
#include "Time.h"
#include "poData.h"
#include "PurchaseOrderRepository.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "PurchaseOrder.h"

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
	ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
	poTable.show();
    std::cout << "" << endl;
	std::cout << "0-Back" << endl;
	std::cout << "Please Enter the Order ID that you want to search: " << endl;
	int option;
	cin >> option;


    PurchaseOrder* Sdata = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(option);
    /*PririorityQueue<PurchaseOrder>* Sdata = nullptr;*/
    auto searchData = Sdata->purchaseOrder;
   
    for (int i = 0; i < searchData->length; i++)
    {
        auto record = searchData->get(i)->content;

        for (int j = 0; j < record.orderedProducts->length; j++) {
            std::cout
                << left
                << setw(3)
                << ""
                << left
                << setw(7)
                << option
                << left
                << setw(16)
                << record.orderedProducts->get(j)->product->productName
                << left
                << setw(5)
                << record.orderedProducts->get(j)->quantity
                << left
                << setw(22)
                << std::put_time(&record.timeCreated, "%Y-%m-%d.%H:%M:%S")
                << left
                << setw(3)
                << ""
                << left
                << setw(8)
                << record.totalPrice
                << left
                << setw(18)
                << Payment::paymentMethodToString(record.paymentRecord.paymentMethod)
                << left
                << setw(10)
                << PurchaseOrder::orderStatusToString(record.orderStatus)
                << endl;
            if (j == record.orderedProducts->length - 1) {
                cout
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(7)
                    << ""
                    << left
                    << setw(16)
                    << record.orderedProducts->get(j)->product->productName
                    << left
                    << setw(5)
                    << record.orderedProducts->get(j)->quantity
                    << left
                    << setw(22)
                    << put_time(&record.timeCreated, "%Y-%m-%d.%H:%M:%S")
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(8)
                    << record.totalPrice
                    << left
                    << setw(18)
                    << Payment::paymentMethodToString(record.paymentRecord.paymentMethod)
                    << left
                    << setw(10)
                    << PurchaseOrder::orderStatusToString(record.orderStatus)
                    << endl;
            }
        }

    }
        

}
	//std::cout << " " << data->getPOID()<< " | " << data->orderedProducts << " | " << &data->timeCreated << " | " << data->totalPrice << " | " << &data->paymentRecord << " | " << data->vendor << " | " << data->orderStatusToString << endl;


