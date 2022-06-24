#pragma once

#include <string>
#include <vector>

namespace pm::types 
{
    class Project
    {
    public:

    private:
        int projectId;
        std::string name;
        std::string description;
        int ownerId;
        std::vector<int> taskIds;
    };
}
