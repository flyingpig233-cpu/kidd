#include "kidd.h"
#include "utils/ncurses_utils.h"
#include "config/window_config.h"
#include "window.h"
#include "components/view.h"
#include "event/event_poll.h"
#include "utils/logger.h"
#include <spdlog/spdlog.h>
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
    auto gap = std::make_shared<GapBuffer>();
    w->add_view(std::make_shared<View>(w, WindowConfig { 0 }, gap));
    while (1)
    {
        wint_t ch;
        get_wch(&ch);
        gap->PutChar(ch);
        w->update();
    }

    return 0;
}

Kidd::~Kidd()
{
    endwin();
}