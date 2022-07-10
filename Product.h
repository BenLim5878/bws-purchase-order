#pragma once
#include <string>

class ProductCategory {
public:
	int categoryID = -1;
	std::string categoryTitle;
	std::string categoryDescription;
public:
	ProductCategory(){}
	ProductCategory(int categoryID, std::string categoryTitle, std::string categoryDescription) {
		this->categoryID = categoryID;
		this->categoryTitle = categoryTitle;
		this->categoryDescription = categoryDescription;
	}
	~ProductCategory(){}
};

enum ProductStatus {
	OnStock,
	OutOfStock
};

class Product
{
private:
	int productID;
public:
	ProductCategory* productCategory;
	std::string productBrand;
	std::string productName;
	std::string productDescription;
	long productPricePerUnit;
	long productDiscountRate;
	int productStockUnit;
	int productQuantityPerUnit;
	ProductStatus productStatus;
public:
	Product();
	~Product();
public:
	int getProductID();
	void setProductID(int id);
};

