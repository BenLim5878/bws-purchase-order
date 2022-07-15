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
	std::cout << "Please choose your payment method: ";

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
	std::cout << "0-Back" << endl;


	//std::cout << "Please Enter the Order ID: " << endl;
	//int oid;
	//string decision;
	//std::cin>> oid;
	//if (oid == 0) {
	//	std::cout << "Are you sure you want to exit? (Y/N): " << endl;
	//	string decision;;
	//	std::cin>> decision;
	//	if (decision == "Y") {
	//		return;
	//	}
	//	else {
	//		std::cout << "Please Enter the Order ID: " << endl;
	//		std::cin>> oid;
	//	}
	//}

	//std::cout << "Please Enter the Product Name: " << endl;
	//string pname;
	//std::cin>> pname;
	//if (pname == "0") {
	//	std::cout << "Are you sure you want to exit? (Y/N): " << endl;
	//	string decision;;
	//	std::cin >> decision;
	//	if (decision == "Y") {
	//		return;
	//	}
	//	else {
	//		std::cout << "Please Enter the Product Name: " << endl;
	//		std::cin >> pname;
	//	}
	//}

	//std::cout << "Please Enter the Quantity: " << endl;
	//int qty;
	//std::cin >> qty;
	//if (qty == 0) {
	//	std::cout << "Are you sure you want to exit? (Y/N): " << endl;
	//	string decision;
	//	std::cin >> decision;
	//	if (decision == "Y") {
	//		return;
	//	}
	//	else {
	//		std::cout << "Please Enter the Quantity: " << endl;
	//		std::cin >> qty;
	//	}
	//}

	//std::cout << "Please Enter the Total Price (RM): " << endl;
	//double price;
	//std::cin >> price;
	//if (price == 0) {
	//	std::cout << "Are you sure you want to exit? (Y/N): " << endl;
	//	string decision;;
	//	std::cin >> decision;
	//	if (decision == "Y") {
	//		return;
	//	}
	//	else {
	//		std::cout << "Please Enter the Total Price (RM): " << endl;
	//		std::cin >> price;
	//	}
	//}
	//std::cout << "Please Enter the Payment Method (etc. MayBank): " << endl;
	//
	//std::cout << "1-Credit Card" << endl;
	//std::cout << "2-Check" << endl;
	//std::cout << "3-Bank Transfer" << endl;
	//int method{};
	//string pmethod;
	//std::cin >> pmethod;
	//switch (method) {
	//case 1:
	//	pmethod = "Credit Card";
	//	std::cin >> pmethod;
	//	break;
	//case 2:
	//	pmethod = "Check";
	//	std::cin >> pmethod;
	//	break;
	//case 3:
	//	pmethod = "Bank Transfer";
	//	std::cin >> pmethod;
	//	break;
	//}
	//
	//if (pmethod == "0") {
	//	std::cout << "Are you sure you want to exit? (Y/N): " << endl;
	//	string decision;
	//	std::cin >> decision;
	//	if (decision == "Y") {
	//		return;
	//	}
	//	else {
	//		std::cout << "Please Enter the Payment Method (etc. MayBank): " << endl;
	//		std::cout << "1-Credit Card" << endl;
	//		std::cout << "2-Check" << endl;
	//		std::cout << "3-Bank Transfer" << endl;
	//		int method{};
	//		switch (method) {
	//		case 1:
	//			pmethod = "Credit Card";
	//			std::cin >> pmethod;
	//			break;
	//		case 2:
	//			pmethod = "Check";
	//			std::cin >> pmethod;
	//			break;
	//		case 3:
	//			pmethod = "Bank Transfer";
	//			std::cin >> pmethod;
	//			break;
	//		}
	//	}
	//	}

	//	std::cout << "Please Enter the Order Status: " << endl;
	//	std::cout << "1-Processing" << endl;
	//	std::cout << "2-Sent" << endl;
	//	std::cout << "3-Complete" << endl;
	//	std::cout << "4-Delivering" << endl;
	//	string status;
	//	std::cin >> status;
	//	int stat{};
	//	switch (stat) {
	//	case 1:
	//		status = "Processing";
	//		std::cin >> status;
	//		break;
	//	case 2:
	//		status = "Sent";
	//		std::cin >> status;
	//		break;
	//	case 3:
	//		status = "Complete";
	//		std::cin >> status;
	//		break;
	//	case 4:
	//		status = "Delivering";
	//		std::cin >> status;
	//		break;
	//	}
	//	if (pmethod == "0") {
	//		std::cout << "Are you sure you want to exit? (Processing/Sent/Complete/Delivering): " << endl;
	//		string decision;;
	//		std::cin >> decision;
	//		if (decision == "Y") {
	//			return;
	//		}
	//		else {

	//			std::cout << "Please Enter the Order Status (Processing/Sent/Complete/Delivering): " << endl;
	//			std::cout << "1-Processing" << endl;
	//			std::cout << "2-Sent" << endl;
	//			std::cout << "3-Complete" << endl;
	//			std::cout << "4-Delivering" << endl;
	//			int stat{};
	//			switch (stat) {
	//			case 1:
	//				status = "Processing";
	//				std::cin >> status;
	//				break;
	//			case 2:
	//				status = "Sent";
	//				std::cin >> status;
	//				break;
	//			case 3:
	//				status = "Complete";
	//				std::cin >> status;
	//				break;
	//			case 4:
	//				status = "Delivering";
	//				std::cin >> status;
	//				break;
	//			}
	//		}
	//}

	auto ven = DataAccess::getInstance()->vendorRepository;
	auto vdata = ven->vendors;
	PurchaseOrder temp;
	int vendorID = -1;
	float totalOrderedPrice = 0;
	// Please select which vendor to order from
	std::cout << "Please select which vendor to order from: " << endl;

	for (int i = 0; i < vdata->length; i++)
	{
		auto vrec = vdata->get(i);
		std::cout << " " << vrec->getVendorID() << " | " << vrec->vendorName << " | " << vrec->vendorDescription << " | " << vrec->vendorStatus << endl;
	}
	std::cout << "Vendor ID: ";
	std::cin >> vendorID;


	temp.vendor = DataAccess::getInstance()->vendorRepository->getVendor(vendorID);
	auto productList = DataAccess::getInstance()->vendorRepository->getProductByVendor(vendorID);
	for (int i = 0; i < productList->length; i++)
	{
		auto product = productList->get(i);
		cout << " " << product->getProductID() << " | " << product->productName << " | " << product->productBrand << " | " << product->productCategory << " | " << product->productDescription << " | " << product->productDiscountRate << " | " << product->productPricePerUnit << " | " << product->productQuantityPerUnit << " | " << product->productStatus << endl;
	}

	int productID = -1;
	std::cout << "Product ID: ";
	std::cin >> productID;
	Product* tarrProduct = DataAccess::getInstance()->productRepository->getProduct(productID);


	// Please input the amount of items you want to order
	int orderedAmount = -1;
	std::cout << "Please enter the amount of items you want to order: ";
	std::cin >> orderedAmount;
	ProductOrderDescription orderDescription;
	orderDescription.product = tarrProduct;
	orderDescription.quantity = orderedAmount;
	totalOrderedPrice += (tarrProduct->productPricePerUnit * orderedAmount);
	std::cout << totalOrderedPrice << endl;

	temp.orderedProducts = new LinkedList<ProductOrderDescription>;
	temp.orderedProducts->push(orderDescription);

	// Let user to confirm the order or add another product
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

	std::cout << "Added Successfully!" << endl;
	std::cout << "0-Back" << endl;
	string back;
	std::cin >> back;
	if (back == "0") {
		return;
	}
}

