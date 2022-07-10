#pragma once

#pragma once
#include "PriorityQueue.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {
    class DeliveryTable
    {
    public:
        void show() {

            std::cout << "=============================================" << endl;
            cout
                << left
                << setw(18)
                << " Delivery ID"
                << left
                << setw(10)
                << "Status"
                << left
                << setw(12)
                << "Order ID"
                << left
                << setw(12)
                << "Date"
                << endl;
            std::cout << "=============================================" << endl;
            std::cout << "" << endl;
        }
    };
}


