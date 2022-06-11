#include "kidd.h"
#include "utils/ncurses_utils.h"

Kidd::Kidd(ArgConfig &config)
    : _config(std::move(config))
{
    curses_init();
}

int Kidd::run()
{
    return 0;
}