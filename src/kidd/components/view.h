#ifndef _KIDD_VIEW_H__
#define _KIDD_VIEW_H__

#include <ncursesw/ncurses.h>
#include <memory>
#include <list>
#include "config/window_config.h"
#include "utils/gapbuffer/gapbuffer.h"

class Window;
class View
{
public:
    using gap_buffer_t = std::shared_ptr<GapBuffer>;
    using gap_buffer_list = std::list<gap_buffer_t>;
protected:
    std::shared_ptr<WINDOW> _window;
    std::weak_ptr<Window> _parent;
    gap_buffer_list _buffers;
    gap_buffer_list::size_type _active_buffer;
    WindowConfig _window_config;
    
public:
    View(std::shared_ptr<Window> parent, WindowConfig config, gap_buffer_t buffer = nullptr);
    std::shared_ptr<GapBuffer> get_active_buffer();
    void update();
    ~View() {};
};

#endif // _KIDD_VIEW_H__