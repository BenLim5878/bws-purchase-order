#include "UserRepository.h"

void UserRepository::loadData()
{
	for (std::list<std::string>::iterator i = this->dataReader->context->begin(); i != this->dataReader->context->end(); ++i) {
		std::vector<std::string> record = this->dataReader->splitDelimeter(*i);
		if (std::stoi(record.at(4)) == UserRole::Admin) {
			Administrator admin;
			admin.setUserID(std::stoi(record.at(0)));
			admin.name = record.at(1);
			admin.emailAddress = record.at(2);
			admin.role = UserRole::Admin;
			admin.setPwd(record.at(3));
			admin.phoneNo = record.at(5);
			admin.nationalID = record.at(6);
			admin.setAdminID(std::stoi(record.at(7)));
			this->users->push(admin);
			this->adminstrator->push(admin);
		}
		else {
			SalesOrderExecutive soe;
			soe.setUserID(std::stoi(record.at(0)));
			soe.name = record.at(1);
			soe.emailAddress = record.at(2);
			soe.role = UserRole::SOE;
			soe.setPwd(record.at(3));
			soe.phoneNo = record.at(5);
			soe.nationalID = record.at(6);
			soe.setExecutiveID(std::stoi(record.at(7)));
			this->users->push(soe);
			this->salesOrderExecutive->push(soe);
		}
	}
}

int UserRepository::getTotalUser()
{
	return this->users->length;
}

User* UserRepository::getUserByID(int userID)
{
	User* res = nullptr;
	for (int i = 0; i < this->users->length; i++) {
		User* user = this->users->get(i);
		if (user->getUserID() == userID) {
			res = user;
			break;
		}
	}
	return res;
}

Administrator* UserRepository::getAdminByID(int adminID)
{
	Administrator* res = nullptr;
	for (int i = 0; i < this->adminstrator->length; i++) {
		Administrator* admin = this->adminstrator->get(i);
		if (admin->getAdminID() == adminID) {
			res = admin;
			break;
		}
	}
	return res;
}

SalesOrderExecutive* UserRepository::getSOEByID(int SOEID)
{
	SalesOrderExecutive* res = nullptr;
	for (int i = 0; i < this->salesOrderExecutive ->length; i++) {
		SalesOrderExecutive* soe = this->salesOrderExecutive->get(i);
		if (soe->getExecutiveID() == SOEID) {
			res = soe;
			break;
		}
	}
	return res;
}

UserRepository::UserRepository(std::string fileLocation):users(new LinkedList<User>()),adminstrator(new LinkedList<Administrator>()), salesOrderExecutive(new LinkedList<SalesOrderExecutive>())
{
	this->dataReader = new TextDataReader(fileLocation);
	this->dataReader->readFile();
	this->loadData();
}

UserRepository::~UserRepository()
{
}

