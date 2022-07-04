#include "User.h"

/**
 * . Constructor for user class
 * 
 * \param i Id of user
 * \param uname Username of user
 * \param passwd Password of user
 * \param fName First name of user
 * \param lName Last name of user
 * \param e Email of user
 * \param dOC Date of creation of user
 * \param isAdmin Privlidges of user
 * \return Does not return anyting
 */
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

/**
 * . Default constructor of user
 *   Creates an empty user
 * 
 * \return 
 */
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

/**
 * . Function to return id of user
 * 
 * \return Returns Id
 */
int pm::types::User::getId()
{
	return id;
}

/**
 * . Function to return hashed password of user
 * 
 * \return Returns hashed password
 */
std::string pm::types::User::getPasswordHash() 
{
	return passwordHash;
}

/**
 * . Function to return username of user
 * 
 * \return Returns username
 */
std::string pm::types::User::getUsername()
{
	return username;
}

/**
 * . Function to return first name of user
 * 
 * \return Returns first name
 */
std::string pm::types::User::getFirstName()
{
	return firstName;
}

/**
 * . Function to return last name of user
 * 
 * \return Returns last name
 */
std::string pm::types::User::getLastName()
{
	return lastName;
}

/**
 * . Function to return email of user
 * 
 * \return Returns email
 */
std::string pm::types::User::getEmail()
{
	return email;
}

/**
 * . Function to return date of creation of user
 * 
 * \return Returns date of creation
 */
time_t pm::types::User::getDateOfCreation() 
{
	return dateOfCreation;
}

/**
 * . Funciton to return privlidges of user
 * 
 * \return Returns privlidges
 */
bool pm::types::User::getPrivlidges() 
{
	return isAdmin;
}

/**
 * . Sets new username to user
 * 
 * \param newUsername New username for the user
 */
void pm::types::User::setUsername(std::string newUsername) 
{
	username = newUsername;
}

/**
 * . Sets new hashed password to user
 * 
 * \param newPasswordHash New hashed password for user
 */
void pm::types::User::setPasswordHash(std::string newPasswordHash) 
{
	passwordHash = newPasswordHash;
}

/**
 * . Sets new first name to user
 * 
 * \param newFirstName New first name for user
 */
void pm::types::User::setFirstName(std::string newFirstName) 
{
	firstName = newFirstName;
}

/**
 * . Sets new last name to user
 * 
 * \param newLastName New last name for user
 */
void pm::types::User::setLastName(std::string newLastName) 
{
	lastName = newLastName;
}
