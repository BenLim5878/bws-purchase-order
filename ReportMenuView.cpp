#include "ReportMenuView.h"
#include <iostream>
#include <Windows.h>
#include "Header.h"
#include "Time.h"

using namespace std;

void View::ReportMenuView::show()
{
    int selection = 0;

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
    std::cout << "" << endl;
    std::cout << "============================================" << endl;

    switch (selection) {
    case 1:
        //Stock Inventory Report();
        break;
    case 2:
        //User Record();
        break;
    case 3:
        //Purchase Order Summary();
        break;
    }
}