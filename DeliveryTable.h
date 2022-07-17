#pragma once
#include "Stack.h"
#include "DeliveryRepository.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {

    class DeliveryTable
    {
    public:
        Stack<Delivery>* data = nullptr;
        DeliveryTable(Stack<Delivery>* data) {
            this->data = data;
        };
        void show() {

            int max_product_string_space = 0;
            for (int i = 0; i < this->data->length; i++) {
                auto record = this->data->get(i);
                for (int j = 0; j < record->purchaseOrder->orderedProducts->length; j++) {
                    int stringLen = record->purchaseOrder->orderedProducts->get(j)->product->productName.length();
                    if (max_product_string_space < stringLen) {
                        max_product_string_space = stringLen;
                    }
                }
            }

            cout << "========================================================================================================" << endl;
            cout
                << left
                << setw(1)
                << ""
                << left
                << setw(14)
                << "Delivery ID"
                << left
                << setw(3 + max_product_string_space)
                << "Product Name"
                << left
                << setw(10)
                << "Order ID"
                << left
                << setw(22)
                << "Date Registered"
                << setw(8)
                << "Status"
                << endl;
            std::cout << "========================================================================================================" << endl;

            for (int i = 0; i < this->data->length; i++)
            {
                auto record = this->data->get(i);
                int totalProducts = record->purchaseOrder->orderedProducts->length;
                for (int j = 0; j < totalProducts; j++) {
                    cout
                        << left
                        << setw(5)
                        << ""
                        << left
                        << setw(10);
                    if (j == 0) {
                        cout <<
                            record->getDeliveryID();
                    }
                    else {
                        cout
                            << "";
                    }
                    cout
                        << left
                        << setw(3 + max_product_string_space)
                        << record->purchaseOrder->orderedProducts->get(j)->product->productName
                        << left
                        << setw(10)
                        << record->purchaseOrder->getPOID()
                        << left
                        << setw(22)
                        << std::put_time(&record->createdAt, "%Y-%m-%d.%H:%M:%S")
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(8)
                        << Delivery::deliveryStatusToString(record->deliveryStatus)
                        << endl;
                }

            }
        }
    };
}

