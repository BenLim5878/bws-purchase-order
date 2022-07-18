#include <iostream>
#include "AddRecordView.h"
#include "PurchaseOrderTable.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "poData.h"
#include <ctime>
#include "Helper.h"
#include "VendorRepository.h"
#include "Payment.h"
using namespace std;

void choice(PurchaseOrder* temp, Payment* tempPayment) {
	auto timeNow = std::time(0);
	auto timeTm = std::localtime(&timeNow);

	// Let user to choose payment method
	int userChoice = -1;
	std::cout << "*** Payment Method ***" << endl;
	std::cout << "0-Credit Card" << endl;
	std::cout << "1-Check" << endl;
	std::cout << "2-Bank Transfer" << endl;
	std::cout << "Please choose your payment method:" << endl;
	std::cout << "Payment Method: ";

	std::cin >> userChoice;
	tempPayment->paymentMethod = static_cast<PaymentMethod>(userChoice);
	tempPayment->createdAt = *timeTm;
}

void View::AddRecordView::show()
{
	system("CLS");
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();

	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
	poTable.show();

	auto po = DataAccess::getInstance()->purchaseOrderRepository;
	auto data = po->purchaseOrder;
	auto timeNow = std::time(0);
	auto timeTm = std::localtime(&timeNow);

	std::cout << "" << endl;
	std::cout << "B-Back" << endl;
	std::cout << "Press Any Letter or Number to Proceed to Add Purchase Record" << endl;
	std::cout << "Enter:";
	string back;
	cin >> back;
	if (back == "B") {
		std::cout << "Are you sure you want to exit? (Y/N): ";
		string decision;;
		std::cin >> decision;
		if (decision == "Y") {
			return;
		}
	}

	auto ven = DataAccess::getInstance()->vendorRepository;
	auto vdata = ven->vendors;
	PurchaseOrder temp;
	int vendorID = -1;
	float totalOrderedPrice = 0;
	// Please select which vendor to order from
	std::cout << "Please select which vendor to order from: " << endl;
	std::cout << " " << "Vendor ID" << " | " << "Name" << " | " << "Description" << " | " << "Status" << endl;
	for (int i = 0; i < vdata->length; i++)
	{
		auto vrec = vdata->get(i);
		std::cout << " " << vrec->getVendorID() << " | " << vrec->vendorName << " | " << vrec->vendorDescription << " | " << Vendor::vendorStatusToString(vrec->vendorStatus) << endl;
	}
	std::cout << "Vendor ID: ";
	std::cin >> vendorID;


	temp.vendor = DataAccess::getInstance()->vendorRepository->getVendor(vendorID);
	auto productList = DataAccess::getInstance()->vendorRepository->getProductByVendor(vendorID);
	std::cout << " " << "Product ID" << " | " << "Name" << " | " << "Brand" << " | " << "Description" << " | " << "Price" << " | " << "Qty" << " | " << "Status" << endl;
	for (int i = 0; i < productList->length; i++)
	{
		auto product = productList->get(i);
		std::cout << " " << product->getProductID() << " | " << product->productName << " | " << product->productBrand << " | " << product->productDescription << " | " << product->productPricePerUnit << " | " << product->productQuantityPerUnit << " | " << Product::productStatusToString(product->productStatus) << endl;
	}

	int productID = -1;
	std::cout << "Product ID: ";
	std::cin >> productID;
	Product* tarrProduct = DataAccess::getInstance()->productRepository->getProduct(productID);


	// Please input the amount of items you want to order
	int orderedAmount = -1;
	std::cout << "Please enter the amount of items you want to order: " << endl;
	std::cout << "Amount of items:";
	std::cin >> orderedAmount;
	ProductOrderDescription orderDescription;
	orderDescription.product = tarrProduct;
	orderDescription.quantity = orderedAmount;
	totalOrderedPrice += (tarrProduct->productPricePerUnit * orderedAmount);
	std::cout << "Total Ordered Price: " << totalOrderedPrice << endl;

	temp.orderedProducts = new LinkedList<ProductOrderDescription>;
	temp.orderedProducts->push(orderDescription);

	// Let user to confirm the order or add another product
	std::cout << "*** Please Select ***" << endl;
	std::cout << "1-Confirm Order" << endl;
	std::cout << "2-Add Another Order" << endl;
	int order;
	Payment tempPayment;
	std::cin >> order;
	switch (order) {
	case 1:
		temp.orderStatus = OrderStatus::Sent;
		temp.totalPrice = totalOrderedPrice;
		tempPayment.paymentAmount = totalOrderedPrice;
		break;
	case 2:
		temp.orderStatus = OrderStatus::Sent;
		temp.totalPrice = totalOrderedPrice;
		tempPayment.paymentAmount = totalOrderedPrice;
		View::AddRecordView::show();
		break;

	}
	choice(&temp, &tempPayment);
	Payment* addedPayment = DataAccess::getInstance()->paymentRepository->addPayment(tempPayment);
	temp.paymentRecord = *addedPayment;
	temp.timeCreated = *timeTm;

	DataAccess::getInstance()->purchaseOrderRepository->addPurchaseOrder(temp);

	std::cout << " " << endl;
	std::cout << "Added Successfully!" << endl;
	std::cout << " " << endl;
	std::cout << "B-Back" << endl;
	std::cout << "Enter: ";
	std::cin >> back;
}

