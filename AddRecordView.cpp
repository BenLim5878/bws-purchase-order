#include <iostream>
#include "AddRecordView.h"
#include "PurchaseOrderTable.h"

using namespace std;

void View::AddRecordView::show()
{
    system("CLS");
    cin.ignore();

    // Show the Purchase Order Table
    ViewComponent::PurchaseOrderTable poTable;
    poTable.show();

    std::cout << "" << endl;
    std::cout << "0-Back" << endl;


    std::cout << "Please Enter the Order ID: " << endl;
    int oid;
    string decision;
    cin >> oid;
    if (oid == 0) {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        cin >> decision;
        if (decision == "Y") {
            return;
        }
        else {
            std::cout << "Please Enter the Order ID: " << endl;
            cin >> oid;
        }
    }

    std::cout << "Please Enter the Product Name: " << endl;
    string pname;
    cin >> pname;
    if (pname == "0") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        cin >> decision;
        if (decision == "Y") {
            return;
        }
        else {
            std::cout << "Please Enter the Product Name: " << endl;
            cin >> pname;
        }
    }

    std::cout << "Please Enter the Quantity: " << endl;
    int qty;
    cin >> qty;
    if (qty == 0) {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        cin >> decision;
        if (decision == "Y") {
            return;
        }
        else {
            std::cout << "Please Enter the Quantity: " << endl;
            cin >> qty;
        }
    }

    std::cout << "Please Enter the Total Price (RM): " << endl;
    double price;
    cin >> price;
    if (price == 0) {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        cin >> decision;
        if (decision == "Y") {
            return;
        }
        else {
            std::cout << "Please Enter the Total Price (RM): " << endl;
            cin >> price;
        }
    }
    std::cout << "Please Enter the Payment Method (etc. MayBank): " << endl;
    string pmethod;
    cin >> pmethod;
    if (pmethod == "0") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        string decision;;
        cin >> decision;
        if (decision == "Y") {
            return;
        }
        else {
            std::cout << "Please Enter the Payment Method (etc. MayBank): " << endl;
            cin >> pmethod;

        }

    }

    std::cout << "Added Successfully!" << endl;
    std::cout << "0-Back" << endl;
    string back;
    cin >> back;
    if (back == "0") {
        return;
    }
}
