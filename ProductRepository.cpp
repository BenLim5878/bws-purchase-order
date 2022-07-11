#include "ProductRepository.h"
#include "Config.h"
//ProductID, (0)
//ProductCategoryID, (1)
//ProductBrandName, (2)
//ProductName, (3)
//ProductDescription, (4)
//ProductPricePerUnit, (5)
//ProductQuantityPerUnit, (6)
//ProductStockUnit, (7)
//ProductDiscountRate, (8)
//ProductStatus(9)

void ProductRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		Product temp;
		// Product ID
		temp.setProductID(std::stoi(record.at(0)));
		// Product Category ID
		int categoryID = std::stoi(record.at(1));
		temp.productCategory = getProductCategory(categoryID);
		// Product Brand Name
		temp.productBrand = record.at(2);
		// Product Name
		temp.productName = record.at(3);
		// Product Description
		temp.productDescription = record.at(4);
		// Product Price Per Unit
		temp.productPricePerUnit = std::stoll(record.at(5));
		// Product Quantity Per Unit
		temp.productQuantityPerUnit = std::stoi(record.at(6));
		// Product Stock Unit
		temp.productStockUnit = std::stoi(record.at(7));
		// Product Discount Rate
		temp.productDiscountRate = std::stoll(record.at(8));
		// Product Status
		temp.productStatus = static_cast<ProductStatus>(std::stoi(record.at(8)));
		
		// Insert into tree
		insertProduct(temp);
	}
}

void ProductRepository::initialize_tree()
{
	this->productCategoryTree = new Tree();
	CategoryNode* rootNode = new CategoryNode();
	rootNode->data = *new ProductCategory(-1, "Root category", "Root category of product");
	this->productCategoryTree->root = rootNode;

	for (int i = 0; i < this->productCategory.length; i++) {
		insertCategory(*this->productCategory.get(i));
	}
}

void ProductRepository::insertProduct(Product product)
{
	ProductCategory* category = product.productCategory;
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(*this->productCategoryTree->root->getChild()->get(i));
		if (categoryNode->data.categoryID == category->categoryID) {
			ProductNode* productNode = new ProductNode();
			productNode->data = product;
			categoryNode->addChild(productNode);
			break;
		}
	}
}

void ProductRepository::insertCategory(ProductCategory productCategory)
{
	CategoryNode* categoryNode = new CategoryNode();
	categoryNode->data = productCategory;
	this->productCategoryTree->root->addChild(categoryNode);
}

Product* ProductRepository::getProduct(std::string categoryName, int nthChild)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		if (categoryNode->data.categoryTitle == categoryName) {
			ProductNode* productNode = static_cast<ProductNode*>(categoryNode->getChild(nthChild));
			return &productNode->data;
		}
	}
}

Product* ProductRepository::getProduct(int categoryID, int nthChild)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(*this->productCategoryTree->root->getChild()->get(i));
		if (categoryNode->data.categoryID == categoryID) {
			ProductNode* productNode = static_cast<ProductNode*>(categoryNode->getChild(nthChild));
			return &productNode->data;
		}
	}
}

Product* ProductRepository::getProduct(int productID)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		for (int j = 0; j < getTotalItemByCategory(categoryNode->data.categoryID); j++) {
			ProductNode* productNode = static_cast<ProductNode*>(categoryNode->getChild(j));
			if (productNode->data.getProductID() == productID) {
				return &productNode->data;
			}
		}
	}
}

ProductCategory* ProductRepository::getProductCategory(std::string categoryName)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(*this->productCategoryTree->root->getChild()->get(i));
		if (categoryNode->data.categoryTitle == categoryName) {
			return &categoryNode->data;
		}
	}
}

ProductCategory* ProductRepository::getProductCategory(int categoryID)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		if (categoryNode->data.categoryID == categoryID) {
			return &categoryNode->data;
		}
	}
}

void ProductRepository::deleteProduct(Product* product)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		if (categoryNode->data.categoryID == product->productCategory->categoryID ) {
			for (int j = 0; j < getTotalItemByCategory(product->productCategory->categoryID); j++) {
				ProductNode* productNode = static_cast<ProductNode*>(categoryNode->getChild(i));
				if (productNode->data.getProductID() == product->getProductID()) {
					categoryNode->deleteChild(productNode);
					break;
				}
			}
		}
	}
}

void ProductRepository::deleteProduct(int productID)
{
	Product* product = getProduct(productID);
	if (product) {
		deleteProduct(product);
	}
}

int ProductRepository::getTotalCategory()
{
	int totalCategory = this->productCategoryTree->root->getChild()->length;
	return totalCategory;
}

int ProductRepository::getTotalItem()
{
	int total = 0;
	for (int i = 0; i < getTotalCategory(); i++) {
		total += getTotalItemByCategory(i);
	}
	return total;
}

int ProductRepository::getTotalItemByCategory(int categoryID)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		if (categoryNode->data.categoryID == categoryID) {
			return categoryNode->getChild()->length;
		}
	}
}

int ProductRepository::getTotalItemByCategory(std::string categoryName)
{
	for (int i = 0; i < getTotalCategory(); i++) {
		CategoryNode* categoryNode = static_cast<CategoryNode*>(this->productCategoryTree->root->getChild(i));
		if (categoryNode->data.categoryTitle == categoryName) {
			return categoryNode->getChild()->length;
		}
	}
}


ProductRepository::ProductRepository(std::string fileLocation)
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();

	// Load sample category data
	Config config;
	this->productCategory = *config.productCategorySample;

	this->initialize_tree();
	this->loadData();

	
}

ProductRepository::~ProductRepository()
{
	delete this->dataReader;
	delete this->productCategoryTree;
}
