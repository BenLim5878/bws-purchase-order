#include "StockInventoryReportView.h"
#include <Windows.h>
#include <iostream>
#include "Time.h"
#include "Header.h"
#include "DataAccess.h"
#include <iomanip>

using namespace std;

void View::StockInventoryReportView::show()
{
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();


    cout << "===========================================================================================================================================" << endl;
    cout
        << left
        << setw(15)
        << "ProductID"
        << left
        << setw(18)
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
    std::cout << "===========================================================================================================================================" << endl;

    auto productRepos = DataAccess::getInstance()->productRepository;
    for (int i = 0; i < productRepos->getTotalCategory(); i++) {
        auto productCategory = productRepos->getProductCategory(i);
        totalStockCategory++;
        cout <<
            productCategory->categoryTitle << endl;
        if (productRepos->getTotalItemByCategory(productCategory->categoryID) == 0) {
            cout
                <<"No item is available in this category" << endl;
        }
        for (int j = 0; j < productRepos->getTotalItemByCategory(i); j++) {
            auto product = productRepos->getProduct(i, j);
            int stockAmount = productRepos->getProductStockAmount(product->getProductID());
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
                << setw(18)
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
    cout << "Current Inventory Cost : RM " << totalInventoryCost << endl;
    cout << "Total Stock Amount: " << totalStockAmount << endl;
    cout << "Total Product Category: " << totalStockCategory << endl;
}
