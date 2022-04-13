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
        std::string email;
        time_t dateOfCreation;


        User(uint8_t id,
            std::string username,
            std::string passwordHash,
            std::string firstName,
            std::string lastName,
            std::string email,
            time_t dateOfCreation
            ) : id(id),
            username(username),
            passwordHash(passwordHash),
            firstName(firstName),
            lastName(lastName),
            email(email),
            dateOfCreation(dateOfCreation) {}
    };
}