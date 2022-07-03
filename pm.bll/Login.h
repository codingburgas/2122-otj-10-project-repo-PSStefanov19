#pragma once

#include "../pm.dal/UserManager.h"
#include <vector>

pm::types::User login(std::string username, std::string password);
