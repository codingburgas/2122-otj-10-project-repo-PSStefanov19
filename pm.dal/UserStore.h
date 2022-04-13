#pragma once

#include "pch.h"

namespace pm::dal 
{
	struct UserStore
	{
		void createUser(pm::types::User user);
		std::vector<pm::types::User> getAll();
		void remove(uint8_t id);
		void update(pm::types::User user);
		pm::types::User getById(uint8_t id);
		pm::types::User getByUsername(std::string username);
		pm::types::User getByEmail(std::string email);
	};
}