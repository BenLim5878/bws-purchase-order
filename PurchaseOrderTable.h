#pragma once
#include "PriorityQueue.h"
#include "PurchaseOrderRepository.h"
#include <iomanip>
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

namespace ViewComponent {

	class PurchaseOrderTable
	{
	public:
        PririorityQueue<PurchaseOrder>* data = nullptr;
        PurchaseOrderTable(PririorityQueue<PurchaseOrder>* data) {
            this->data = data;
        };
		void show() {

            int max_product_string_space = 0;
            for (int i = 0; i < this->data->length; i++) {
                auto record = this->data->get(i)->content;
                for (int j = 0; j < record.orderedProducts->length; j++) {
                    int stringLen = record.orderedProducts->get(j)->product->productName.length();
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
                << setw(2+ max_product_string_space)
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

            for (int i = 0; i < this->data->length; i++)
            {
                auto record = this->data->get(i)->content;
                int totalProducts = record.orderedProducts->length;
                for (int j = 0; j < totalProducts; j++) {
                    cout
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(7);
                    if (j == 0) {
                        cout <<
                            record.getPOID();
                    }
                    else {
                        cout
                            << "";
                    }
                    cout
                        << left
                        << setw(3 + max_product_string_space)
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
                        << (record.orderedProducts->get(j)->product->productPricePerUnit * record.orderedProducts->get(j)->quantity)
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
	};
}

