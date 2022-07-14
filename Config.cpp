#include "Config.h"

Config::Config()
{
	this->productCategorySample = new LinkedList<ProductCategory>();
	productCategorySample->push(*new ProductCategory(0, "Electronics","Category for electronics"));
	productCategorySample->push(*new ProductCategory(1, "Utensils","Category for utensils"));
	productCategorySample->push(*new ProductCategory(2, "Others","Category for others"));
}

Config::~Config()
{
}
