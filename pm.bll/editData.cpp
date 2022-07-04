#include "editData.h"

void pm::bll::editUser(int id,
    std::string username,
    std::string password,
    std::string firstName,
    std::string lastName)
{
    std::vector<pm::types::User> users;
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();

    users = u.getAllUsers();

    std::fstream db("../data/users.csv", std::ios::out | std::ios::trunc);
    db << "Id,Username,Password,FirstName,LastName,Email,DateOfCreation,isAdmin\n";
    db.close();

    for (auto& user : users) 
    {
        if (user.getId() == id) 
        {
            user.setUsername(username);
            user.setPasswordHash(md5(password));
            user.setFirstName(firstName);
            user.setLastName(lastName);
        }

        u.createUser(user.getUsername(),
            user.getPasswordHash(),
            user.getFirstName(),
            user.getLastName(),
            user.getEmail(),
            user.getDateOfCreation(),
            user.getPrivlidges());
    }
}
