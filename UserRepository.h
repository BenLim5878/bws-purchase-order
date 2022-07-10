#pragma once
#include "IRepository.h"
#include "TextDataReader.h"
#include "LinkedList.h"
#include "User.h"
#include "Administrator.h"
#include "SalesOrderExecutive.h"

class UserRepository : public IRepository {
private:
	virtual void loadData();
private:
	std::string fileLocation;
	TextDataReader *dataReader;
public:
	LinkedList<User> *users;
	LinkedList<Administrator> *adminstrator;
	LinkedList<SalesOrderExecutive> *salesOrderExecutive;
public:
	int getTotalUser();
	User* getUserByID(int userID);
	Administrator* getAdminByID(int adminID);
	SalesOrderExecutive* getSOEByID(int SOEID);
public:
	UserRepository(std::string fileLocation);
	~UserRepository();

};