#ifndef WIDGET_H
#define WIDGET_H

#include <FEHLCD.h>

#include "GUI/Utility/Time.h"
#include "GUI/Utility/Input.h"
#include "GUI/Utility/Color.h"

#include "GUI/Widgets/Base/WidgetProperties.h"

bool isEventInsideWidget(const Widget &widget, const InputEvent &event);

class Widget
{
public:
    Widget(WidgetProperties prop = WidgetProperties{}) : properties(prop) {}
    virtual ~Widget() {}

    // Called in each frame to render the widget
    virtual void draw() const;

    // Called in each frame to update the widget
    virtual void update(DeltaTime dt);

    // Called to handle input events
    virtual void handleInput(InputEvent event);

    // Called to layout the widget and its contents
    virtual void layout() {}

    WidgetProperties properties;

    // Used as a flag to indicate the widget should be updated
    bool hasUpdate = false;
};

#endif // WIDGET_H