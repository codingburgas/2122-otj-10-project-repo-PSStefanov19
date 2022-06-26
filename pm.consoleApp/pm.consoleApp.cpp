#include <iostream>
#include "../pm.pl/TUI.h"
int main()
{
    initscr();
    mvprintw(5, 5, "NCURSES WORKS!");

    refresh();
    getch();
    endwin();
}
