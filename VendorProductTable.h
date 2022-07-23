#pragma once
#include "PriorityQueue.h"
#include "DataAccess.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace ViewComponent {

    class VendorProductTable
    {
    public:
        int vendorID;
        VendorProductTable(int vendorID) {
            this->vendorID = vendorID;
        };
        void show() {

            auto list = DataAccess::getInstance()->vendorRepository->getProductByVendor(this->vendorID);


            int max_product_string_space = 0;
            int max_product_brand_string_space = 0;
            for (int i = 0; i < list->length; i++) {
                int stringLen = list->get(i)->productName.length();
                int stringLen2 = list->get(i)->productBrand.length();
                if (max_product_string_space < stringLen) {
                    max_product_string_space = stringLen;
                }
                if (max_product_brand_string_space < stringLen2) {
                    max_product_brand_string_space = stringLen2;
                }
            }


            cout << "============================================================================================================================" << endl;
            cout
                << left
                << setw(11)
                << "ProductID"
                << left
                << setw(5 + max_product_string_space)
                << "ProductName"
                << left
                << setw(5 + max_product_brand_string_space)
                << "Brand"
                << left
                << setw(12)
                << "Price"
                << left
                << setw(15)
                << "QTY Per Unit"
                << endl;
            std::cout << "============================================================================================================================" << endl;

            if (list->length > 0) {
                for (int i = 0; i < list->length; i++)
                {
                    auto record = list->get(i);
                    cout
                        << left
                        << setw(3)
                        << ""
                        << left
                        << setw(11)
                        << record->getProductID()
                        << left
                        << setw(5 + max_product_string_space)
                        << record->productName
                        << left
                        << setw(5 + max_product_brand_string_space)
                        << record->productBrand
                        << left
                        << setw(12)
                        << record->productPricePerUnit
                        << left
                        << setw(15)
                        << record->productQuantityPerUnit
                        << endl;
                }
            }
            else {
                cout << "No product has been found..." << endl << endl;
            }

        }
    };
}

