#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <filesystem>

#include "../pm.types/User.h"

namespace pm::dal
{
	class UserManager 
	{
	public:
		static UserManager& getInstance();

		void createUser(const std::string username,
			const std::string passwordHash,
			const std::string firstName,
			const std::string lastName,
			const std::string email,
			const time_t dateOfCreation = 0);

		void displayUsers();
		void createDB();
	private:
		UserManager() {};
		UserManager(const UserManager&) {};
		
		std::list<pm::types::User> users;
		std::fstream db;
	};
}