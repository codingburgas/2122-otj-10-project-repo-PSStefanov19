#include "TeamManager.h"

pm::dal::TeamManager& pm::dal::TeamManager::getInstance()
{
    static pm::dal::TeamManager t;
    return t;
}

void pm::dal::TeamManager::createTeam(const std::string teamName, const int* userIds)
{
	db.open("../data/teams.csv", std::ios::out | std::ios::app);
	
	if (!db.is_open()) 
	{
		return;
	}

	std::string teamMemberIds = "";
	for (int i = 0; i < sizeof(userIds) / sizeof(userIds[0]) + 1; i++) 
	{
		teamMemberIds += std::to_string(userIds[i]) + ";";
	}


	db << lastId << ", " << teamName << ", " << teamMemberIds;
	db.flush();
	
	lastId++;
	db.close();
}

void pm::dal::TeamManager::createDB()
{
    db.open("../data/teams.csv", std::ios::out);

    if (!db.is_open()) 
    {
        return;
    }

    db << "Id,TeamName,UserIds\n";
    db.flush();
    db.close();
}

void pm::dal::TeamManager::syncId()
{
	std::string s;
	int i = -1;
	db.open("../data/teams.csv", std::ios::in);
	if (!db.is_open())
	{
		return;
	}

	while (getline(db, s))
	{
		i++;
	}
	setId(i);

	db.close();
}

void pm::dal::TeamManager::setId(const int newId)
{
	lastId = newId;
}
