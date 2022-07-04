#pragma once

#include "../pm.dal/UserManager.h"
#include <vector>

namespace pm
{
    namespace bll
    {
        pm::types::User login(std::string username, std::string password);
    }
}
