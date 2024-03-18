#ifndef WIDGET_WITH_CHILDREN_H
#define WIDGET_WITH_CHILDREN_H

#include <typeinfo>
#include <vector>

#include "GUI/Widgets/Base/Widget.h"

class WidgetWithChildren : public Widget {
   public:
    WidgetWithChildren(std::vector<Widget *> children = {},
                       WidgetProperties prop = WidgetProperties{});
    ~WidgetWithChildren();

    void layout() override;

    void draw() const override;
    void update(DeltaTime dt) override;
    void handleInput(InputEvent event) override;

    // List of children widgets
    std::vector<Widget *> children;
};

#endif  // WIDGET_WITH_CHILDREN_H
