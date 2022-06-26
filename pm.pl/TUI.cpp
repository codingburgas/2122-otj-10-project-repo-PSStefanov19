#include "TUI.h"

void updateViews() 
{
    update_panels();
    doupdate();
}

void clearWindows(pm::pl::VIEW* views)
{
        for (size_t i = 0; i < 3; i++)
        {
            wclear(views[i].win);
            box(views[i].win, 0, 0);
        }
        mvwprintw(views[0].win, 0, 1, " (U)sers Managment ");
        mvwprintw(views[0].win, 0, 21, " (T)eams Managment ");

        mvwprintw(views[1].win, 0, 1, " Actions ");

        mvwprintw(views[2].win, 0, 1, " Entries ");
}

void pm::pl::configCurses()
{
    raw();
    noecho();
    curs_set(0);
}

pm::pl::VIEW* pm::pl::initTUI()
{
    int screenWidth;
    int screenHeight;

    getmaxyx(stdscr, screenHeight, screenWidth);

    pm::pl::VIEW* views = new VIEW[4];

    views[0].win = newwin(0, 0, 0, 0);
    views[1].win = newwin(screenHeight-2, 20, 1, 1);
    views[2].win = newwin(screenHeight - 2, screenWidth - 22, 1, 21);
    views[3].win = newwin(10, screenWidth / 2, screenHeight / 2 - 10, screenWidth / 4);

    for (size_t i = 0; i < 4; i++) 
    {
        views[i].pan = new_panel(views[i].win);
    }

    hide_panel(views[3].pan);

    return views;
}

void pm::pl::TUI(pm::pl::VIEW* views)
{
    clearWindows(views);
    updateViews();
    getch();
}


