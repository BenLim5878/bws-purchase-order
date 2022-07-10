#include "PurchaseOrder.h"

int PurchaseOrder::getPOID()
{
    return 0;
}

void PurchaseOrder::setPOID(int id)
{
}

PurchaseOrder::PurchaseOrder():orderedProducts(new LinkedList<ProductOrderDescription>()) {
    
}

PurchaseOrder::~PurchaseOrder() {
}

