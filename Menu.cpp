#include "Menu.h"
#include <iostream>
#include <Windows.h>
#include "PurchaseOrderView.h"
#include "VendorView.h"
#include "DeliveryView.h"
#include "Header.h"
#include "Time.h"

using namespace std;


void View::Menu::show()
{
    int selection;

    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();
    cout << "\n=================== MENU ===================" << endl;
    do {
        cout << "1-Purchase Order" << endl;
        cout << "2-Vendor" << endl;
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
        VendorView venView;
        venView.show();
        break;
    case 3:
        //Report();
        break;
    case 4:
        DeliveryView dView;
        dView.show();
        break;
    case 5:
        //Logout();
        break;
    }
}

