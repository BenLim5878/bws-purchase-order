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
    //system("CLS");
    //cin.ignore();

    string line;
    ifstream myFile;
    myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
    if (myFile.is_open()) {
        while (getline(myFile, line))
        {
            cout << line << '\n';
        }
        myFile.close();
    }
    else cout << "Unable to open file";

    cout << "0-Back to Menu" << endl;
    cout << "Please Enter the Purchase Order ID" << endl;
    cout << "Please Enter: ";
    string search;
    cin >> search;
    
    string ProductName, PaymentMethod, Status, Date;
    int OrderID{},
    double Qty{}, Price{};
    string line;
    int found = 0;

    if (myFile.is_open()) {

        while (getline(myFile, line)) {

            if (line.find(search) != string::npos) {
                cout << search << endl;
                cout << "OrderID   ProductName   Qty   Price   PaymentMethod   Status" << endl;
                cout << OrderID << setw(6) << ProductName << setw(15) << Qty << setw(3) << Price << setw(5) << PaymentMethod << setw(10) << Status << setw(8) << endl;
                
                break;
            }
        }
    }
    myFile.close();
}

void VendorOrder() {
    cout << " Please Enter the Vendor ID" << endl;
}

void Report() {
    cout << " Do you want to create report? (Y/N)" << endl;
}

void DeliveryOrder() {
    cout << "Please Enter the Delivery ID" << endl;
}

void Logout() {
    cout << "Are you sure you wanna Logout? (Y/N)" << endl;
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

        string line;
        ifstream myFile;
        switch (selection) {
        case 1: 
        {//
            string line;
            ifstream myFile;
            myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
                while (getline(myFile, line))
                {
                    cout << line << '\n';
                }
                myFile.close();
           
        }//
        PurchaseOrder; system("CLS"); break;
        case 2: VendorOrder(); system("CLS"); break;
        case 3: Report(); system("CLS"); break;
        case 4: DeliveryOrder(); system("CLS"); break;
        case 5: Logout(); system("CLS"); break;
        }


    } while (selection != 6);
    return 0;
}


