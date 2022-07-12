#pragma once
#include "IRepository.h"
#include "Vendor.h"
#include "TextDataReader.h"
#include <string>
#include "LinkedList.h"
#include "Product.h"
#include <memory>

class VendorRepository:public IRepository
{
private:
	virtual void loadData();
private:
	std::string fileLocation;
	TextDataReader* dataReader;
public:
	LinkedList<Vendor>* vendors;
public:
	Vendor* getVendor(int vendorID);
	void addVendor(Vendor vendor);
	Vendor deleteVendor(int vendorID);
	std::unique_ptr<LinkedList<Product>> getProductByVendor(int vendorID);
private:
	int getNewVendorID();
public:
	VendorRepository(std::string fileLocation);
	~VendorRepository();
};

