#include "retrieveData.h"

/**
 * . Function that formats a vector of users
 * 
 * \param users Vector of users
 * \return Vector of strings with formated user information
 */
std::vector<std::string> formatUsers(std::vector<pm::types::User> users) 
{
    std::vector<std::string> formattedUsers;
    std::string userInfo;
    
    for (auto user : users) 
    {
        userInfo += std::to_string(user.getId());
        userInfo.append(11 - std::to_string(user.getId()).size(), ' ');

        userInfo += user.getUsername();
        userInfo.append(17 - user.getUsername().size(), ' ');

        userInfo += user.getFirstName();
        userInfo.append(19 - user.getFirstName().size(), ' ');

        userInfo += user.getLastName();
        userInfo.append(18 - user.getLastName().size(), ' ');

        userInfo += user.getEmail();
        formattedUsers.push_back(userInfo);

        userInfo = "";
    }

    return formattedUsers;
}

/**
 * . Function to return vector of formatted user information
 * 
 * \return Formatted user information
 */
std::vector<std::string> pm::bll::getAllUsersFormatted()
{
    pm::dal::UserManager& uman = pm::dal::UserManager::getInstance();

    uman.getAllUsers();

    std::vector<std::string> formattedUsers = formatUsers(uman.getAllUsers());

    return formattedUsers;
}
