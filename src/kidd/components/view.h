#ifndef _KIDD_VIEW_H__
#define _KIDD_VIEW_H__

#include <ncursesw/ncurses.h>
#include <memory>

class View {
private:
    std::shared_ptr<WINDOW> _window;
public:
    View();
    ~View();
};

#endif // _KIDD_VIEW_H__