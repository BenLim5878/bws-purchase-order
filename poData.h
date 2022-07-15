#pragma once 
#include "PriorityQueue.h"
#include "PurchaseOrderRepository.h"
#include <iomanip>
#include <iostream>
#include "DataAccess.h"

using namespace std;

namespace poData {
	class Data {
	public:
		void show() {
            auto po = DataAccess::getInstance()->purchaseOrderRepository;
            po->sort(PurchaseOrderPriority::PayMethod, PurchaseOrderArrangement::Decending);
            auto data = po->purchaseOrder;
            for (int i = 0; i < data->length; i++)
            {
                auto record = data->get(i)->content;

                for (int j = 0; j < record.orderedProducts->length; j++) {
                    cout
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(7)
                        << record.getPOID()
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
	};
}