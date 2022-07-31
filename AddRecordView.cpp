#include <iostream>
#include "AddRecordView.h"
#include "PurchaseOrderTable.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include <ctime>
#include "Helper.h"
#include "VendorRepository.h"
#include "Payment.h"
#include "PurchaseOrderView.h"
#include "Helper.h"
#include "VendorTable.h"
#include "VendorProductTable.h"
using namespace std;

void View::AddRecordView::show(bool isInputValid)
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

	// Message when valid input
	if (isInputValid) {
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
				PurchaseOrderView view;
				view.show();
				return;
			}
			else {
				show();
			}
		}
	}

	// Message when invalid input
	if (!isInputValid) {
		std::cout << endl << "Invalid Input. Please try again!" << endl;
	}

	auto ven = DataAccess::getInstance()->vendorRepository;
	auto vdata = ven->vendors;
	PurchaseOrder temp;
	Payment tempPayment;
	int vendorID = -1;
	float totalOrderedPrice = 0;
	// Please select which vendor to order from
	std::cout << "Please select which vendor to order from: " << endl << endl;
	
	// Show vendor table
	ViewComponent::VendorTable vendorTable(ven->vendors);
	vendorTable.show();

	// Vendor
	std::cout << endl << "Vendor ID: ";
	vendorID =  promptNumericInput();
	if (vendorID < 0) {
		show(false);
		return;
	}

	auto vendor = DataAccess::getInstance()->vendorRepository->getVendor(vendorID);
	if (!vendor) {
		show(false);
		return;
	}
	temp.vendor = DataAccess::getInstance()->vendorRepository->getVendor(vendorID);

	// Ordered Products
	temp.orderedProducts = new LinkedList<ProductOrderDescription>;
	bool repeatOrder = false;
	do {
		// Show Product Table
		std::cout << endl << "Please select which product you wish to order from " << temp.vendor->vendorName << " : " << endl << endl;
		ViewComponent::VendorProductTable vendorProductTable(vendorID);
		vendorProductTable.show();

		// Product
		int productID;
		std::cout << endl << "Product ID: ";

		productID = promptNumericInput();
		if (productID < 0) {
			show(false);
			return;
		}

		Product* tarrProduct = DataAccess::getInstance()->productRepository->getProduct(productID);
		if (tarrProduct == nullptr) {
			show(false);
			return;
		}

		// Order Amount
		int orderedAmount;
		std::cout << endl << "Please enter the amount of items you want to order: " << endl << endl;
		std::cout << "Amount of items:";
		orderedAmount = promptNumericInput();
		if (orderedAmount < 0) {
			show(false);
			return;
		}

		// Create Product Order Description
		ProductOrderDescription orderDescription;
		orderDescription.product = tarrProduct;
		orderDescription.quantity = orderedAmount;
		totalOrderedPrice += (tarrProduct->productPricePerUnit * orderedAmount);
		std::cout << "Total Ordered Price: " << totalOrderedPrice << endl;
		temp.orderedProducts->push(orderDescription);

		// Let user to confirm the order or add another product
		std::cout << endl << "*** Please Select ***" << endl;
		std::cout << "1-Confirm Order" << endl;
		std::cout << "2-Add Another Order" << endl;
		std::cout << endl << "Select: ";
		int order;
		order = promptNumericInput();
		if (order <= 0 || order > 2) {
			show(false);
			return;
		}
		switch (order) {
			case 1:
				temp.totalPrice = totalOrderedPrice;
				tempPayment.paymentAmount = totalOrderedPrice;
				repeatOrder = false;
				break;
			case 2:
				repeatOrder = true;
		}
	} while (repeatOrder);

	// Order Status
	temp.orderStatus = OrderStatus::Sent;

	// Let user to choose payment method
	std::cout << endl << "*** Payment Method ***" << endl;
	std::cout << "0-Credit Card" << endl;
	std::cout << "1-Check" << endl;
	std::cout << "2-Bank Transfer" << endl << endl;
	std::cout << "Please choose your payment method:" << endl;
	std::cout << "Payment Method: ";

	int userChoice;
	userChoice = promptNumericInput();
	if (userChoice < 0 || userChoice > 2) {
		show(false);
		return;
	} 
	tempPayment.paymentMethod = static_cast<PaymentMethod>(userChoice);
	tempPayment.createdAt = *timeTm;

	// Add payment into repository
	Payment* addedPayment = DataAccess::getInstance()->paymentRepository->addPayment(tempPayment);
	
	// PaymentRecord
	temp.paymentRecord = *addedPayment;
	temp.timeCreated = *timeTm;


	DataAccess::getInstance()->purchaseOrderRepository->addPurchaseOrder(temp);


	std::cout << " " << endl;
	std::cout << "Purchase Order added successfully!" << endl;
	std::cout << " " << endl;
	system("pause");
	PurchaseOrderView view;
	view.show();
}

