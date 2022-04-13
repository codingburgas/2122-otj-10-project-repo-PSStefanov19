#include "UserStore.h"

std::vector<pm::types::User> users;

void pm::dal::UserStore::createUser(pm::types::User user)
{
    users.push_back(user);
}

std::vector<pm::types::User> pm::dal::UserStore::getAll()
{
    return users;
}

void pm::dal::UserStore::remove(uint8_t id)
{
    users.erase(users.begin() + id);
}

pm::types::User pm::dal::UserStore::getById(uint8_t id)
{
    return users.at(id);
}

pm::types::User pm::dal::UserStore::getByUsername(std::string username)
{
    for (auto user : users)
    {
        if (user.username == username) 
        {
            return user;
        }
    }
}
