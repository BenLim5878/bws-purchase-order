#include <iostream>
#include "Menu.h"
#include "DeliveryView.h"
#include "DeliveryTable.h"

using namespace std;

void View::DeliveryView::show()
{
    system("CLS");
    ViewComponent::DeliveryTable dTable;
    dTable.show();

    std::cout << "Please enter the Delivery ID to view the delivery details:" << endl;
    int deliveryID;
    cin >> deliveryID;
}