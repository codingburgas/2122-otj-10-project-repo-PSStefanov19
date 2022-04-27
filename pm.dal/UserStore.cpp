#include "UserStore.h"

void pm::dal::UserStore::createUser(std::string username, std::string passwordHash, std::string firstName, std::string lastName, std::string email, time_t dateOfCreation)
{
    users.push_back({
        getMaxId() + 1,
            username,
            passwordHash,
            firstName,
            lastName,
            email,
            dateOfCreation
        });
}

//std::vector<pm::types::User> pm::dal::UserStore::getAll()
//{
//    return users;
//}
//
//void pm::dal::UserStore::remove(std::uint8_t id)
//{
//    users.erase(users.begin() + id);
//}
//
//void pm::dal::UserStore::update(pm::types::User user)
//{
//    users.at(user.id) = user;
//}
//
//pm::types::User pm::dal::UserStore::getById(std::uint8_t id)
//{
//    return users.at(id);
//}
//
//pm::types::User pm::dal::UserStore::getByUsername(std::string username)
//{
//    for (auto user : users)
//    {
//        if (user.username == username) 
//        {
//            return user;
//        }
//    }
//}
//
//pm::types::User pm::dal::UserStore::getByEmail(std::string email)
//{
//    for (auto user : users)
//    {
//        if (user.email == email)
//        {
//            return user;
//        }
//    }
//}

int pm::dal::UserStore::getMaxId()
{
    return pm::dal::UserStore::users.size();
}