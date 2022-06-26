#pragma once

#include "../pm.tools/curses.h"
#include "../pm.tools/panel.h"
namespace pm 
{
    namespace pl 
    {
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
