#include <iostream>
#include "Menu.h"
#include "VendorView.h"
#include "VendorTable.h"
#include "Menu.h"

using namespace std;
int vDecision;
string vDecision2;

void View::VendorView::show()
{
    system("CLS");
    ViewComponent::VendorTable vTable;
    vTable.show();

    std::cout << "0-Back to Menu" << endl;
    std::cout << "Please enter the Vendor ID to view the vendor details:" << endl;
    int vendorID;
    cin >> vendorID;
    
    if (vDecision == 0) {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        cin >> vDecision2;
        if (vDecision2 == "Y") {
            View::Menu menu;
            menu.show();
        }
        else {
            std::cout << "Please enter the Vendor ID to view the vendor details: " << endl;
            cin >> vendorID;
        }
    }
}
