#include "createData.h"

template<class...A>
bool verifyString(std::string s, A...args)
{
    return ((s.find(args) != std::string::npos) && ...);
}

time_t getCurrentTime() 
{
    return time(0);
}

void createUser(std::string username,
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
