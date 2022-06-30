#pragma once
#include "IRepository.h"
#include "TextDataReader.h"
#include <list>
#include "User.h"

class UserRepository : public IRepository {
private:
	virtual void loadData();
private:
	std::string fileLocation;
	TextDataReader *dataReader;
public:
	std::list<User> users;
public:
	UserRepository(std::string fileLocation);
	~UserRepository();

};