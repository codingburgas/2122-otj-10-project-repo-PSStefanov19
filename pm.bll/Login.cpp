#include "login.h"

pm::types::User login(std::string username, std::string password)
{
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();
    
    pm::types::User sessionUser = u.getUserByUsername(username);

    if (sessionUser.getPasswordHash() == md5(password))
    {
        return sessionUser;
    }
    return pm::types::User();
}
