#pragma once

#include <iostream>
#include <string>
#include <ctime>

namespace pm
{
	namespace types {
		struct User
		{
			int id;
			std::string username;
			std::string passwordHash;
			std::string firstName;
			std::string lastName;
			std::string email;
			time_t dateOfCreation;

			User(int id,
				std::string username,
				std::string passwordHash,
				std::string firstName,
				std::string lastName,
				std::string email, time_t dateOfCreation);
		};
	}
}
