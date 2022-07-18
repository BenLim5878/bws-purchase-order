#pragma once
#include <string>
#include "LinkedList.h"

enum VendorStatus {
	Active,
	Discontinued
};

class Vendor
{
private:
	int vendorID;
public:
	std::string vendorName;
	VendorStatus vendorStatus;
	std::string vendorDescription;
	tm vendorRegisteredDate;
public:
	int getVendorID();
	void setVendorID(int id);
	static std::string vendorStatusToString(VendorStatus vendorStatus);
};

