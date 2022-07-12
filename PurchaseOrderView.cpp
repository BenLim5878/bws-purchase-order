#include "PurchaseOrderView.h"
#include "PurchaseOrderTable.h"
#include "AddRecordView.h"
#include "UpdateRecordView.h"
#include "SearchRecordView.h"
#include "SortRecordView.h"
#include <iostream>
#include "Menu.h"
#include "Header.h"
#include "Time.h"

using namespace std;

void View::PurchaseOrderView::show()
{
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();
    ViewComponent::PurchaseOrderTable poTable;
    poTable.show();

    //if (myFile.is_open()) {
    //    string line;
    //    getline(myFile, line);
    //    while (!myFile.eof())
    //    {

    //        getline(myFile, OrderID, ';');
    //        getline(myFile, ProductName, ';');
    //        getline(myFile, Date, ';');
    //        getline(myFile, Qty, ';');
    //        getline(myFile, Price, ';');
    //        getline(myFile, PaymentMethod, ';');
    //        getline(myFile, Status);

    //        i += 1;

    //        for (int i = 0; i < 1; i++)
    //        {
    //            cout
    //                << left
    //                << setw(11)
    //                << OrderID
    //                << left
    //                << setw(15)
    //                << ProductName
    //                << left
    //                << setw(12)
    //                << Date
    //                << left
    //                << setw(5)
    //                << Qty
    //                << left
    //                << setw(8)
    //                << Price
    //                << left
    //                << setw(18)
    //                << PaymentMethod
    //                << left
    //                << setw(10)
    //                << Status
    //                << endl;
    //        }
    //    }
    //    myFile.close();
    //}
    //else std::cout << "Unable to open file";

    int option;
    do {
        cout << "" << endl;
        cout << "1-Add Order" << endl;
        cout << "2-Update Order" << endl;
        cout << "3-Search Order" << endl;
        cout << "4-Sort Order" << endl;
        cout << "5-Back to Main Menu" << endl;
        cout << "" << endl;
        cout << "=============================================================================" << endl;

        std::cout << "Select Option >>" << endl;

        cin >> option;
        processInput(option);
    } while (option != 5);
}

void View::PurchaseOrderView::processInput(int option) {
    switch (option) {
    case 1:
        AddRecordView addRecordView;
        addRecordView.show();
        break;
    case 2:
        UpdateRecordView updateRecordView;
        updateRecordView.show();
        break;
    case 3: 
        SearchRecordView searchRecordView;
        searchRecordView.show();
        break;
    case 4: 
        SortRecordView sortRecordView;
        sortRecordView.show();
        break;
    case 5:
        Menu menu;
        menu.show();
        break;
    }
}
