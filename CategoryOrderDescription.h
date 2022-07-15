#pragma once
#include "Product.h"

struct CategoryOrderDescription {
public:
	ProductCategory* productCategory;
	float totalPrice = 0;
	int totalQuantity = 0;
};