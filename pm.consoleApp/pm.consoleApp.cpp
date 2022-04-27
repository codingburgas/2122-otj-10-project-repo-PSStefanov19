#include "../pm.dal/UserStore.h"
#include "../pm.types/User.h"
#include <iostream>

int main()
{
	pm::dal::UserStore uStore;

	uStore.createUser("Mitko123", "123", "fName", "lName", "email", 12);
}
