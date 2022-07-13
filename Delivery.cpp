#include "Delivery.h"

std::string Delivery::deliveryStatusToString(DeliveryStatus deliveryStatus)
{
    switch (deliveryStatus) {
    case Shipping:
        return "Shipping";
        break;
    case Delivered:
        return "Delivered";
        break;
    }
}

int Delivery::getDeliveryID()
{
    return this->deliveryID;
}

void Delivery::setDeliveryID(int deliveryID)
{
    this->deliveryID = deliveryID;
}
