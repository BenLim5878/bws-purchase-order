#pragma once
#include "IRepository.h"
#include "TextDataReader.h"
#include "Tree.h"
#include <string>
#include "Product.h"

class ProductRepository: public IRepository
{
private:
	virtual void loadData();
	void initialize_tree();
private:
	std::string fileLocation;
	TextDataReader* dataReader;
public:
	Tree* productCategoryTree;
	LinkedList<ProductCategory> productCategory;
public:
	void insertProduct(Product product);
	void insertCategory(ProductCategory productCategory);
	Product* getProduct(std::string categoryName, int nthChild);
	Product* getProduct(int categoryID, int nthChild);
	ProductCategory* getProductCategory(std::string categoryName);
	ProductCategory* getProductCategory(int categoryID);
	void deleteProduct(Product* product);
public:
	int getTotalCategory();
	int getTotalItem();
	int getTotalItemByCategory(int categoryID);
	int getTotalItemByCategory(std::string categoryName);
public:
	ProductRepository(std::string fileLocation);
	~ProductRepository();

};

class ProductNode :public TreeNode {
public:
	Product data;
};


class CategoryNode : public TreeNode {
public:
	ProductCategory data;
};

