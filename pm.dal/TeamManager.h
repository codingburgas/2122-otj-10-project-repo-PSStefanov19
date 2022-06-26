#pragma once

#include <fstream>

#include "../pm.types/Team.h"
#include "../pm.tools/csv.h"

namespace pm 
{
    namespace dal 
    {
        class TeamManager
        {
        public:
	        static TeamManager& getInstance() 
			{
				static pm::dal::TeamManager t;
				return t;
			}

			TeamManager (TeamManager const&) = delete;
			void operator=(TeamManager const&) = delete;


            void createTeam(const std::string teamName, const int* userIds);
            void createDB();

            void syncId();
            void setId(const int newId);
        private:
            TeamManager() {}

            int lastId = 0;
            std::fstream db;
        };
    }
}