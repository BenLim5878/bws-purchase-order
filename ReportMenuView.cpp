#include "ReportMenuView.h"
#include <iostream>
#include <Windows.h>
#include "Header.h"
#include "Time.h"
#include "StockInventoryReportView.h"
#include "UserReportView.h"
#include "DataAccess.h"
#include "Menu.h"
#include "PurchaseOrderReportView.h"
#include "Helper.h"

using namespace std;

void View::ReportMenuView::show()
{
    cin.clear();
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    std::cout << "\n=================== MENU ===================" << endl;
    std::cout << "" << endl;

    std::cout << "1-Stock Inventory Report" << endl;
    std::cout << "2-User Record" << endl;
    std::cout << "3-Purchase Order Summary" << endl;
    std::cout << "4-Back to Main Menu" << endl;
    std::cout << "" << endl;
    std::cout << "============================================" << endl;

    std::cout << "Select Option >> ";

    int selection = promptNumericInput();

    if (selection <= 0 || selection > 4) {
        show();
        return;
    }

    ReportConfig config;
    config.purchaseOrderArrangement = PurchaseOrderArrangement::Ascending;
    config.purchaseOrderPriority = PurchaseOrderPriority::ID;
    config.reportPeriod = ReportPeriod::All;
    PurchaseOrderReportView pView(config);


    switch (selection) {
    case 1:
        StockInventoryReportView sView;
        sView.show();
        return;
        break;
    case 2:
        UserReportView view;
        view.show();
        return;
        break;
    case 3:
    {
        pView.show();
        return;
        break;
    }
    case 4:
        Menu menu;
        menu.show();
        return;
        break;
    }
}
