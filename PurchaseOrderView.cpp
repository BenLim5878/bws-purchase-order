#include "PurchaseOrderView.h"
#include "PurchaseOrderTable.h"
#include "AddRecordView.h"
#include "UpdateRecordView.h"
#include <iostream>
#include "Menu.h"

using namespace std;

void View::PurchaseOrderView::show()
{
    system("CLS");
    ViewComponent::PurchaseOrderTable poTable;
    poTable.show();


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
        //case 3: search(); system("CLS"); break;
        //case 4: sort(); system("CLS"); break;
    case 5:
        Menu menu;
        menu.show();
        break;
    }
}
