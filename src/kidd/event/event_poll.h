#ifndef _KIDD_EVENT_POLL_H__
#define _KIDD_EVENT_POLL_H__

#include <queue>
#include "event.h"

class EventPoll
{
public:
    static inline std::queue<Event> events;
    static Event get_event()
    {
        if (events.empty())
            return Event(EventType::None, 0);
        auto e = events.front();
        events.pop();
        return e;
    }
    static void pull_event()
    {

        wint_t ch;
        get_wch(&ch);
        switch (ch)
        {
        case KEY_MOUSE:
            events.push(Event(EventType::MouseMove, ch));
            break;
        case KEY_RESIZE:
            events.push(Event(EventType::Resize, ch));
            break;
        default:
            events.push(Event(EventType::KeyDown, ch));
        }
    }
};

#endif // _KIDD_EVENT_POLL_H__