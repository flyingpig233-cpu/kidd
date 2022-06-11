#include "kidd.h"
#include "utils/ncurses_utils.h"
#include "window.h"
#include "event/event_poll.h"

Kidd::Kidd(ArgConfig &config)
    : _config(std::move(config))
{
    curses_init();
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    scrollok(stdscr, true);
}

int Kidd::run()
{
    Window w;
    while (true)
    {
        EventPoll::pull_event();
        printw("%ls\n", type_map.at(EventPoll::get_event().event).c_str());
    }

    return 0;
}