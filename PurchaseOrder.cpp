#include "PurchaseOrder.h"

int PurchaseOrder::getPOID()
{
    return this->poID;
}

void PurchaseOrder::setPOID(int id)
{
    this->poID = id;
}

PurchaseOrder::PurchaseOrder():orderedProducts(new LinkedList<ProductOrderDescription>()) {
    
}

PurchaseOrder::~PurchaseOrder() {
}

