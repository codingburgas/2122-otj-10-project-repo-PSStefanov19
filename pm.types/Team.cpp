#include "Team.h"

std::string pm::types::Team::getTeamName()
{
    return teamName;
}

std::vector<pm::types::User> pm::types::Team::getUsers()
{
    return users;
}
