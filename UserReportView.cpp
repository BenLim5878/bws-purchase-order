#include "UserReportVIew.h"
#include <Windows.h>
#include <iostream>
#include "Time.h"
#include "Header.h"
#include "DataAccess.h"
#include <iomanip>
#include "ReportMenuView.h"
#include "UserTable.h"

using namespace std;

void View::UserReportView::show()
{
    cin.clear();
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();

    ViewComponent::UserTable tableView(DataAccess::getInstance()->userRepository->users);
    tableView.show();

    std::cout << "" << endl;
    std::cout << "B-Back to Menu" << endl;
    std::cout << "Enter: ";
    string vDecision;
    string vDecision2;
    cin >> vDecision;
    if (vDecision == "B") {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        cin >> vDecision2;
        if (vDecision2 == "Y") {
            ReportMenuView view;
            view.show();
        }
        else {
            View::UserReportView::show();
        }
    }

}