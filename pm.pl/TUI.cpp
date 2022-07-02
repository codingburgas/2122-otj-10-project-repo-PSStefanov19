#include "TUI.h"

void updateViews()
{
    update_panels();
    doupdate();
}

void showCreateUserPrompt(WINDOW* win)
{
    mvwprintw(win, 0, 1, " Create User ");
    mvwprintw(win, 1, 1, "Username: ");
    mvwprintw(win, 2, 1, "Password: ");
    mvwprintw(win, 3, 1, "First name: ");
    mvwprintw(win, 4, 1, "Last name: ");
    mvwprintw(win, 5, 1, "Email: ");
    mvwprintw(win, 6, 1, "Is admin: ");

    updateViews();

    char username[30];
    char password[30];
    char firstName[30];
    char lastName[30];
    char email[30];
    int isAdmin;

    curs_set(1);
    echo();

    // Username
    mvwscanw(win, 1, 12, "%s", &username);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Create User ");

    // Turn off echoing for password
    noecho();
    curs_set(0);

    mvwscanw(win, 2, 12, "%s", &password);

    mvwprintw(win, 0, 1, " Create User ");
    // Turn on echoing for other parts of input
    echo();
    curs_set(1);

    // First name
    mvwscanw(win, 3, 14, "%s", &firstName);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Create User ");

    // Last name
    mvwscanw(win, 4, 13, "%s", &lastName);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Create User ");

    // Email
    mvwscanw(win, 5, 9, "%s", &email);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Create User ");

    // Admin privledges
    mvwscanw(win, 6, 12, "%d", &isAdmin);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Create User ");

    createUser(username, password, firstName, lastName, email, isAdmin);

    wclear(win);
}

void showDeleteUserPanel(WINDOW* win) 
{
    mvwprintw(win, 0, 1, " Delete user ");
    
    mvwprintw(win, 1, 1, "Id:");

    updateViews();
    
    int id;
    
    echo();
    curs_set(1);

    mvwscanw(win, 1, 5, "%i", &id);

    noecho();
    curs_set(0);

    if (verifyUserId(id)) 
    {
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 0, 1, " Error ");
        mvwprintw(win, 1, 1, "Incorrect Id");

        updateViews();
        getch();
    }

    wclear(win);
}

void setupDeletePrompt(const pm::pl::managmentView& v, WINDOW* win) 
{
    box(win, 0, 0);
    switch (v)
    {
    case pm::pl::managmentView::User:
        showDeleteUserPanel(win);
        break;
    case pm::pl::managmentView::Team:
        break;
    case pm::pl::managmentView::Project:
        break;
    }
}

void setupCreatePanel(const pm::pl::managmentView& v, WINDOW* win)
{
    box(win, 0, 0);
    switch (v)
    {
    case pm::pl::managmentView::User:
        showCreateUserPrompt(win);
        break;
    case pm::pl::managmentView::Team:
        break;
    case pm::pl::managmentView::Project:
        break;
    }
}

void handleInput(pm::pl::managmentView& v, PANEL* pan)
{
    switch (getch())
    {
    case 'u':
    case 'U':
        v = pm::pl::managmentView::User;
        break;
    case 't':
    case 'T':
        v = pm::pl::managmentView::Team;
        break;
    case 'p':
    case 'P':
        v = pm::pl::managmentView::Project;
        break;
    case 'c':
    case 'C':
        show_panel(pan);
        setupCreatePanel(v, panel_window(pan));
        hide_panel(pan);
        break;
    case 'd':
    case 'D':
        show_panel(pan);
        setupDeletePrompt(v, panel_window(pan));
        hide_panel(pan);
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    }
}

void clearWindows(pm::pl::managmentView v, pm::pl::VIEW* views)
{
    for (size_t i = 0; i < 3; i++)
    {
        wclear(views[i].win);
        box(views[i].win, 0, 0);
    }
    mvwprintw(views[0].win, 0, 1, " (U)sers Managment ");
    mvwprintw(views[0].win, 0, 21, " (T)eams Managment ");
    mvwprintw(views[0].win, 0, 41, " (P)roject Managment ");

    switch (v)
    {
    case pm::pl::User:
        mvwchgat(views[0].win, 0, 2, 17, A_REVERSE, 1, NULL);
        break;
    case pm::pl::Team:
        mvwchgat(views[0].win, 0, 22, 17, A_REVERSE, 1, NULL);
        break;
    case pm::pl::Project:
        mvwchgat(views[0].win, 0, 42, 19, A_REVERSE, 1, NULL);
        break;
    }

    mvwprintw(views[1].win, 0, 1, " Actions ");
    mvwprintw(views[1].win, 1, 2, "(C)reate");
    mvwprintw(views[1].win, 2, 2, "(E)dit");
    mvwprintw(views[1].win, 3, 2, "(D)elete");

    mvwprintw(views[1].win, getmaxy(views[1].win) - 3, 2, "(L)og out");
    mvwprintw(views[1].win, getmaxy(views[1].win) - 2, 2, "(Q)uit");
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
    views[1].win = newwin(screenHeight - 2, 20, 1, 1);
    views[2].win = newwin(screenHeight - 2, screenWidth - 22, 1, 21);
    views[3].win = newwin(10, screenWidth / 2, screenHeight / 2 - 10, screenWidth / 4);

    for (size_t i = 0; i < 4; i++)
    {
        views[i].pan = new_panel(views[i].win);
    }

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
        mvwprintw(displayWin, i + 1, 2, users[i].c_str());
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
    }
}

void pm::pl::TUI(pm::pl::VIEW* views)
{
    pm::pl::managmentView mView = User;

    while (true)
    {
        clearWindows(mView, views);
        displayView(mView, views[2].win);
        updateViews();
        handleInput(mView, views[3].pan);
    }
}


