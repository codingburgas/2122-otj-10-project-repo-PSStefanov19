#include <iostream>
#include <filesystem>

#include "../pm.pl/TUI.h"
#include "../pm.dal/UserManager.h"
#include "../pm.dal/TeamManager.h"

int main()
{
    //Initialize databases
    pm::dal::UserManager& uman = pm::dal::UserManager::getInstance();
    pm::dal::TeamManager& tman = pm::dal::TeamManager::getInstance();
    
    pm::pl::VIEW* views = new pm::pl::VIEW[4];
    if(!std::filesystem::exists("../data"))
    {
        std::filesystem::create_directory("../data/");
    }
    uman.createDB();
    tman.createDB();
   
    initscr();
    
    pm::pl::configCurses();
    views = pm::pl::initTUI();

    pm::types::User sessionUser = pm::pl::loginScreen(views[3].win);
    while (sessionUser.getId() == 0) 
    {
        sessionUser = pm::pl::loginScreen(views[3].win);
    }
    hide_panel(views[3].pan);
    pm::pl::TUI(views, sessionUser);

    endwin();
}
