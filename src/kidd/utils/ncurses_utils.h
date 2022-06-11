#ifndef _KIDD_NCURSES_UTILS_H__
#define _KIDD_NCURSES_UTILS_H__

#include <locale>

void curses_init()
{
#ifdef UNICODE
    setlocale(LC_ALL, "");
#endif // UNICODE

    // init ncurses screen, making main window too
    initscr();
    // change how terminal input works
    // initialise colours
    start_color();
    // don't echo typed characters back
    noecho();
    // characters read 1 by 1
    cbreak();
    // get all keys
    keypad(stdscr, true);
}

#endif // _KIDD_NCURSES_UTILS_H__