#pragma once

#include "../pm.dal/UserManager.h"
#include "../pm.dal/TeamManager.h"

#include <vector>
#include <string>

namespace pm
{
    namespace bll
    {
        std::vector<std::string> getAllUsersFormatted();
    }
}
