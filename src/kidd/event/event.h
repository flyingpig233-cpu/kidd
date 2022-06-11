#ifndef _KIDD_EVENT_H__
#define _KIDD_EVENT_H__

#include <ncursesw/ncurses.h>

enum class EventType
{
    KeyDown,
    MouseMove,
    Resize,
    None
};

struct Event
{
    EventType event;
    wint_t data;
    Event(EventType type) : event(type) {}
    Event(EventType type, wint_t data) : event(type), data(data) {}
};

#endif // _KIDD_EVENT_H__