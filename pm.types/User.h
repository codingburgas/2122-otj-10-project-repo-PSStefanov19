#pragma once

#include "pch.h"

namespace pm::types 
{
	struct User
	{
		uint8_t id;
		std::string username;
		std::string passwordHash;
		std::string firstName;
		std::string lastName;
		time_t dateOfCreation;
		uint8_t idOfCreator;
		time_t dateOfLastChange;
		uint8_t idOfLastChangeUser;
	};
}