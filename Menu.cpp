#include "Menu.h"
#include <iostream>
#include <Windows.h>
#include "PurchaseOrderView.h"
#include "VendorView.h"
#include "DeliveryView.h"
#include "Header.h"
#include "Time.h"
#include "Session.h"
#include "LoginView.h"
#include "ReportMenuView.h"

using namespace std;


void View::Menu::show()
{
    int selection;
    cin.clear();
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    std::cout << "\n=================== MENU ===================" << endl;
    std::cout << "" << endl;
    do {
        if (Session::getInstance()->loggedUser->role == UserRole::Admin) {
            std::cout << "1-Purchase Order" << endl;
            std::cout << "2-Vendor" << endl;
            std::cout << "3-Report" << endl;
            std::cout << "4-Delivery Order" << endl;
            std::cout << "5-Logout" << endl;
            std::cout << "6-Exit Program" << endl;
            std::cout << "" << endl;
            std::cout << "============================================" << endl;
        }
        else {
            std::cout << "1-Purchase Order" << endl;
            std::cout << "2-Vendor" << endl;
            std::cout << "3-Delivery Order" << endl;
            std::cout << "4-Logout" << endl;
            std::cout << "5-Exit Program" << endl;
            std::cout << "" << endl;
            std::cout << "============================================" << endl;
        }

        cout << "Select Option >> ";
        cin >> selection;
        cin.ignore();
        processInput(selection);

    } while (selection < 1 || selection > 5);
}

void View::Menu::processInput(int selection) {
    if (Session::getInstance()->loggedUser->role == UserRole::Admin)
    {
        switch (selection) {
        case 1:
            PurchaseOrderView poView;
            poView.show();
            return;
            break;
        case 2:
            VendorView venView;
            venView.show();
            return;
            break;
        case 3:
            ReportMenuView reportmenuView;
            reportmenuView.show();
            return;
            break;
        case 4:
            DeliveryView dView;
            dView.show();
            return;
            break;
        case 5:
            Session::getInstance()->deleteSession();
            LoginView view;
            view.show();
            return;
            break;
        case 6:
            system("CLS");
            exit(1);
            break;
        }
    }
    else {
        switch (selection) {
        case 1:
            PurchaseOrderView poView;
            poView.show();
            return;
            break;
        case 2:
            VendorView venView;
            venView.show();
            return;
            break;
        case 3:
            DeliveryView dView;
            dView.show();
            return;
            break;
        case 4:
            Session::getInstance()->deleteSession();
            LoginView view;
            view.show();
            return;
            break;
        case 5:
            system("CLS");
            exit(1);
            break;
        }
    }
}

