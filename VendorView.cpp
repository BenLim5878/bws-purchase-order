#include <iostream>
#include "Menu.h"
#include "VendorView.h"
#include "VendorTable.h"

using namespace std;

void View::VendorView::show()
{
    system("CLS");
    ViewComponent::VendorTable vTable;
    vTable.show();

    std::cout << "Please enter the Vendor ID to view the vendor details:" << endl;
    int vendorID;
    cin >> vendorID;
}
