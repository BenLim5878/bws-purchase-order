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
#include "Helper.h"

using namespace std;


void View::Menu::show(bool isValidInput)
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

    if (isValidInput) {
        cout << "Select Option >> ";
    }
    else {
        cout << "Invalid Option. Please try again >> ";
    }

    selection = promptNumericInput();
    if (selection < 0) {
        show(false);
    }
    else {
        if (Session::getInstance()->loggedUser->role == UserRole::Admin) {
            if (selection > 0 && selection < 7) {
                processInput(selection);
            }
            else {
                show(false);
            }
        }
        else {
            if (selection > 0 && selection < 6) {
                processInput(selection);
            }
            else {
                show(false);
            }
        }
    }

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

