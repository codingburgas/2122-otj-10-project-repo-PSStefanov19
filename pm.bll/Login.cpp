#include "login.h"

/**
 * . Function that checks login informaion of user
 * 
 * \param username Username of user
 * \param password Password of user
 * \return Logged in user
 */
pm::types::User pm::bll::login(std::string username, std::string password)
{
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();
    
    pm::types::User sessionUser = u.getUserByUsername(username);

    if (sessionUser.getPasswordHash() == md5(password))
    {
        return sessionUser;
    }

    // If log in was unsuccessful return NULL user
    return pm::types::User();
}
