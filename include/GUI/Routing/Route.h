#ifndef ROUTE_H
#define ROUTE_H

#include "GUI/Widgets/Base/WidgetWithChild.h"

class Route : public WidgetWithChild {
   public:
    Route(Widget *child = nullptr,
          WidgetProperties prop = {.width = 320, .height = 240})
        : WidgetWithChild(child, prop) {}
};

#endif  // ROUTE_H
