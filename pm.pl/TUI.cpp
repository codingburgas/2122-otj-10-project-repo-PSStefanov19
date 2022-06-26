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

void setupUserView(WINDOW* displayWin) 
{
    mvwprintw(displayWin, 0, 1, " Id ");
    mvwprintw(displayWin, 0, 12, " Username ");
    mvwprintw(displayWin, 0, 29, " First Name ");
    mvwprintw(displayWin, 0, 48, " Last Name ");
    mvwprintw(displayWin, 0, 66, " Email ");
}

void displayUsers(WINDOW* displayWin)
{
    std::vector<std::string> users;
    users = getAllUsersFormatted();

    for (size_t i = 0; i < users.size(); i++) 
    {
        mvwprintw(displayWin, i+1, 2, users[i].c_str());
    }
}

void displayView(pm::pl::managmentView v, WINDOW* displayWin)
{
    switch (v)
    {
    case pm::pl::User:
        setupUserView(displayWin);
        displayUsers(displayWin);
        break;
    case pm::pl::Team:
        break;
    case pm::pl::Project:
        break;
    default:
        break;
    }
}

void pm::pl::TUI(pm::pl::VIEW* views)
{
    managmentView m = User;

    while (true)
    {
        clearWindows(views);
        displayView(m, views[2].win);
        updateViews();
        getch();
    }
}


