#include "Vendor.h"

int Vendor::getVendorID()
{
    return this->vendorID;
}

void Vendor::setVendorID(int id)
{
    this->vendorID = id;
}

std::string Vendor::vendorStatusToString(VendorStatus vendorStatus)
{
    switch (vendorStatus) {
    case Active:
        return "Active";
        break;
    case Discontinued:
        return "Discontinued";
        break;
    }
}
