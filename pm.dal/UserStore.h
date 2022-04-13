#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../pm.types/User.h"

namespace pm::dal
{
	struct UserStore
	{
		void createUser(pm::types::User user);
		std::vector<pm::types::User> getAll();
		void remove(std::uint8_t id);
		void update(pm::types::User user);
		pm::types::User getById(std::uint8_t id);
		pm::types::User getByUsername(std::string username);
		pm::types::User getByEmail(std::string email);
	};
}