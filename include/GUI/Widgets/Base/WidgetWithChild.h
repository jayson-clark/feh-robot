#ifndef WIDGET_WITH_CHILD_H
#define WIDGET_WITH_CHILD_H

#include "GUI/Widgets/Base/Widget.h"

class WidgetWithChild : public Widget {
   public:
    WidgetWithChild(Widget *child = nullptr,
                    WidgetProperties prop = WidgetProperties{});
    ~WidgetWithChild();

    void layout() override;
    void draw() const override;
    void update(DeltaTime dt) override;
    void handleInput(InputEvent event) override;

    Widget *child;
};

#endif  // WIDGET_WITH_CHILD_H
