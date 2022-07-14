#include "PurchaseOrder.h"

int PurchaseOrder::getPOID()
{
    return this->poID;
}

void PurchaseOrder::setPOID(int id)
{
    this->poID = id;
}

std::string PurchaseOrder::orderStatusToString(OrderStatus orderStatus)
{
    switch (orderStatus)
    {
    case Sent:
        return "Sent";
        break;
    case Processing:
        return "Processing";
        break;
    case Delivering:
        return "Delivering";
        break;
    case Complete:
        return "Complete";
        break;
    }

    return std::string();
}

PurchaseOrder::PurchaseOrder():orderedProducts(new LinkedList<ProductOrderDescription>()) {
    
}

PurchaseOrder::~PurchaseOrder() {
}

