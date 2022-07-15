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
#include "poData.h"

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
    poData::Data dTable;
    dTable.show();
 /*   auto po = DataAccess::getInstance()->purchaseOrderRepository;
    po->sort(PurchaseOrderPriority::PayMethod, PurchaseOrderArrangement::Decending);
    auto data = po->purchaseOrder;


    for (int i = 0; i < data->length; i++)
    {
        auto record = data->get(i)->content;

        for (int j = 0; j < record.orderedProducts->length; j++) {
            cout
                << left
                << setw(3)
                << ""
                << left
                << setw(7)
                << record.getPOID()
                << left
                << setw(16)
                << record.orderedProducts->get(j)->product->productName
                << left
                << setw(5)
                << record.orderedProducts->get(j)->quantity
                << left
                << setw(22)
                << std::put_time(&record.timeCreated, "%Y-%m-%d.%H:%M:%S")
                << left
                << setw(3)
                << ""
                << left
                << setw(8)
                << record.totalPrice
                << left
                << setw(18)
                << Payment::paymentMethodToString(record.paymentRecord.paymentMethod)
                << left
                << setw(10)
                << PurchaseOrder::orderStatusToString(record.orderStatus)
                << endl;
            if (j == record.orderedProducts->length - 1) {
                cout
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(7)
                    << ""
                    << left
                    << setw(16)
                    << record.orderedProducts->get(j)->product->productName
                    << left
                    << setw(5)
                    << record.orderedProducts->get(j)->quantity
                    << left
                    << setw(22)
                    << put_time(&record.timeCreated, "%Y-%m-%d.%H:%M:%S")
                    << left
                    << setw(3)
                    << ""
                    << left
                    << setw(8)
                    << record.totalPrice
                    << left
                    << setw(18)
                    << Payment::paymentMethodToString(record.paymentRecord.paymentMethod)
                    << left
                    << setw(10)
                    << PurchaseOrder::orderStatusToString(record.orderStatus)
                    << endl;
            }
        }

    }*/

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
