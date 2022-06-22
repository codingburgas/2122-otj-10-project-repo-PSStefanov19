#pragma once

#include <fstream>

#include "../pm.types/Team.h"
#include "../pm.tools/csv.h"

namespace pm::dal 
{
    class TeamManager 
    {
    public:
        static TeamManager& getInstance();

        void createTeam(const std::string teamName, const int* userIds);
        void createDB();

        void syncId();
        void setId(const int newId);
    private:
        TeamManager() {};
        TeamManager(const TeamManager&) {};

        int lastId = 0;
        std::fstream db;
    };
}