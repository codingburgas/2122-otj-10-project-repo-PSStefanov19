#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <filesystem>

#include "../pm.tools/csv.h"
#include "../pm.types/User.h"

namespace pm
{
	namespace dal
	{
		class UserManager
		{
		public:
			static UserManager& getInstance() 
			{
				static pm::dal::UserManager u;
				return u;
			}

			UserManager(UserManager const&) = delete;
			void operator=(UserManager const&) = delete;

			void createUser(const std::string username,
				const std::string passwordHash,
				const std::string firstName,
				const std::string lastName,
				const std::string email,
				const time_t dateOfCreation = 0,
				const bool isAdmin = false);

			void displayUsers();
			void createDB();

			void setId(int newId);
			void syncId();
		private:
			UserManager() {}

			int lastId = 0;
			std::fstream db;
		};
	}
}