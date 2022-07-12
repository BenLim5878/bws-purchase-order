#include <iostream>
#include "Menu.h"
#include "DeliveryView.h"
#include "DeliveryTable.h"
#include "Header.h"
#include "Time.h"

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
    ViewComponent::DeliveryTable dTable;
    dTable.show();

    std::cout << "0-Back to Menu" << endl;
    std::cout << "Please enter the Delivery ID to view the delivery details:" << endl;
    int deliveryID;
    cin >> deliveryID;

    if (dDecision == 0) {
        std::cout << "Are you sure you want to exit? (Y/N): " << endl;
        cin >> dDecision2;
        if (dDecision2 == "Y") {
            View::Menu menu;
            menu.show();
        }
        else {
            std::cout << "Please enter the Delivery ID to view the delivery details:" << endl;
            cin >> deliveryID;
        }
    }
}