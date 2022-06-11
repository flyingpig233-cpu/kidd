#include "view.h"

View::View(std::shared_ptr<Window> parent, WindowConfig config, gap_buffer_t buffer)
    : _parent(parent), _buffers(), _window_config(config)
{

    // init buffer
    if (!buffer)
    {
        _buffers.push_back(std::make_shared<GapBuffer>());
    }
    else
    {
        _buffers.push_back(buffer);
    }
    _active_buffer = _buffers.end();

    // init window
    _window = std::shared_ptr<WINDOW>(newwin(_window_config.height, _window_config.width,
                                             _window_config.pos.y, _window_config.pos.x),
                                      [](WINDOW *w)
                                      {
                                          delwin(w);
                                      });
}

void View::update()
{
    werase(_window.get());
    waddwstr(_window.get(), _("HELLO!!!"));
    wrefresh(_window.get());
}