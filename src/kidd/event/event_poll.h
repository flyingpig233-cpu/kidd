#ifndef _KIDD_EVENT_POLL_H__
#define _KIDD_EVENT_POLL_H__

#include <queue>
#include "event.h"

class EventPoll
{
public:
    static std::queue<Event> events;
    static Event get_event();
    static void pull_event();
};

#endif // _KIDD_EVENT_POLL_H__