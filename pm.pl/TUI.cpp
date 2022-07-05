#include "TUI.h"

/**
 * . Function that updates all Views
 * 
 */
void updateViews()
{
    update_panels();
    doupdate();
}

/**
 * . Function that sets up user prompt and gets information for user creation
 * 
 * \param win Popup window with all information fields
 */
void showCreateUserPrompt(WINDOW* win)
{
    // Print all fields on screen
    mvwprintw(win, 0, 1, " Create User ");
    mvwprintw(win, 1, 1, "Username: ");
    mvwprintw(win, 2, 1, "Password: ");
    mvwprintw(win, 3, 1, "First name: ");
    mvwprintw(win, 4, 1, "Last name: ");
    mvwprintw(win, 5, 1, "Email: ");
    mvwprintw(win, 6, 1, "Is admin: ");

    updateViews();

    // Information fields
    char username[30];
    char password[30];
    char firstName[30];
    char lastName[30];
    char email[30];
    int isAdmin;

    // Make user written characters and cursor visible
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

    pm::bll::createUser(username, password, firstName, lastName, email, isAdmin);

    // Clear popup window after use
    wclear(win);
}

/**
 * . Function that sets up user prompt and gets information for user editing
 * 
 * \param win Popup window with all information fields
 */
void showEditUserPanel(WINDOW* win) 
{
    // Print all fields on screen
    mvwprintw(win, 0, 1, " Edit ");
    mvwprintw(win, 1, 1, "User Id:");
    mvwprintw(win, 2, 1, "New Username:");
    mvwprintw(win, 3, 1, "New Password:");
    mvwprintw(win, 4, 1, "New First name:");
    mvwprintw(win, 5, 1, "New Last name:");

    updateViews();
    
    // Information fields
    int id;
    char username[20];
    char password[20];
    char firstName[20];
    char lastName[20];

    // Make user written character and cursor visible
    echo();
    curs_set(1);
    
    mvwscanw(win, 1, 10, "%i", &id);
    mvwscanw(win, 2, 15, "%s", &username);

    // Turn off echoing of characters and cursor for password
    noecho();
    curs_set(0);
    mvwscanw(win, 3, 15, "%s", &password);
    
    // Turn it on back again
    echo();
    curs_set(1);

    mvwscanw(win, 4, 17, "%s", &firstName);
    mvwscanw(win, 5, 16, "%s", &lastName);
    
    // Turn off echoing
    noecho();
    curs_set(0);
    
    // Edit user
    pm::bll::editUser(id, username, password, firstName, lastName);

    // Clear window after use
    wclear(win);
}

/**
 * . Function that sets up user prompt and gets information for user deletion
 * 
 * \param win Popup window with all information fields
 */
void showDeleteUserPanel(WINDOW* win)
{
    // Print all fields on screen
    mvwprintw(win, 0, 1, " Delete user ");
    mvwprintw(win, 1, 1, "Id:");

    updateViews();
    
    // Information fields
    int id;

    // Turn on echoing of characters and cursor
    echo();
    curs_set(1);

    mvwscanw(win, 1, 5, "%i", &id);

    // Turn off echoing and cursor
    noecho();
    curs_set(0);

    if (pm::bll::verifyUserId(id))
    {
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 0, 1, " Error ");
        mvwprintw(win, 1, 1, "Incorrect Id");

        updateViews();
        getch();
    }

    // Clear window after user
    wclear(win);
}

/**
 * . Function that sets up delete prompt
 * 
 * \param v Managment view
 * \param win Window to be displayed to
 */
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


/**
 * . Function that sets up create prompt
 * 
 * \param v Managment view
 * \param win Window to be displayed to
 */
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

/**
 * . Function that sets up edit prompt
 * 
 * \param v Managment view
 * \param win Window to be displayed to
 */
void  setupEditPanel(const pm::pl::managmentView& v, WINDOW* win) 
{
    box(win, 0, 0);
    switch (v) 
    {
    case pm::pl::managmentView::User:
        showEditUserPanel(win);
    case pm::pl::managmentView::Team:
        break;
    case pm::pl::managmentView::Project:
        break;
    }
}

/**
 * . Function that handles input
 * 
 * \param v Managment view
 * \param pan Popup panel
 * \param sessionUser Logged in user
 */
void handleInput(pm::pl::managmentView& v, PANEL* pan, pm::types::User& sessionUser)
{
    switch (getch())
    {
    // Switch to user managment view
    case 'u':
    case 'U':
        v = pm::pl::managmentView::User;
        break;
    // Switch to Team managment view
    case 't':
    case 'T':
        v = pm::pl::managmentView::Team;
        break;
    // Switch to Project managment view
    case 'p':
    case 'P':
        v = pm::pl::managmentView::Project;
        break;
    // Open create prompt
    case 'c':
    case 'C':
        if (sessionUser.getPrivlidges()) 
        {
            show_panel(pan);
            setupCreatePanel(v, panel_window(pan));
            hide_panel(pan);
        }
        break;
    // Open edit prompt
    case 'e':
    case 'E':
        if (sessionUser.getPrivlidges())
        {
            show_panel(pan);
            setupEditPanel(v, panel_window(pan));
            hide_panel(pan);
        }
        break;
    // Open delete prompt
    case 'd':
    case 'D':
        if (sessionUser.getPrivlidges())
        {
            show_panel(pan);
            setupDeletePrompt(v, panel_window(pan));
            hide_panel(pan);
        }
        break;
    // Logout
    case 'l':
    case 'L':
        sessionUser = pm::pl::loginScreen(panel_window(pan));
        break;
    // Quit application
    case 'q':
    case 'Q':
        exit(0);
        break;
    }
}

/**
 * . Function that clears windows to desired state
 * 
 * \param v Managment view
 * \param views All views
 * \param sessionUser Logged in user
 */
void clearWindows(pm::pl::managmentView v, pm::pl::VIEW* views, pm::types::User sessionUser)
{
    // Clear all windows and put a box around them
    for (size_t i = 0; i < 3; i++)
    {
        wclear(views[i].win);
        box(views[i].win, 0, 0);
    }

    // Write headers for Managment views
    mvwprintw(views[0].win, 0, 1, " (U)sers Managment ");
    mvwprintw(views[0].win, 0, 21, " (T)eams Managment ");
    mvwprintw(views[0].win, 0, 41, " (P)roject Managment ");
    
    // Add logged in infromation
    mvwprintw(views[0].win, 0, getmaxx(views[0].win) - 44, "Logged as: %s ", sessionUser.getUsername().c_str());

    // Highlight selected view
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

    // Write all actions possible
    mvwprintw(views[1].win, 0, 1, " Actions ");
    mvwprintw(views[1].win, 1, 2, "(C)reate");
    mvwprintw(views[1].win, 2, 2, "(E)dit");
    mvwprintw(views[1].win, 3, 2, "(D)elete");
    mvwprintw(views[1].win, getmaxy(views[1].win) - 3, 2, "(L)og out");
    mvwprintw(views[1].win, getmaxy(views[1].win) - 2, 2, "(Q)uit");
}

/**
 * . Function to cofig PDcurses
 * 
 */
void pm::pl::configCurses()
{
    raw();
    noecho();
    curs_set(0);
}

/**
 * . Function that displays login screen
 * 
 * \param win Window to be displayed to
 * \return Logged in user
 */
pm::types::User pm::pl::loginScreen(WINDOW* win)
{
    box(win, 0, 0);
    mvwprintw(win, 0, 1, " Login ");

    mvwprintw(win, 1, 1, "Username: ");
    mvwprintw(win, 2, 1, "Password: ");

    char username[30];
    char password[30];

    echo();
    curs_set(1);

    mvwscanw(win, 1, 11, "%s", &username);

    noecho();
    curs_set(0);

    mvwscanw(win, 2, 11, "%s", &password);

    wclear(win);
    return pm::bll::login(username, password);
}

/**
 * . Initialization of TUI
 * 
 * \return Set up views
 */
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

/**
 * . Function to set up the user view
 * 
 * \param displayWin Window to be displayed to
 */
void setupUserView(WINDOW* displayWin)
{
    mvwprintw(displayWin, 0, 1, " Id ");
    mvwprintw(displayWin, 0, 12, " Username ");
    mvwprintw(displayWin, 0, 29, " First Name ");
    mvwprintw(displayWin, 0, 48, " Last Name ");
    mvwprintw(displayWin, 0, 66, " Email ");
}

/**
 * . Function to display all users
 * 
 * \param displayWin Window to be displayed to
 */
void displayUsers(WINDOW* displayWin)
{
    // Get all users
    std::vector<std::string> users;
    users = pm::bll::getAllUsersFormatted();

    // Print them to the screen
    for (size_t i = 0; i < users.size(); i++)
    {
        mvwprintw(displayWin, i + 1, 2, users[i].c_str());
    }
}

/**
 * . Function that display information on the Managment View panel
 * 
 * \param v Managment View enum
 * \param displayWin Window to be displayed to
 * \param sessionUser Logged in user
 */
void displayView(pm::pl::managmentView v, WINDOW* displayWin, pm::types::User sessionUser)
{
    switch (v)
    {
    case pm::pl::User:
        if (sessionUser.getPrivlidges())
        {
            setupUserView(displayWin);
            displayUsers(displayWin);
        }
        else 
        {
            mvwprintw(displayWin, 1, 1, "User is not admin.");
            mvwprintw(displayWin, 2, 1, "You will not be able to modify the users(e.g. Create, Edit, Delete).");
        }
        break;
    case pm::pl::Team:
        mvwprintw(displayWin, 1, 1, "Team information");
        break;
    case pm::pl::Project:
        mvwprintw(displayWin, 1, 1, "Project information");
        break;
    }
}

/**
 * . Main TUI function
 * 
 * \param views All views that can be used
 * \param sessionUser Logged in user
 */
void pm::pl::TUI(pm::pl::VIEW* views, pm::types::User sessionUser)
{
    pm::pl::managmentView mView = User;

    while (true)
    {
        clearWindows(mView, views, sessionUser);
        displayView(mView, views[2].win, sessionUser);
        updateViews();
        handleInput(mView, views[3].pan, sessionUser);
    }
}


