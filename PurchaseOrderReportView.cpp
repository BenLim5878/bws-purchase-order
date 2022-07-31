#include "PurchaseOrderReportView.h"
#include <Windows.h>
#include <iostream>
#include "Time.h"
#include "Header.h"
#include <iomanip>
#include "DataAccess.h"
#include "PurchaseOrderTable.h"
#include "PurchaseOrderRepository.h"
#include "ReportMenuView.h"
#include "Helper.h"

void View::PurchaseOrderReportView::show()
{
    cin.clear();
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    auto poRepos = DataAccess::getInstance()->purchaseOrderRepository;
    poRepos->sort(this->reportConfig.purchaseOrderPriority, this->reportConfig.purchaseOrderArrangement);
    auto list = PurchaseOrderRepository::getPurchaseOrderByPeriod(poRepos->purchaseOrder, this->reportConfig.reportPeriod);
    auto summa = PurchaseOrderRepository::showSummary(list.get());

    time_t time = std::time(0);
    tm tm_time;
    char timeString[32];
    switch (this->reportConfig.reportPeriod) {
    case ReportPeriod::All:
        cout << "Showing report from all purchase orders :" << endl << endl;
        break;
    case ReportPeriod::Daily:
        time = time - 86400;
        localtime_s(&tm_time, &time);
        strftime(timeString, 32, "%Y-%m-%d",&tm_time);
        cout << "Showing report from " << timeString<< " :" << endl << endl;
        break;
    case ReportPeriod::Monthly:
        time = time - 2.628e+6;
        localtime_s(&tm_time, &time);
        strftime(timeString, 32, "%Y-%m-%d", &tm_time);
        cout << "Showing report from " << timeString << " :" << endl << endl;
        break;
    case ReportPeriod::Annually:
        time = time - 3.154e+7;
        localtime_s(&tm_time, &time);
        strftime(timeString, 32, "%Y-%m-%d", &tm_time);
        cout << "Showing report from " << timeString << " :" << endl << endl;
        break;
    }

    cout << "======================" << endl;
    cout << "Purchase Order Summary" << endl;
    cout << "======================" << endl;

    cout << "Total Amount: RM " << summa->totalAmount << endl;
    cout << "Total Pourchase Order Placed: " << summa->totalPOPlaced << endl;
    cout << "Total Incoming Stock: " << summa->totalIncomingStock << endl << endl;

    ViewComponent::PurchaseOrderTable poTable(list.get());
    poTable.show();

    std::cout << "\n=================== REPORT MENU ===================" << endl;
    std::cout << "1- Select Report" << endl;
    std::cout << "2- Sort Purchase Order by Criteria" << endl;
    std::cout << "3- Back to Report Menu" << endl;
    std::cout << "===================================================" << endl;

    std::cout << "Select Option >> ";

    std::string input;
    char selection = 'f';
    cin >> input;
    cin.ignore();
    if (input.length() != 1) {
        show();
    }
    else {
        selection = input[0];
    }
    processInput(selection);
}

void View::PurchaseOrderReportView::processInput(char selection)
{

    ReportMenuView menuView;
    switch (selection) {
        case '1':
            showReportSelectionMenu();
            break;
        case '2':
            showCriteriaMenu();
            break;
        case '3':
            menuView.show();
            return;
            break;
        default:
            menuView.show();
            return;
            break;
    }
}

void View::PurchaseOrderReportView::showCriteriaMenu() {
    cout
        << endl
        << "Please select criteria you wish to sort: "
        << endl << endl
        << "1- ID (Default)" << endl
        << "2- Latest" << endl
        << "3- Payment Method" << endl
        << "4- Status" << endl
        << "5- Total Item" << endl
        << "6- Total Price" << endl << endl
        << "Select Option >> ";
    string input;
    cin >> input;
    if (input.length() > 1) {
        this->reportConfig.purchaseOrderPriority = static_cast<PurchaseOrderPriority>(0);
    }
    else {
        this->reportConfig.purchaseOrderPriority = static_cast<PurchaseOrderPriority>(stoi(input)-1);
    }

    cout
        << endl
        << "================================================"
        << endl
        << "Please select order you wish to view: "
        << endl << endl
        << "1- Ascending (Default)" << endl
        << "2- Descending" << endl << endl
        << "Select Option >> ";
    string input2;
    cin >> input2;
    string selection2;
    if (input2.length() > 1) {
        this->reportConfig.purchaseOrderArrangement = static_cast<PurchaseOrderArrangement>(0);
    }
    else {
        this->reportConfig.purchaseOrderArrangement = static_cast<PurchaseOrderArrangement>(stoi(input2)-1);
    }

    PurchaseOrderReportView view(this->reportConfig);
    view.show();
    return;
}

void View::PurchaseOrderReportView::showReportSelectionMenu()
{
    cout
        << endl
        << "Please select report type: "
        << endl << endl
        << "1- All (Default)" << endl
        << "2- Daily" << endl
        << "3- Monthly" << endl
        << "4- Annually" << endl << endl
        << "Select Option >> ";
    string input;
    cin >> input;
    if (input.length() > 1) {
        this->reportConfig.reportPeriod = static_cast<ReportPeriod>(0);
    }
    else {
        this->reportConfig.reportPeriod = static_cast<ReportPeriod>(stoi(input) - 1);
    }
    PurchaseOrderReportView view(this->reportConfig);
    view.show();
    return;
}

View::PurchaseOrderReportView::PurchaseOrderReportView(ReportConfig reportConfig)
{
    this->reportConfig = reportConfig;
}

View::PurchaseOrderReportView::~PurchaseOrderReportView()
{
}
