#include "PurchaseOrderReportView.h"
#include <Windows.h>
#include <iostream>
#include "Time.h"
#include "Header.h"
#include <iomanip>
#include "DataAccess.h"
#include "PurchaseOrderTable.h"
#include "PurchaseOrderRepository.h"

void View::PurchaseOrderReportView::show()
{
    cin.clear();
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    auto poRepos = DataAccess::getInstance()->purchaseOrderRepository;

    auto summa = PurchaseOrderRepository::showSummary(poRepos->purchaseOrder);


    ViewComponent::PurchaseOrderTable poTable(poRepos->purchaseOrder);
    poTable.show();
    
    cout << "==================" << endl;
    cout << "Purchase Order Summary" << endl;
    cout << "==================" << endl;

    cout << "Total Amount: " << summa->totalAmount << endl;
    cout << "Total Pourchase Order Placed: " << summa->totalPOPlaced << endl;
    cout << "Total Incoming Stock: " << summa->totalIncomingStock << endl;
}
