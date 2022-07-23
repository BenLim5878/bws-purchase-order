#include <iostream>
#include "Menu.h"
#include "DeliveryView.h"
#include "DeliveryTable.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"

using namespace std;
int dDecision;
string dDecision2;

void View::DeliveryView::show()
{
    system("CLS");
    ViewHeader::Header head;
    head.display();
    displayTime::Time dtime;
    dtime.show();
    //show the Delivery Table
    ViewComponent::DeliveryTable dTable(DataAccess::getInstance()->deliveryRepository->deliveries);
    dTable.show();

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
            View::Menu menu;
            menu.show();
        }
        else {
            show();
        }
    }
    else {
        show();
    }
}