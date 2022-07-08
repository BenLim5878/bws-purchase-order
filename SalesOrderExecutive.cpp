#include "SalesOrderExecutive.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const int maxrow = 50;

//string OrderID[maxrow] = {};
//string ProductName[maxrow] = {};
//string Date[maxrow] = {};
//string Qty[maxrow] = {};
//string Amount[maxrow] = {};
//string PaymentMethod[maxrow] = {};
//string CustomerID[maxrow] = {};
//string CusName[maxrow] = {};
//string Status[maxrow] = {};

int SalesOrderExecutive::getExecutiveID() {
    return this->executivesID;
}

void SalesOrderExecutive::setExecutiveID(int executiveID) {
    this->executivesID = executiveID;
}

//void SearchRec(string search) {
//    system("CLS");
//    cout << "********************************************" << endl;
//    int counter = 0;
//    for (int x = 0; x < maxrow; x++) {
//        
//        if (OrderID[x] == search) {
//            counter++;
//            //PurchaseOrder();
//            break;
//        }
//    }
//
//    if (counter == 0) {
//        cout << "Sorry, No Record Found!" << endl;
//    }
//}

void PurchaseOrder() {
    system("CLS");
    cin.ignore();
    //string ProductName, PaymentMethod, Status, Date;
    //int OrderID{},
    //double Qty{}, Price{};
    string line;
    ifstream myFile;
    myFile.open("PurchaseOrder.txt", true);
    if (myFile.is_open()) {
        while (getline(myFile, line))
        {
            std::cout << line << '\n';
        }
        myFile.close();
    }
    else cout << "Unable to open file";
    int selection;
    do {
        std::cout << "1-Add Order" << endl;
        std::cout << "2-Update Order" << endl;
        std::cout << "3-Search Order" << endl;
        std::cout << "4-Sort Order" << endl;
        std::cout << "5-Back to Main Menu" << endl;
        std::cout << "********************************************" << endl;

        std::cout << "Select Option >>" << endl;
        cin >> selection;
        system("CLS");

        switch (selection) {
        case 1: add(); system("CLS"); break;
        case 2: update(); system("CLS"); break;
        case 3: search(); system("CLS"); break;
        case 4: sort(); system("CLS"); break;
        }
    } while (selection != 5);
    menu();
}

void add() {
    system("CLS");
    cin.ignore();
    std::cout << "Are you sure you want to add order? (Y/N)" << endl;
}

void update() {
    system("CLS");
    cin.ignore();
    std::cout << "Please enter the Order ID that you want to update: " << endl;
}

void search() {
    system("CLS");
    cin.ignore();
    std::cout << "Please enter the Order ID that you want to search: " << endl;
}

void sort() {
    system("CLS");
    cin.ignore();
    std::cout << "Are you sure you want to sort? (Y/N): " << endl;
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

void mainmenu() {
    system("CLS");
    cin.ignore();
    std::cout << "\n=================== MENU ===================" << endl;
    int selection;

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
        system("CLS");

        switch (selection) {
        case 1: PurchaseOrder(); system("CLS"); break;
        case 2: VendorOrder(); system("CLS"); break;
        case 3: Report(); system("CLS"); break;
        case 4: DeliveryOrder(); system("CLS"); break;
        case 5: Logout(); system("CLS"); break;
        }


    } while (selection != 6);
}


int SalesOrderExecutive::menu() {

    std::cout << "\n=================== MENU ===================" << endl;
    int selection;

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
        system("CLS");

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


