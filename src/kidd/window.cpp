#include "window.h"
#include "components/view.h"

Window::Window()
    : _views(), _active_view(nullptr)
{

}

void Window::update()
{
    for (auto &&v : _views)
    {
        v->update();
    }
}

void Window::add_view(std::shared_ptr<View> view, bool active)
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