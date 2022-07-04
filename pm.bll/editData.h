#pragma once

#include "../pm.dal/UserManager.h"

#include <string>
#include <vector>

void editUser(int id,
    std::string username,
    std::string password,
    std::string firstName,
    std::string lastName);
