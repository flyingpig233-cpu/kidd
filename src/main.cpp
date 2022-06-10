#include <ncursesw/ncurses.h>

int main()
{
    initscr();
    wint_t y;
    get_wch(&y);
    endwin();    
}
