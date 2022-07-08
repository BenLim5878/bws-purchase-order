#include "SalesOrderExecutive.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void AddRecord();
void Update();


int SalesOrderExecutive::getExecutiveID() {
    return this->executiveID;
}

void SalesOrderExecutive::setExecutiveID(int executiveID) {
    this->executiveID = executiveID;
}

void PurchaseOrder() {
    system("CLS");
    cin.ignore();

    ifstream myFile;
    int i = 0;
    myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
    string OrderID, ProductName, Date, Qty, Price, PaymentMethod, Status;
    std::cout << "=============================================================================" << endl;
    cout
        << left
        << setw(11)
        << " OrderID"
        << left
        << setw(15)
        << "ProductName"
        << left
        << setw(12)
        << "Date"
        << left
        << setw(5)
        << "Qty"
        << left
        << setw(8)
        << "Price"
        << left
        << setw(18)
        << "PaymentMethod"
        << left
        << setw(10)
        << "Status"
        << endl;
    std::cout << "=============================================================================" << endl;
    if (myFile.is_open()) {
        string line;
        getline(myFile, line);
        while (!myFile.eof())
        {

            getline(myFile, OrderID, ';');
            getline(myFile, ProductName, ';');
            getline(myFile, Date, ';');
            getline(myFile, Qty, ';');
            getline(myFile, Price, ';');
            getline(myFile, PaymentMethod, ';');
            getline(myFile, Status);

            i += 1;

            for (int i = 0; i < 1; i++)
            {
                cout
                    << left
                    << setw(11)
                    << OrderID
                    << left
                    << setw(15)
                    << ProductName
                    << left
                    << setw(12)
                    << Date
                    << left
                    << setw(5)
                    << Qty
                    << left
                    << setw(8)
                    << Price
                    << left
                    << setw(18)
                    << PaymentMethod
                    << left
                    << setw(10)
                    << Status
                    << endl;
            }
        }
        myFile.close();
    }
    else std::cout << "Unable to open file";
    std::cout << "=============================================================================" << endl;
    int option;
    do {
        std::cout << "" << endl;
        std::cout << "1-Add Order" << endl;
        std::cout << "2-Update Order" << endl;
        std::cout << "3-Search Order" << endl;
        std::cout << "4-Sort Order" << endl;
        std::cout << "5-Back to Main Menu" << endl;
        std::cout << "" << endl;
        std::cout << "=============================================================================" << endl;

        std::cout << "Select Option >>" << endl;
        cin >> option;
        system("CLS");

        switch (option) {
        case 1: AddRecord(); system("CLS"); break;
        case 2: Update(); system("CLS"); break;
        //case 3: search(); system("CLS"); break;
        //case 4: sort(); system("CLS"); break;
        }
    } while (option != 5);
}

void AddRecord() {
    system("CLS");
    cin.ignore();

    ifstream myFile;
    int i = 0;
    myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
    string OrderID, ProductName, Date, Qty, Price, PaymentMethod, Status;
    std::cout << "=============================================================================" << endl;
    cout
        << left
        << setw(11)
        << " OrderID"
        << left
        << setw(15)
        << "ProductName"
        << left
        << setw(12)
        << "Date"
        << left
        << setw(5)
        << "Qty"
        << left
        << setw(8)
        << "Price"
        << left
        << setw(18)
        << "PaymentMethod"
        << left
        << setw(10)
        << "Status"
        << endl;
    std::cout << "=============================================================================" << endl;
    if (myFile.is_open()) {
        string line;
        getline(myFile, line);
        while (!myFile.eof())
        {

            getline(myFile, OrderID, ';');
            getline(myFile, ProductName, ';');
            getline(myFile, Date, ';');
            getline(myFile, Qty, ';');
            getline(myFile, Price, ';');
            getline(myFile, PaymentMethod, ';');
            getline(myFile, Status);

            i += 1;

            for (int i = 0; i < 1; i++)
            {
                cout
                    << left
                    << setw(11)
                    << OrderID
                    << left
                    << setw(15)
                    << ProductName
                    << left
                    << setw(12)
                    << Date
                    << left
                    << setw(5)
                    << Qty
                    << left
                    << setw(8)
                    << Price
                    << left
                    << setw(18)
                    << PaymentMethod
                    << left
                    << setw(10)
                    << Status
                    << endl;
            }
        }

        myFile.close();
    }
    else std::cout << "Unable to open file";
    std::cout << "=============================================================================" << endl;
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
    //do {
    //    std::cout << "Please Enter the Order ID: " << endl;
    //    cin >> oid;
    //    if (oid == 0) {
    //        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
    //        cin >> decision;
    //    }
    //    else {
    //        exit;
    //    }
    //}while (decision != "Y");{
    //    return;
    //}

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
    //int option2;
    //cin >> option2;
    //system("CLS");

}

void Update() {
    system("CLS");
    cin.ignore();

    ifstream myFile;
    int i = 0;
    myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
    string OrderID, ProductName, Date, Qty, Price, PaymentMethod, Status;
    std::cout << "=============================================================================" << endl;
    cout
        << left
        << setw(11)
        << " OrderID"
        << left
        << setw(15)
        << "ProductName"
        << left
        << setw(12)
        << "Date"
        << left
        << setw(5)
        << "Qty"
        << left
        << setw(8)
        << "Price"
        << left
        << setw(18)
        << "PaymentMethod"
        << left
        << setw(10)
        << "Status"
        << endl;
    std::cout << "=============================================================================" << endl;
    if (myFile.is_open()) {
        string line;
        getline(myFile, line);
        while (!myFile.eof())
        {

            getline(myFile, OrderID, ';');
            getline(myFile, ProductName, ';');
            getline(myFile, Date, ';');
            getline(myFile, Qty, ';');
            getline(myFile, Price, ';');
            getline(myFile, PaymentMethod, ';');
            getline(myFile, Status);

            i += 1;

            for (int i = 0; i < 1; i++)
            {
                cout
                    << left
                    << setw(11)
                    << OrderID
                    << left
                    << setw(15)
                    << ProductName
                    << left
                    << setw(12)
                    << Date
                    << left
                    << setw(5)
                    << Qty
                    << left
                    << setw(8)
                    << Price
                    << left
                    << setw(18)
                    << PaymentMethod
                    << left
                    << setw(10)
                    << Status
                    << endl;
            }
        }

        myFile.close();
    }
    else std::cout << "Unable to open file";
    std::cout << "=============================================================================" << endl;
    std::cout << "" << endl;
    std::cout << "0-Back" << endl;
    std::cout << "Please Enter the Order ID: " << endl;
    int option2;
    cin >> option2;
    system("CLS");
}

void VendorOrder() {
    std::cout << " Please Enter the Vendor ID" << endl;
}

void Report() {
    std::cout << " Do you want to create report? (Y/N)" << endl;
}

void DeliveryOrder() {
    std::cout << "Please Enter the Delivery ID" << endl;
}

void Logout() {
    std::cout << "Are you sure you wanna Logout? (Y/N)" << endl;
}


int SalesOrderExecutive::menu() {

    std::cout << "\n=================== MENU ===================" << endl;
    int selection;
    system("CLS");
    do {
        std::cout << "1-Purchase Order" << endl;
        std::cout << "2-Vendor Order" << endl;
        std::cout << "3-Report" << endl;
        std::cout << "4-Delivery Order" << endl;
        std::cout << "5-Logout" << endl;
        std::cout << "6-Exit Program" << endl;
        std::cout << "********************************************" << endl;

        std::cout << "Select Option >>" << endl;
        cin >> selection;

        switch (selection) {
        case 1: PurchaseOrder(); system("CLS"); break;
        case 2: VendorOrder(); system("CLS"); break;
        case 3: Report(); system("CLS"); break;
        case 4: DeliveryOrder(); system("CLS"); break;
        case 5: Logout(); system("CLS"); break;
        }


    } while (selection != 6);
    return 0;
}


