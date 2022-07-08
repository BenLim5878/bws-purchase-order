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
    return this->executiveID;
}

void SalesOrderExecutive::setExecutiveID(int executiveID) {
    this->executiveID = executiveID;
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
    string line;
    ifstream myFile;
    myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
    if (myFile.is_open()) {
        while (getline(myFile, line))
        {
            std::cout << line << '\n';
        }
        myFile.close();
    }
    else cout << "Unable to open file";
    int option;
    system("CLS");
    do {
        std::cout << "1-Add Order" << endl;
        std::cout << "2-Update Order" << endl;
        std::cout << "3-Search Order" << endl;
        std::cout << "4-Sort Order" << endl;
        std::cout << "5-Back to Main Menu" << endl;
        std::cout << "********************************************" << endl;

        std::cout << "Select Option >>" << endl;
        cin >> option;
        system("CLS");

        //switch (option) {
        //case 1: add(); system("CLS"); break;
        //case 2: update(); system("CLS"); break;
        //case 3: search(); system("CLS"); break;
        //case 4: sort(); system("CLS"); break;
        //}
    } while (option != 5);
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
    return;
}


