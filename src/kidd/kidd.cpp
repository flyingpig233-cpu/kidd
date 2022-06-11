#include "kidd.h"
#include "utils/ncurses_utils.h"
#include "window.h"
#include "event/event_poll.h"

Kidd::Kidd(ArgConfig &config)
    : _config(std::move(config))
{
    curses_init();
}

int Kidd::run()
{
    Window w;
    while (true)
    {
        EventPoll::pull_event();
        printw("Your Input: %d\n", EventPoll::get_event().data);
    }

    return 0;
}