#include <iostream>
#include "PurchaseOrderTable.h"
#include "SearchRecordView.h"
#include "Header.h"
#include "DataAccess.h"
#include "Time.h"
#include "poData.h"
#include "PurchaseOrder.h"
#include "PurchaseOrderRepository.h"

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
	std::cout << "B-Back" << endl;
	std::cout << "Press Any Letter or Number to Proceed to Add Purchase Record" << endl;
    std::cout << "Enter: " << endl;
    string back;
    cin >> back;
    if (back == "B") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        std::cin >> decision;
        if (decision == "Y") {
            return;
        }
    } 

    std::cout << "Please enter the Order ID that you want to search:" << endl;
    std::cout << "Order ID:" << endl;
    int option;
	cin >> option;
    
    PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(option);
    if (data->getPOID() == option) {
 

            int max_product_string_space = 0;
            for (int i = 0; i < data->getPOID(); i++) {
                for (int j = 0; j < data->orderedProducts->length; j++) {
                    int stringLen = data->orderedProducts->get(j)->product->productName.length();
                    if (max_product_string_space < stringLen) {
                        max_product_string_space = stringLen;
                    }
                }
            }
            cout << "========================================================================================================" << endl;
            cout
                << left
                << setw(10)
                << "OrderID"
                << left
                << setw(2 + max_product_string_space)
                << "ProductName"
                << setw(6)
                << left
                << "Qty"
                << left
                << setw(22)
                << "Time Created"
                << left
                << setw(8)
                << "Price"
                << left
                << setw(18)
                << "PaymentMethod"
                << left
                << setw(10)
                << "Status"
                << endl;
            std::cout << "========================================================================================================" << endl;

            for (int i = 0; i < data->getPOID(); i++)
            {
                int totalProducts = data->orderedProducts->length;
                for (int j = 0; j < totalProducts; j++) {
                    cout
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(7);
                    if (j == 0) {
                        cout <<
                            data->getPOID();
                    }
                    else {
                        cout
                            << "";
                    }
                    cout
                        << left
                        << setw(3 + max_product_string_space)
                        << data->orderedProducts->get(j)->product->productName
                        << left
                        << setw(5)
                        << data->orderedProducts->get(j)->quantity
                        << left
                        << setw(22)
                        << std::put_time(&data->timeCreated, "%Y-%m-%d.%H:%M:%S")
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(8)
                        << (data->orderedProducts->get(j)->product->productPricePerUnit * data->orderedProducts->get(j)->quantity)
                        << left
                        << setw(18)
                        << Payment::paymentMethodToString(data->paymentRecord.paymentMethod)
                        << left
                        << setw(10)
                        << PurchaseOrder::orderStatusToString(data->orderStatus)
                        << endl;
                }

            }
        //for (int i = 0; i < data->getPOID(); i++) {
        //    //std::cout << " " << option << " | " << data->orderedProducts->get(i)->product->productName << " | " << data->orderedProducts->get(i)->quantity << " | " << data->totalPrice << endl;
        //    for (int j = 0; j < data->orderedProducts->length; j++) {
        //        std::cout
        //            << left
        //            << setw(3)
        //            << ""
        //            << left
        //            << setw(7)
        //            << option
        //            << left
        //            << setw(16)
        //            << data->orderedProducts->get(j)->product->productName
        //            << left
        //            << setw(5)
        //            << data->orderedProducts->get(j)->quantity
        //            << left
        //            << setw(22)
        //            << std::put_time(&data->timeCreated, "%Y-%m-%d.%H:%M:%S")
        //            << left
        //            << setw(3)
        //            << ""
        //            << left
        //            << setw(8)
        //            << data->totalPrice
        //            << left
        //            << setw(18)
        //            << Payment::paymentMethodToString(data->paymentRecord.paymentMethod)
        //            << left
        //            << setw(10)
        //            << PurchaseOrder::orderStatusToString(data->orderStatus)
        //            << endl;
        //        if (j == data->orderedProducts->length - 1) {
        //            cout
        //                << left
        //                << setw(3)
        //                << ""
        //                << left
        //                << setw(7)
        //                << ""
        //                << left
        //                << setw(16)
        //                << data->orderedProducts->get(j)->product->productName
        //                << left
        //                << setw(5)
        //                << data->orderedProducts->get(j)->quantity
        //                << left
        //                << setw(22)
        //                << put_time(&data->timeCreated, "%Y-%m-%d.%H:%M:%S")
        //                << left
        //                << setw(3)
        //                << ""
        //                << left
        //                << setw(8)
        //                << data->totalPrice
        //                << left
        //                << setw(18)
        //                << Payment::paymentMethodToString(data->paymentRecord.paymentMethod)
        //                << left
        //                << setw(10)
        //                << PurchaseOrder::orderStatusToString(data->orderStatus)
        //                << endl;
        //        }
        //    }
        //}
    }

    }

        

    //}
        


	


