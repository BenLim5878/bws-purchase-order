#include "StockInventoryReportView.h"
#include <Windows.h>
#include <iostream>
#include "Time.h"
#include "Header.h"
#include "DataAccess.h"
#include <iomanip>
#include "ReportMenuView.h"
#include "ProductTable.h"

using namespace std;

void View::StockInventoryReportView::show()
{
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    ViewComponent::ProductTable pTable(DataAccess::getInstance()->productRepository);
    pTable.show();

    cout << endl << endl << "Type any key to return to the report menu." << endl;
    int t;
    cin >> t;
    ReportMenuView view;
    view.show();
    return;

}
