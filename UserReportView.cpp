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

    cout << endl << endl << "Type any key to return to the report menu. " << endl;
    int t;
    cin >> t;
    ReportMenuView view;
    view.show();
}