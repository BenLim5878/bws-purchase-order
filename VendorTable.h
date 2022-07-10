#pragma once

#pragma once
#include "PriorityQueue.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {
    class VendorTable
    {
    public:
        void show() {

            cout << "=====================================================================================" << endl;
            cout
                << left
                << setw(15)
                << " VendorID"
                << left
                << setw(15)
                << "Vendor Name"
                << left
                << setw(10)
                << "Status"
                << left
                << setw(30)
                << "Description"
                << left
                << setw(8)
                << "Registered Date"
                << endl;
            std::cout << "=====================================================================================" << endl;
            std::cout << "" << endl;
        }
    };
}


