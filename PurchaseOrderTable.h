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
            
            cout << "=============================================================================" << endl;
            cout
                << left
                << setw(11)
                << " OrderID"
                << left
                << setw(15)
                << "ProductName"
                << left
                << setw(12)
                << "Date"
                << left
                << setw(5)
                << "Qty"
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
            std::cout << "=============================================================================" << endl;
		}
	};
}

