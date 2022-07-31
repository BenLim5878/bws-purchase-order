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

std::string Product::productStatusToString(ProductStatus productStatus)
{
    switch (productStatus) {
    case OnStock:
        return "On Stock";
        break;
    case OutOfStock:
        return "Out of Stock";
        break;
    }
}
