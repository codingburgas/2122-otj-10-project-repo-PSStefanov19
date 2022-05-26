#include "UserManager.h"

pm::dal::UserManager& pm::dal::UserManager::getInstance()
{
    static pm::dal::UserManager u;
    return u;
}

void pm::dal::UserManager::createUser(const std::string username,
	const std::string passwordHash,
	const std::string firstName,
	const std::string lastName,
	const std::string email,
	const time_t dateOfCreation)
{
    pm::types::User u(users.size() + 1, username, passwordHash, firstName, lastName, email, dateOfCreation);
    users.push_back(u);
}

void pm::dal::UserManager::displayUsers() 
{
	for (pm::types::User user : users) 
	{
		std::cout << "Id: " << user.getId() << "\n";
		std::cout << "UserName: " << user.getUsername() << "\n";
		std::cout << "\n";
		std::cout.flush();
	}
}