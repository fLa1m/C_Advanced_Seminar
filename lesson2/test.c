#include <curses.h>

int main(int argc, char const *argv[])
{
    initscr();
    printw("Hello World!!!");
    refresh();
    getch();
    endwin();
    return 0;
}
