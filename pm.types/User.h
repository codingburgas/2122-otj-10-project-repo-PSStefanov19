#pragma once
#include <iostream>
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

	public:
		pm::types::User(int,
			std::string,
			std::string,
			std::string,
			std::string,
			std::string,
			time_t);
		int getId();

		std::string getUsername();
	};
}