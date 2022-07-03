#pragma once
#include <iostream>
#include "../pm.tools/md5.h"

namespace pm
{
	namespace types 
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
			pm::types::User();
			int getId();
			std::string getPasswordHash();
			std::string getUsername();
			std::string getFirstName();
			std::string getLastName();
			std::string getEmail();
		};
	}
}