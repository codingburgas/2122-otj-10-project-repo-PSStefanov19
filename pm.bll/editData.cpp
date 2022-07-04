#include "editData.h"

/**
 * . Function that edits user information
 * 
 * \param id Id of user to be edited
 * \param username New username of user
 * \param password New password of user
 * \param firstName New first name of user
 * \param lastName New last name of user
 */
void pm::bll::editUser(int id,
    std::string username,
    std::string password,
    std::string firstName,
    std::string lastName)
{
    // Vector of all users
    std::vector<pm::types::User> users;
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();

    users = u.getAllUsers();

    // Clean database and add headers
    std::fstream db("../data/users.csv", std::ios::out | std::ios::trunc);
    db << "Id,Username,Password,FirstName,LastName,Email,DateOfCreation,isAdmin\n";
    db.close();

    // Add all users back to database
    for (auto& user : users) 
    {
        // Change user with selected id
        if (user.getId() == id) 
        {
            user.setUsername(username);
            user.setPasswordHash(md5(password));
            user.setFirstName(firstName);
            user.setLastName(lastName);
        }

        // Add user to database
        u.createUser(user.getUsername(),
            user.getPasswordHash(),
            user.getFirstName(),
            user.getLastName(),
            user.getEmail(),
            user.getDateOfCreation(),
            user.getPrivlidges());
    }
}
