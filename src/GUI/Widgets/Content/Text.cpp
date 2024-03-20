#include "GUI/Widgets/Content/Text.h"

Text::Text(std::string text, WidgetProperties prop) : Widget(prop) {
    properties.textContent = text;

    if (properties.width == 0)
        properties.width = CHAR_WIDTH * text.length() + properties.padding * 2;

    if (properties.height == 0)
        properties.height = CHAR_HEIGHT + properties.padding * 2;

    if (properties.padding == 0)
        properties.padding = 6;  // Default to 6 if not specified
}

void Text::draw() const {
    Widget::draw();

    int textWidth = CHAR_WIDTH * properties.textContent.length();
    int x = properties.x + (properties.width / 2) - (textWidth / 2);
    int y = properties.y + (properties.height / 2) - (CHAR_HEIGHT / 2);

    LCD.SetFontColor(properties.foregroundColor.toInt());
    LCD.WriteAt(properties.textContent.c_str(), x, y);
}
