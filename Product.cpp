#include "Product.h"

Product::Product()
{
}

Product::~Product()
{
}

int Product::getProductID()
{
    return this->productID;
}

void Product::setProductID(int id)
{
    this->productID = id;
}
