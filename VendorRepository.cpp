#include "VendorRepository.h"
#include "Helper.h"
#include <algorithm>
#include "DataAccess.h"

//VendorID, (0)
//VendorName, (1)
//VendorStatus, (2)
//Vendor Description, (3)
//VendorRegisteredDate (4)

// Swap function for quick sort algorithm
void swap(LinkedList<Vendor>* list, SinglyNode<Vendor>* low, SinglyNode<Vendor>* high) {
	SinglyNode<Vendor>* prevNode = nullptr;
	SinglyNode<Vendor>* prevNode2 = nullptr;
	auto l = list->head;
	auto r = list->head;

	if (l == nullptr) {
		return;
	}

	if (low->data.getVendorID() == high->data.getVendorID()) {
		return;
	}

	while (l != nullptr && l->data.getVendorID() != low->data.getVendorID()) {
		prevNode = l;
		l = l->next;
	}

	while (r != nullptr && r->data.getVendorID() != high->data.getVendorID()) {
		prevNode2 = r;
		r = r->next;
	}

	if (l != nullptr && r != nullptr) {
		if (prevNode != nullptr) {
			prevNode->next = r;
		}
		else {
			list->head = r;
		}

		if (prevNode2 != nullptr) {
			prevNode2->next = l;
		}
		else {
			list->head = l;
		}
		auto temp = l->next;
		l->next = r->next;
		r->next = temp;
	}
	else {
		return;
	}


}

int partition(LinkedList<Vendor>* list, int low, int high, Vendor* pivot)
{
	int i = low;
	int j = low;
	while (i <= high) {
		auto iTime = mktime(&list->get(i)->vendorRegisteredDate);
		auto pivotTime = mktime(&pivot->vendorRegisteredDate);
		if (iTime > pivotTime) {
			i++;
		}
		else {
			swap(list, list->getNode(i), list->getNode(j));
			i++;
			j++;
		}
	}
	return j - 1;
}

// Sort vendor list by date created
void sort(LinkedList<Vendor>* list, int low, int high)
{
	if (low < high) {
		auto pivot = list->get(high);
		int pos = partition(list, low, high, pivot);
		sort(list, low, pos - 1);
		sort(list, pos + 1, high);
	}
}

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
	sort(this->vendors, 0, this->vendors->length - 1);
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