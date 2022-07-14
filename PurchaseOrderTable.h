#pragma once
#include "PriorityQueue.h"
#include "PurchaseOrderRepository.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {

	class PurchaseOrderTable
	{
	public:
		void show() {
            
            cout << "========================================================================================" << endl;
            cout
                << left
                << setw(10)
                << "OrderID"
                << left
                << setw(15)
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
            std::cout << "========================================================================================" << endl;
		}
	};
}

