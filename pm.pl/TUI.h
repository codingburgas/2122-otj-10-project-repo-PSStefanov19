#pragma once

#include "../pm.tools/curses.h"
#include "../pm.tools/panel.h"
#include "../pm.bll/retrieveData.h"
#include "../pm.bll/createData.h"
#include "../pm.bll/editData.h"
#include "../pm.bll/deleteData.h"
#include "../pm.bll/login.h"

#include <vector>
#include <string>
namespace pm 
{
    namespace pl 
    {
        /**
         * . Enumerator that holds all views
         */
        typedef enum managmentView 
        {
            User,
            Team,
            Project
        } managmentView;

        /**
         * . Structure that holds a window and correspoding panel
         */
        struct VIEW
        {
            WINDOW* win;
            PANEL* pan;
        };
        
        void configCurses();

        pm::types::User loginScreen(WINDOW* win);

        VIEW* initTUI();

        void TUI(VIEW* views, pm::types::User);

    }
}
