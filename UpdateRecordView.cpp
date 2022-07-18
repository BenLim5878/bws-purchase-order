#include <iostream>
#include "PurchaseOrderTable.h"
#include "PurchaseOrderRepository.h"
#include "UpdateRecordView.h"
#include "Header.h"
#include "Time.h"
#include "DataAccess.h"
#include "Payment.h"

using namespace std;
int oid;
string back;
string decision;
string name;
auto timeNow = std::time(0);
auto timeTm = std::localtime(&timeNow);

void product() {
	std::cout << "Please enter the Order ID: ";
	std::cin >> oid;

	PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(oid);
	for (int i = 0; i < data->getPOID(); i++)
	{
		if (data->getPOID() == oid) {
			for (int i = 0; i < data->getPOID(); i++) {
				for (int j = 0; j < data->orderedProducts->length; j++) {
					int stringLen = data->orderedProducts->get(j)->product->productName.length();
				}
			}
			int c = 1;
			int totalProducts = data->orderedProducts->length;
			if (data->orderedProducts->length > 1) {
				std::cout << "==== Product Name ====" << endl;
				for (int j = 0; j < totalProducts; j++) {
					std::cout << " " << c++ << " " << data->orderedProducts->get(j)->product->productName << endl;
					std::cout << "" << endl;
				}
			}
		}
		//std::cout << "Please enter the Product Name: ";
		//std::cin >> name;

		if (data->getPOID() == oid /*and data->orderedProducts->get(i)->product->productName == name*/) {
			auto ven = DataAccess::getInstance()->vendorRepository;
			auto vdata = ven->vendors;
			PurchaseOrder temp;
			int vendorID = -1;
			float totalOrderedPrice = 0;
			// Please re-select which vendor to order from
			std::cout << "Please update which vendor to order from: " << endl;
			std::cout << " " << "Vendor ID" << " | " << "Name" << " | " << "Description" << " | " << "Status" << endl;
			for (int i = 0; i < vdata->length; i++)
			{
				auto vrec = vdata->get(i);
				std::cout << " " << vrec->getVendorID() << " | " << vrec->vendorName << " | " << vrec->vendorDescription << " | " << Vendor::vendorStatusToString(vrec->vendorStatus) << endl;
			}
			std::cout << "Update Vendor ID: ";
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
			std::cout << "Update Product ID: ";
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

			temp.setPOID(oid);
			temp.orderedProducts = new LinkedList<ProductOrderDescription>;
			temp.orderedProducts->push(orderDescription);
			temp.timeCreated = data->timeCreated, "%Y-%m-%d.%H:%M:%S";
			temp.paymentRecord.paymentMethod = data->paymentRecord.paymentMethod;

			std::cout << "" << endl;
			std::cout << "UPDATED!" << endl;

			DataAccess::getInstance()->purchaseOrderRepository->deletePurchaseOrder(oid);
			DataAccess::getInstance()->purchaseOrderRepository->addPurchaseOrder(temp);

			return;
		}
	}
}

void paymentMethod() {

	PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(oid);
	if (data->getPOID() == oid) {
		std::cout << "Please enter the Order ID: ";
		std::cin >> oid;

		PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(oid);
		for (int i = 0; i < data->getPOID(); i++)
		{
			if (data->getPOID() == oid) {
				for (int i = 0; i < data->getPOID(); i++) {
					for (int j = 0; j < data->orderedProducts->length; j++) {
						int stringLen = data->orderedProducts->get(j)->product->productName.length();
					}
				}
				int c = 1;
				int totalProducts = data->orderedProducts->length;
				if (data->orderedProducts->length > 1) {
					std::cout << "==== Product Name ====" << endl;
					for (int j = 0; j < totalProducts; j++) {
						std::cout << " " << c++ << " " << data->orderedProducts->get(j)->product->productName << endl;
						std::cout << "" << endl;
					}
				}
			}

			if (data->getPOID() == oid /*and data->orderedProducts->get(i)->product->productName == name*/) {
				auto ven = DataAccess::getInstance()->vendorRepository;
				auto vdata = ven->vendors;
				PurchaseOrder temp;
				int vendorID = -1;
				float totalOrderedPrice = 0;
				// Please re-select which vendor to order from
				std::cout << " " << endl;
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

				 //Please input the amount of items you want to order
				int orderedAmount = -1;
				std::cout << "Please enter the amount of items you want to order: " << endl;
				std::cout << "Amount of items:";
				std::cin >> orderedAmount;
				ProductOrderDescription orderDescription;
				orderDescription.product = tarrProduct;
				orderDescription.quantity = orderedAmount;
				totalOrderedPrice += (tarrProduct->productPricePerUnit * orderedAmount);

				int userChoice = -1;
				std::cout << " " << endl;
				std::cout << "*** Payment Method ***" << endl;
				std::cout << "0-Credit Card" << endl;
				std::cout << "1-Check" << endl;
				std::cout << "2-Bank Transfer" << endl;
				std::cout << "Please choose your payment method:" << endl;
				std::cout << "Payment Method: ";
				std::cin >> userChoice;

				temp.setPOID(oid);
				temp.orderedProducts = new LinkedList<ProductOrderDescription>;
				temp.orderedProducts->push(orderDescription);
				Payment* tempPayment = new Payment();
				tempPayment->paymentMethod = static_cast<PaymentMethod>(userChoice);

				temp.timeCreated = data->timeCreated, "%Y-%m-%d.%H:%M:%S";

				std::cout << "" << endl;
				std::cout << "UPDATED!" << endl;

				DataAccess::getInstance()->purchaseOrderRepository->deletePurchaseOrder(oid);
				DataAccess::getInstance()->purchaseOrderRepository->addPurchaseOrder(temp);
			
				return;
			}
		}
	}
}
	

void status() {
	std::cout << "Please enter the Order ID: ";
	std::cin >> oid;

	PurchaseOrder* data = DataAccess::getInstance()->purchaseOrderRepository->getPurchaseOrder(oid);
	for (int i = 0; i < data->getPOID(); i++)
	{
		if (data->getPOID() == oid) {
			for (int i = 0; i < data->getPOID(); i++) {
				for (int j = 0; j < data->orderedProducts->length; j++) {
					int stringLen = data->orderedProducts->get(j)->product->productName.length();
				}
			}
			int c = 1;
			int totalProducts = data->orderedProducts->length;
			if (data->orderedProducts->length > 1) {
				std::cout << "==== Product Name ====" << endl;
				for (int j = 0; j < totalProducts; j++) {
					std::cout << " " << c++ << " " << data->orderedProducts->get(j)->product->productName << endl;
					std::cout << "" << endl;
				}
			}
		}
		//std::cout << "Please enter the Product Name: ";
		//std::cin >> name;

		if (data->getPOID() == oid /*and data->orderedProducts->get(i)->product->productName == name*/) {
			auto ven = DataAccess::getInstance()->vendorRepository;
			auto vdata = ven->vendors;
			PurchaseOrder temp;
			int vendorID = -1;
			float totalOrderedPrice = 0;
			// Please re-select which vendor to order from
			std::cout << " " << endl;
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
			std::cout << "Update Product ID: ";
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

			int userChoice = -1;
			std::cout << " " << endl;
			std::cout << "*** Order Status ***" << endl;
			std::cout << "1-Sent" << endl;
			std::cout << "2-Processing" << endl;
			std::cout << "3-Delivering" << endl;
			std::cout << "4-Complete" << endl;
			std::cout << "Please select the Order Status:" << endl;
			std::cout << "Order Status: ";
			std::cin >> userChoice;

			temp.setPOID(oid);
			temp.orderedProducts = new LinkedList<ProductOrderDescription>;
			temp.orderedProducts->push(orderDescription);
			temp.timeCreated = data->timeCreated, "%Y-%m-%d.%H:%M:%S";
			temp.paymentRecord.paymentMethod = data->paymentRecord.paymentMethod;

			temp.orderStatus = static_cast<OrderStatus>(userChoice);

			std::cout << "" << endl;
			std::cout << "UPDATED!" << endl;

			DataAccess::getInstance()->purchaseOrderRepository->deletePurchaseOrder(oid);
			DataAccess::getInstance()->purchaseOrderRepository->addPurchaseOrder(temp);

			return;
		}
	}
}

void View::UpdateRecordView::show()
{
	system("CLS");
	cin.ignore();
	ViewHeader::Header head;
	head.display();
	displayTime::Time dtime;
	dtime.show();
	// Show the Purchase Order Table
	ViewComponent::PurchaseOrderTable poTable(DataAccess::getInstance()->purchaseOrderRepository->purchaseOrder);
	poTable.show();

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


	std::cout << "Please select which data you want to update: " << endl;
	std::cout << "1-Product (Name, Price, Qty)" << endl;
	std::cout << "2-Payment Method" << endl;
	std::cout << "3-Status" << endl;
	std::cout << "Please Select >>";
	int selection;
	cin >> selection;

	switch (selection) {
	case 1:
		product();
		break;
	case 2:
		paymentMethod();
		break;
	case 3:
		status();
		break;
	}

}
