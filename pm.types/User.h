#pragma once

#include "pch.h"

namespace pm::types
{
	struct User
	{
		int id;
		std::string username;
		std::string passwordHash;
		std::string firstName;
		std::string lastName;
		std::string email;
		time_t dateOfCreation;
	};
}
