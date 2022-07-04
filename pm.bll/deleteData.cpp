#include "deleteData.h"

/**
 * . Function that verifies and deletes user by id
 * 
 * \param id Id of user to be deleted
 * \return Error code
 */
int pm::bll::verifyUserId(int id)
{
    pm::dal::UserManager& u = pm::dal::UserManager::getInstance();

    if (id > 0 && id < u.getLastId() + 1) 
    {
        u.deleteUserById(id);
        return 0;
    }

    return 1;
}

