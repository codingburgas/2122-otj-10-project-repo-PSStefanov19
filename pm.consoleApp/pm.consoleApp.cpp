#include "../pm.dal/UserStore.h"
#include "../pm.types/User.h"
#include <iostream>

int main()
{
	pm::types::User user = { 1, "Pres", "123", "abc", "def", "pp@codingburgas.bg", 12 };
	pm::dal::UserStore uStore;

	uStore.createUser(user);

	auto allUsers = uStore.getAll();

	for (const auto user : allUsers) 
	{
		std::cout << user.firstName << std::endl;
	}
}
