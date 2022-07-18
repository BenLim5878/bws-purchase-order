#include <iostream>
#include "Menu.h"
#include "VendorView.h"
#include "VendorTable.h"
#include "Menu.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "VendorRepository.h"

using namespace std;


void View::VendorView::show()
{
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();
    // Show the Vendor Table
    ViewComponent::VendorTable vTable(DataAccess::getInstance()->vendorRepository->vendors);
    vTable.show();
    std::cout << "" << endl;
    std::cout << "B-Back to Menu" << endl;
    std::cout << "Enter: ";
    string vDecision;
    string vDecision2;
    cin >> vDecision;
    if (vDecision == "B") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        cin >> vDecision2;
        if (vDecision2 == "Y") {
            View::Menu menu;
            menu.show();
        }
        else {
            View::VendorView::show();
        }
    }
}
