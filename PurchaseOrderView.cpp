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
#include "DataAccess.h"
#include "Helper.h"

using namespace std;

void View::PurchaseOrderView::show(bool isValidInput)
{
    system("CLS");
    cin.clear();
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    auto po = DataAccess::getInstance()->purchaseOrderRepository;
    auto data = po->purchaseOrder;

    ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
    poTable.show();
     

    int option;
    cout << "" << endl;
    cout << "1-Add Order" << endl;
    cout << "2-Update Order" << endl;
    cout << "3-Search Order" << endl;
    cout << "4-Sort Order" << endl;
    cout << "5-Back to Main Menu" << endl;
    cout << "" << endl;
    cout << "=============================================================================" << endl;

    if (isValidInput) {
        cout << "Select Option >> ";
    }
    else {
        cout << "Invalid Input. Please try again! >> ";
    }
   
    option = promptNumericInput();
    if (option < 0) {
        show(false);
    }
    else {
        if (option > 0 && option < 6) {
            processInput(option);
        }
        else {
            show(false);
        }
    }
}

void View::PurchaseOrderView::processInput(int option) {
    switch (option) {
    case 1:
        AddRecordView addRecordView;
        addRecordView.show();
        return;
        break;
    case 2:
        UpdateRecordView updateRecordView;
        updateRecordView.show();
        return;
        break;
    case 3: 
        SearchRecordView searchRecordView;
        searchRecordView.show();
        return;
        break;
    case 4: 
        SortRecordView sortRecordView;
        sortRecordView.show();
        return;
        break;
    case 5:
        Menu menu;
        menu.show();
        return;
        break;
    }
}
