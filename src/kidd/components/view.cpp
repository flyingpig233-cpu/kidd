#include "view.h"
#include <memory>
#include "utils/gapbuffer/gapbuffer.h"

View::View(std::shared_ptr<Window> parent, WindowConfig config, gap_buffer_t buffer)
    : _parent(parent), _buffers(), _window_config(config)
{

    // init buffer
    if (!buffer)
    {
        //_buffers.push_back(std::shared_ptr<GapBuffer>(new GapBuffer()));
        auto g = std::shared_ptr<GapBuffer>(new GapBuffer());
        _buffers.push_back(g);
    }
    else
    {
        _buffers.push_back(buffer);
    }
    _active_buffer = _buffers.size() - 1;

    // init window
    _window = std::shared_ptr<WINDOW>(newwin(_window_config.height, _window_config.width,
                                             _window_config.pos.y, _window_config.pos.x),
                                      [](WINDOW *w)
                                      {
                                          delwin(w);
                                      });
}

std::shared_ptr<GapBuffer> View::get_active_buffer()
{
    return *std::next(_buffers.begin(), _active_buffer);
}

void View::update()
{
    werase(_window.get());
    waddwstr(_window.get(), get_active_buffer()->GetBuffer());
    // waddwstr(_window.get(), _("HELLO!!!"));
    wrefresh(_window.get());
}