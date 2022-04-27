#include "User.h"

pm::types::User::User(int id,std::string username, std::string passwordHash, std::string firstName, std::string lastName, std::string email, time_t dateOfCreation)
{
    this->id = id;
    this->username = username;
    this->passwordHash = passwordHash;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->dateOfCreation = dateOfCreation;
}
