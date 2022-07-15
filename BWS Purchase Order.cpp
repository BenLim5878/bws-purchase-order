// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Tree.h"
#include "DataAccess.h"
#include "Menu.h"
#include "Header.h"
#include "Session.h"
#include "Menu.h"
#include "PurchaseOrderReportView.h"

using namespace std;

DataAccess* DataAccess::instance = 0;
Session* Session::instance = 0;

int main()
{
	View::PurchaseOrderReportView view;
	view.show();

}

