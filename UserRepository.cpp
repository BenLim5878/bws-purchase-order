#include "UserRepository.h"
#include "Administrator.h"
#include "SalesOrderExecutive.h"

void UserRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		if (std::stoi(record.at(3)) == UserRole::Admin) {
			Administrator* admin = new Administrator();
			admin->setUserID(std::stoi(record.at(0)));
			admin->name = record.at(1);
			admin->role = UserRole::Admin;
			admin->phoneNo = record.at(4);
			admin->nationalID = record.at(5);
			admin->setAdminID(std::stoi(record.at(6)));
			this->users.push_back(*admin);
		}
	}
}

UserRepository::UserRepository(std::string fileLocation)
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

UserRepository::~UserRepository()
{
}
