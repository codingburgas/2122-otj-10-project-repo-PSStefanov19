#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>

#include "../pm.tools/csv.h"
#include "../pm.types/User.h"

namespace pm
{
	namespace dal
	{
		/**
		 * . Singleton class that manages users
		 */
		class UserManager
		{
		public:
			/**
			 * . Static function that return instance of the class
			 * 
			 * \return Address of the instanced class
			 */
			static UserManager& getInstance() 
			{
				static pm::dal::UserManager u;
				return u;
			}

			// Delete copy constructor
			UserManager(UserManager const&) = delete;
			
			// Delete assigment operator
			void operator=(UserManager const&) = delete;

			// Functions to operate on users and database
			void createUser(const std::string username,
				const std::string passwordHash,
				const std::string firstName,
				const std::string lastName,
				const std::string email,
				const time_t dateOfCreation = 0,
				const bool isAdmin = false);
			void deleteUserById(int);

			std::vector<pm::types::User> getAllUsers();
			void createDB();

			int getLastId();

			pm::types::User getUserByUsername(std::string username);

		private:
			// Empty default constructor
			UserManager() {}

			// File stream for the database
			std::fstream db;
		};
	}
}