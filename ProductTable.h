#pragma once
#include "DataAccess.h"
#include <iomanip>

using namespace std;

namespace ViewComponent {
    class ProductTable {
    public:
        ProductRepository* data = nullptr;
        ProductTable(ProductRepository* data) {
            this->data = data;
        }

        void show() {

            int max_product_string_space = 0;
            for (int i = 0; i < this->data->getTotalCategory(); i++) {
                auto productCategory = this->data->getProductCategory(i);
                for (int j = 0; j < this->data->getTotalItemByCategory(i); j++) {
                    int stringLen = this->data->getProduct(i, j)->productName.length();
                    if (max_product_string_space < stringLen) {
                        max_product_string_space = stringLen;
                    }
                }
            }

                cout << "==================================================================================================================================================" << endl;
                cout
                    << left
                    << setw(15)
                    << "ProductID"
                    << left
                    << setw(5 + max_product_string_space)
                    << "ProductName"
                    << setw(12)
                    << left
                    << "Brand"
                    << left
                    << setw(12)
                    << "Price"
                    << left
                    << setw(15)
                    << "Status"
                    << left
                    << setw(15)
                    << "QTY Per Unit"
                    << left
                    << setw(22)
                    << "Stock Amount"
                    << left
                    << setw(20)
                    << "Vendor"
                    << endl;
                std::cout << "==================================================================================================================================================" << endl;

                int totalStockCategory = 0, totalStockAmount = 0;
                float totalInventoryCost = 0;
                for (int i = 0; i < this->data->getTotalCategory(); i++) {
                    auto productCategory = this->data->getProductCategory(i);
                    totalStockCategory++;
                    cout <<
                        productCategory->categoryTitle << endl;
                    if (this->data->getTotalItemByCategory(productCategory->categoryID) == 0) {
                        cout
                            << "No item is available in this category" << endl;
                    }
                    for (int j = 0; j < this->data->getTotalItemByCategory(i); j++) {
                        auto product = this->data->getProduct(i, j);
                        int stockAmount = this->data->getProductStockAmount(product->getProductID());
                        totalStockAmount += stockAmount;
                        totalInventoryCost += (stockAmount * product->productPricePerUnit);
                        cout
                            << left
                            << setw(5)
                            << ""
                            << left
                            << setw(10)
                            << product->getProductID()
                            << left
                            << setw(5 + max_product_string_space)
                            << product->productName
                            << left
                            << setw(12)
                            << product->productBrand
                            << left
                            << setw(12)
                            << product->productPricePerUnit
                            << left
                            << setw(20)
                            << Product::productStatusToString(product->productStatus)
                            << left
                            << setw(15)
                            << product->productQuantityPerUnit
                            << left
                            << setw(12)
                            << stockAmount
                            << left
                            << setw(12)
                            << product->productVendor->vendorName
                            << endl;
                    }
                    cout << endl;
                }
                std::cout << "=================================" << endl;
                std::cout << "Inventory Summary" << endl;
                std::cout << "=================================" << endl;

                std::cout << "Current Inventory Cost : RM " << totalInventoryCost << endl;
                std::cout << "Total Stock Amount: " << totalStockAmount << endl;
                std::cout << "Total Product Category: " << totalStockCategory << endl;
            }
        };

}
