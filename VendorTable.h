#pragma once
#include "LinkedList.h"
#include "VendorRepository.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {

    class VendorTable
    {
    public:
        LinkedList<Vendor>* data = nullptr;
        VendorTable(LinkedList<Vendor>* data) {
            this->data = data;
        };
        void show() {

            int max_product_string_space = 0;
            for (int i = 0; i < this->data->length; i++) {
                auto record = this->data->get(i);
            }


            cout << "==============================================================================================================" << endl;
            cout
                << left
                << setw(10)
                << "Vendor ID"
                << left
                << setw(30)
                << "Name"
                << left
                << setw(36)
                << "Description"
                << left
                << setw(22)
                << "Date Registered"
                << setw(8)
                << "Status"
                << endl;
            std::cout << "==============================================================================================================" << endl;

            for (int i = 0; i < this->data->length; i++)
            {
                auto record = this->data->get(i);
                cout
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(7)
                    << record->getVendorID()
                    << left
                    << setw(30)
                    << record->vendorName
                    << left
                    << setw(36)
                    << record->vendorDescription
                    << left
                    << setw(22)
                    << std::put_time(&record->vendorRegisteredDate, "%Y-%m-%d.%H:%M:%S")
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(8)
                    << Vendor::vendorStatusToString(record->vendorStatus)
                    << endl;
            }

        }
    };
}

