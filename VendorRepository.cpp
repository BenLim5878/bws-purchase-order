#include "VendorRepository.h"
#include "Helper.h"
#include <algorithm>
#include "DataAccess.h"

//VendorID, (0)
//VendorName, (1)
//VendorStatus, (2)
//Vendor Description, (3)
//VendorRegisteredDate (4)

void VendorRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		Vendor temp;
		temp.setVendorID(std::stoi(record.at(0)));
		temp.vendorName = record.at(1);
		temp.vendorStatus = static_cast<VendorStatus>(std::stoi(record.at(2)));
		temp.vendorDescription = record.at(3);
		temp.vendorRegisteredDate = stringToTime(record.at(4));
		this->vendors->push(temp);
	}
}

Vendor* VendorRepository::getVendor(int vendorID)
{
	Vendor* t = nullptr;
	for (int i = 0; i < this->vendors->length; i++) {
		t = this->vendors->get(i);
		if (t->getVendorID() == vendorID) {
			return t;
		}
	}
	return nullptr;
}

void VendorRepository::addVendor(Vendor vendor)
{
	vendor.setVendorID(getNewVendorID());
	this->vendors->push(vendor);
}

Vendor VendorRepository::deleteVendor(int vendorID)
{
	Vendor* tarr = getVendor(vendorID);
	Vendor res;
	if (tarr) {
		res = this->vendors->remove(tarr);
	}
	return res;
}

std::unique_ptr<LinkedList<Product>> VendorRepository::getProductByVendor(int vendorID)
{
	ProductRepository* productRepo = DataAccess::getInstance()->productRepository;
	std::unique_ptr<LinkedList<Product>> productPointer(new LinkedList<Product>);
	for (int i = 0; i < productRepo->getTotalCategory(); i++) {
		ProductCategory* cat = productRepo->getProductCategory(i);
		for (int j = 0; j < productRepo->getTotalItemByCategory(cat->categoryTitle); j++) {
			Product* temp = productRepo->getProduct(cat->categoryID, j);
			if (temp->productVendor->getVendorID() == vendorID) {
				productPointer.get()->push(*temp);
			}
		}
	}
	return productPointer;
}

int VendorRepository::getNewVendorID()
{
	if (this->vendors->length == 0) {
		return 0;
	}
	std::vector<int> ids;
	for (int i = 0; i < this->vendors->length; i++) {
		ids.push_back(this->vendors->get(i)->getVendorID());
	}
	int max = *std::max_element(ids.begin(), ids.end());
	return  max + 1;
}

VendorRepository::VendorRepository(std::string fileLocation):vendors(new LinkedList<Vendor>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

VendorRepository::~VendorRepository()
{
}
