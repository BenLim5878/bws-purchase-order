#include "SalesOrderExecutive.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



int SalesOrderExecutive::getExecutiveID() {
    return this->executiveID;
}

void SalesOrderExecutive::setExecutiveID(int executiveID) {
    this->executiveID = executiveID;
}


