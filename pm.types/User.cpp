#include "User.h"

pm::types::User::User(int i,
	std::string uname,
	std::string passwd,
	std::string fName,
	std::string lName,
	std::string e,
	time_t dOC,
	bool isAdmin)
{
	id = i;
	passwordHash = passwd;
	username = uname;
	firstName = fName;
	lastName = lName;
	email = e;
	dateOfCreation = dOC;
	this->isAdmin = isAdmin;
}

int pm::types::User::getId()
{
	return id;
}

std::string pm::types::User::getUsername()
{
	return username;
}

std::string pm::types::User::getPassword()
{
	return passwordHash;
}
