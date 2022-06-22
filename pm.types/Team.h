#pragma once
#include <vector>
#include <string>
#include "User.h"
namespace pm::types {
	class Team
	{
	public:
		std::string getTeamName();
		std::vector<User> getUsers();
	private:
		std::string teamName;
		std::vector<User> users;
	};
}
