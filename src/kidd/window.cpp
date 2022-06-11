#include "window.h"

Window::Window()
    : _views(), _active_view(nullptr)
{

}

void Window::add_view(std::shared_ptr<View> view, bool active = false)
{
    _views.push_back(view);
    if (active || _views.size() <= 1)
    {
        _active_view = _views.end();
    }
}

Window::~Window()
{

}