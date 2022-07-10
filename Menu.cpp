#include "Menu.h"
#include <iostream>
#include "PurchaseOrderView.h"

using namespace std;

void View::Menu::show()
{
    int selection;
    cout << "\n=================== MENU ===================" << endl;
    system("CLS");
    do {
        cout << "1-Purchase Order" << endl;
        cout << "2-Vendor Order" << endl;
        cout << "3-Report" << endl;
        cout << "4-Delivery Order" << endl;
        cout << "5-Logout" << endl;
        cout << "6-Exit Program" << endl;
        cout << "********************************************" << endl;

        cout << "Select Option >>" << endl;
        cin >> selection;
        processInput(selection);


    } while (selection < 1 && selection > 5);
}

void View::Menu::processInput(int selection) {
    switch (selection) {
    case 1:
        PurchaseOrderView poView;
        poView.show();
        break;
    case 2:
        //VendorOrder();
        break;
    case 3:
        //Report();
        break;
    case 4:
        //DeliveryOrder();
        break;
    case 5:
        //Logout();
        break;
    }
}