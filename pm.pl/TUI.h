#pragma once

#include "../pm.tools/curses.h"
#include "../pm.tools/panel.h"
#include "../pm.bll/retrieveData.h"
#include "../pm.bll/createData.h"

#include <vector>
#include <string>
namespace pm 
{
    namespace pl 
    {
        typedef enum managmentView 
        {
            User,
            Team,
            Project
        } managmentView;

        struct VIEW
        {
            WINDOW* win;
            PANEL* pan;
        };
        
        void configCurses();

        VIEW* initTUI();

        void TUI(VIEW* views);
    }
}
