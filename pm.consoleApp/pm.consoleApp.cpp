#include "../pm.dal/UserManager.h"
#include <iostream>

int main()
{
	pm::dal::UserManager& uMan = pm::dal::UserManager::getInstance();
	uMan.createUser("user1", "pass1", "fname1", "lname1", "email1", 1);
	uMan.createUser("user2", "pass2", "fname2", "lname2", "email2");

	uMan.displayUsers();
}
