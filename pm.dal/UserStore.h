#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../pm.types/User.h"

namespace pm
{
	namespace dal {
		struct UserStore
		{
			static std::vector<pm::types::User> users;
			void createUser(std::string username, std::string passwordHash, std::string firstName, std::string lastName, std::string email, time_t dateOfCreation);
			/*std::vector<pm::types::User> getAll();
			void remove(std::uint8_t id);
			void update(pm::types::User user);
			pm::types::User getById(std::uint8_t id);
			pm::types::User getByUsername(std::string username);
			pm::types::User getByEmail(std::string email);*/
			static int getMaxId();
		};
	}
}