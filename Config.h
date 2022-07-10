#pragma once
#include "LinkedList.h"
#include "Product.h"

class Config {
public:
	LinkedList<ProductCategory>* productCategorySample;
public:
	Config();
	~Config();
};
