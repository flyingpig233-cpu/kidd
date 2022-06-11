#include "event_poll.h"

Event EventPoll::get_event()
{
    if (events.empty())
        return Event(EventType::None);
    auto e = events.front();
    events.pop();
    return e;
}

void EventPoll::pull_event()
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
    default:
        events.push(Event(EventType::KeyDown, ch));
    }
}
