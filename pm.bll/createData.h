#pragma once

#include "../pm.dal/UserManager.h"

#include <string>
#include <algorithm>
#include <time.h>

namespace pm
{
    namespace bll
    {
        void createUser(std::string username,
            std::string password,
            std::string firstName,
            std::string lastName,
            std::string email,
            bool isAdmin);
    }
}
