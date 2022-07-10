#include "PurchaseOrder.h"

int PurchaseOrder::getPOID()
{
    return 0;
}

void PurchaseOrder::setPOID(int id)
{
}

PurchaseOrder::PurchaseOrder() {
    this->orderedProducts = new Product[5];
}

PurchaseOrder::~PurchaseOrder() {

}

