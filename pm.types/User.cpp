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

pm::types::User::User() 
{
	id = NULL;
	passwordHash = "";
	username = "";
	firstName = "";
	lastName = "";
	email = "";
	dateOfCreation = NULL;
	isAdmin = NULL;
}

int pm::types::User::getId()
{
	return id;
}

std::string pm::types::User::getPasswordHash() 
{
	return passwordHash;
}

std::string pm::types::User::getUsername()
{
	return username;
}

std::string pm::types::User::getFirstName()
{
	return firstName;
}

std::string pm::types::User::getLastName()
{
	return lastName;
}

std::string pm::types::User::getEmail()
{
	return email;
}

time_t pm::types::User::getDateOfCreation() 
{
	return dateOfCreation;
}

bool pm::types::User::getPrivlidges() 
{
	return isAdmin;
}

void pm::types::User::setUsername(std::string newUsername) 
{
	username = newUsername;
}

void pm::types::User::setPasswordHash(std::string newPasswordHash) 
{
	passwordHash = newPasswordHash;
}

void pm::types::User::setFirstName(std::string newFirstName) 
{
	firstName = newFirstName;
}

void pm::types::User::setLastName(std::string newLastName) 
{
	lastName = newLastName;
}
