#include "SalesOrderExecutive.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const int maxrow = 50;

int SalesOrderExecutive::getExecutiveID() {
    return this->executivesID;
}

void SalesOrderExecutive::setExecutiveID(int executiveID) {
    this->executivesID = executiveID;
}

void PurchaseOrder() {
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


