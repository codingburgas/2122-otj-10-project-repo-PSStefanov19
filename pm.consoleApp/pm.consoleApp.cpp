#include "../pm.dal/UserManager.h"
#include "../pm.dal/TeamManager.h"
#include <iostream>

int main()
{
	pm::dal::UserManager& uMan = pm::dal::UserManager::getInstance();
	pm::dal::TeamManager& tMan = pm::dal::TeamManager::getInstance();
	std::filesystem::create_directories("../data");
	if (!std::filesystem::exists("../data/teams.csv"))
	{
		tMan.createDB();
	}
	int ids[] = { 1, 4, 5 };
	tMan.createTeam("Team1", ids);
}
