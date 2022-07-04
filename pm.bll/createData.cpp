#include "createData.h"

/**
 * . Function that checks if string contains substrings
 * 
 * \param s String to be checked
 * \param ...args Parameter pack with all substrings
 * \return Boolean value representing if any substring was found
 */
template<class...A>
bool verifyString(std::string s, A...args)
{
    return ((s.find(args) != std::string::npos) && ...);
}

/**
 * . Function that retirns current time
 * 
 * \return time_t formatted time
 */
time_t getCurrentTime() 
{
    return time(0);
}

/**
 * . Function that verifies user data and creates user
 * 
 * \param username Username of new user
 * \param password Password of new user
 * \param firstName First name of new user
 * \param lastName Last name of new user
 * \param email Email of new user
 * \param isAdmin Privlidges of new user
 */
void pm::bll::createUser(std::string username,
    std::string password, 
    std::string firstName,
    std::string lastName,
    std::string email,
    bool isAdmin)
{
    // Input verificaition
    // using guard clauses
    
    if (verifyString(username, " ")) 
    {
        return;
    }
    if (verifyString(password, " ")) 
    {
        return;
    }
    if (verifyString(firstName, " ")) 
    {
        return;
    }
    if (verifyString(lastName, " ")) 
    {
        return;
    }
    if (!verifyString(email, "@", ".")) 
    {
        return;
    }

    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();

    u.createUser(username, md5(password), firstName, lastName, email, getCurrentTime(), isAdmin);
}
