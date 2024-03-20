#ifndef WIDGET_PROPERTIES_H
#define WIDGET_PROPERTIES_H

#include <functional>
#include <string>

#include "GUI/Widgets/Base/Widget.h"

class Widget;

struct WidgetProperties
{
    std::string textContent = "";

    int x = 0, y = 0;
    int width = 0, height = 0;

    Color backgroundColor = Color(BLACK); // Default black background
    Color foregroundColor = Color(WHITE); // Default white foreground

    int borderWidth = 0;              // No border by default
    Color borderColor = Color(WHITE); // Default white border color

    int padding = 6; // Default padding

    // Event callbacks
    std::function<void(Widget *, InputEvent)> onPress = [](Widget *self, InputEvent event) {};
    std::function<void(Widget *, InputEvent)> onRelease = [](Widget *self, InputEvent event) {};
    std::function<void(Widget *, InputEvent)> onEnter = [](Widget *self, InputEvent event) {};
    std::function<void(Widget *, InputEvent)> onLeave = [](Widget *self, InputEvent event) {};

    Widget *parent = nullptr; // Pointer to parent widget
};

#endif // WIDGET_PROPERTIES_H