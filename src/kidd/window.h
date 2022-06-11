#ifndef _KIDD_WINDOW_H__
#define _KIDD_WINDOW_H__

#include <list>
#include <memory>

class View;
class Window
{
private:
    std::list<std::shared_ptr<View>> _views;
    std::list<std::shared_ptr<View>>::iterator _active_view;
public:
    Window();
    void add_view(std::shared_ptr<View> view, bool active = false);
    void update();
    ~Window();

};

#endif // _KIDD_WINDOW_H__