#include "deleteData.h"

int verifyUserId(int id)
{
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();

    if (id > 0 && id < u.getLastId() + 1) 
    {
        u.deleteUserById(id);
        return 0;
    }

    return 1;
}

