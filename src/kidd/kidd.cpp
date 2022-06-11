#include "kidd.h"
#include "utils/ncurses_utils.h"
#include "config/window_config.h"
#include "window.h"
#include "components/view.h"
#include "event/event_poll.h"

#include <assert.h>
Kidd::Kidd(ArgConfig &config)
    : _config(std::move(config))
{
    curses_init();
    //mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    //scrollok(stdscr, true);
}

int Kidd::run()
{
    std::shared_ptr<Window> w = std::make_shared<Window>();
    w->add_view(std::make_shared<View>(w, WindowConfig { 0 }));
    while (true)
    {
        w->update();
        // EventPoll::pull_event();
        // printw("%ls\n", type_map.at(EventPoll::get_event().event).c_str());
    }

    return 0;
}

Kidd::~Kidd()
{
    endwin();
}