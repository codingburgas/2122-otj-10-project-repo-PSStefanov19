#pragma once
#include <iostream>
#include "../pm.tools/md5.h"

namespace pm::types
{
	class User
	{
	private:
		int id = 0;
		std::string username;
		std::string passwordHash;
		std::string firstName;
		std::string lastName;
		std::string email;
		time_t dateOfCreation;
		bool isAdmin;
	public:
		pm::types::User(int,
			std::string,
			std::string,
			std::string,
			std::string,
			std::string,
			time_t,
			bool);
		int getId();

		std::string getUsername();

		std::string getPassword();
	};
}